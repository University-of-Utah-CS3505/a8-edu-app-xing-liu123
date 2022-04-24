#include "view.h"
#include "model.h"
#include "ui_view.h"
#include <iostream>
#include <QPropertyAnimation>
#include <QMessageBox>

View::View(Model &model,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{

    ui->setupUi(this);
    this->setMouseTracking(true);



    /*
     * Set quiz buttons to be unvisibles
    **/
    ui->nextQuestionButton->setVisible(false);
    ui->nextFishTestButton->setVisible(false);
    ui->catchButton->setVisible(false);
    ui->goToQuizButton->setVisible(false);

    /*
     * Button style section
    **/
    ui->freshWaterButton->setStyleSheet("border-image: url(:/buttons/Button_FreshWater.png)"); // Test
    ui->freshWaterButton->resize(180,60); // Find the original PNG size and divide it by 2.5. Set the values as QPushButton size.
    ui->saltWaterButton->setStyleSheet("border-image: url(:/buttons/Button_SeaWater.png)");
    ui->smoothWaterButton->setStyleSheet("border-image: url(:/buttons/Button_SmoothWater.png)");

    /*
     * Background style section
    **/
    ui->mainMenuBackgroundImageLabel->setStyleSheet("border-image: url(:/Background_MainMenu.png)");

    /*
     * Audio section
    **/

    // Uncomment this when working on audios
    // Background music
    bgmOutput->setVolume(audioVolumn);
    bgmPlayer->setAudioOutput(bgmOutput);
    bgmPlayer->setSource(QUrl("qrc:/Waves.mp3"));

    // Sound effects
    SE_GameOver.setSource(QUrl("qrc:/GameOver(Test).wav"));

    /*
     * Audio connections
    **/

    // Connect loading media and playing media, cause mediaplayer to play the audio after finished loading
    connect(bgmPlayer, &QMediaPlayer::mediaStatusChanged, this, &View::playBGM);
    // Connect Music: on/off to an event
    connect(ui->mainMenuMucisButton, &QPushButton::pressed, this, &View::pressMusicButton);
    // Connect event's emission to change the text of Music: on/of
    connect(this, &View::updateMainMenuMusicButton, ui->mainMenuMucisButton, &QPushButton::setText);
    // [TEST] Connect TestSound Button to an event
    connect(ui->TestSoundButton, &QPushButton::clicked, this, &View::pressTestSoundButton);

    // Set images for moving fishes
    ui->fish1Label->setStyleSheet("border-image: url(://fishShadows/fishShadow.png)");
    ui->fish2Label->setStyleSheet("border-image: url(://fishShadows/fishShadow.png)");
    ui->fish3Label->setStyleSheet("border-image: url(://fishShadows/fishShadow.png)");

    // set image for the spear
    QPixmap spearPix;
    spearPix.load(":/spear1.png");
    ui->spearLabel->setPixmap(spearPix.scaled(ui->spearLabel->width(), ui->spearLabel->height()));

    //Set up the initial Widget
    ui->stackedWidget->setCurrentIndex(startPage);
    time = new QTimer(this);

    //Congrats label
    ui->congratsLabel->setVisible(false);
    //congrats close button
    ui->closeCongratsButton->setEnabled(false);
    ui->closeCongratsButton->setVisible(false);

    //Connections to set up first
    connect(this,
            &View::updateWorld,
            &model,
            &Model::setUpWorld);

    //oOnnection to display fish
    connect(&model,
            &Model::setUpFish1,
            this,
            &View::displayFish1);
    connect(&model,
            &Model::setUpFish2,
            this,
            &View::displayFish2);
    connect(&model,
            &Model::setUpFish3,
            this,
            &View::displayFish3);

    // reset world
    connect(this,
            &View::resetWorld,
            &model,
            &Model::resetWorld);

    // connects for spear
    connect(this,
            &View::shootSpear,
            &model,
            &Model::shotSpear);
    connect(&model,
            &Model::setUpSpear,
            this,
            &View::displaySpear);
    connect(this,
            &View::sendPosition,
            &model,
            &Model::setSpearLabel);
    connect(&model,
            &Model::sendSpearLabel,
            this,
            &View::updateSpearLabel);
    connect(&model,
            &Model::resetSpear,
            this,
            &View::resetSpearLabel);

    //Ctach, Quiz and info window
    connect(ui->catchButton,
            &QPushButton::clicked,
            &model,
            &Model::getFish);

    connect(&model,
            &Model::updateInformation,
            this,
            &View::setUpInfo);
    connect(&model,
            &Model::updateQuiz,
            this,
            &View::setUpQuiz);
    connect(&model,
            &Model::sendCountDown,
            this,
            &View::displayCountDown);

    //Checking Answer Buttons
    connect(ui->answ1Button,
            &QPushButton::clicked,
            this,
            &View::on_answerButton1_clicked);
    connect(ui->answ1Button_2,
            &QPushButton::clicked,
            this,
            &View::on_answerButton2_clicked);
    connect(ui->answ1Button_3,
            &QPushButton::clicked,
            this,
            &View::on_answerButton3_clicked);
    //button number 4 has an autoconnected slot

    connect(this,
            &View::checkUserAnswer,
            &model,
            &Model::checkAnswer);
    connect(&model,
            &Model::answerResult,
            this,
            &View::showResult);

    //Journal
    connect(this,
            &View::getJournal,
            &model,
            &Model::getJouralInfo);
    connect(&model,
            &Model::updateJournal,
            this,
            &View::setUpJournal);

    //Testing Code for quiz and info window
    connect(ui->nextFishTestButton,
            &QPushButton::clicked,
            &model,
            &Model::getTestInfoFish);
    connect(ui->nextQuestionButton,
            &QPushButton::clicked,
            &model,
            &Model::getTestQuizInfo);
    connect(ui->goToQuizButton,
            &QPushButton::clicked,
            &model,
            &Model::getTestQuizInfo);

    //update the levels and progress bar
    connect(&model,
            &Model::updateNextLevelProgress,
            this,
            &View::updateNextLevelProgress);

    // update the spear and progress bar
    connect(&model,
            &Model::updateNextSpearProgress,
            this,
            &View::updateNextSpearProgress);
}


View::~View()
{
    delete ui;
    delete time;

    // Uncomment this when working on audios
    delete bgmPlayer;
    delete bgmOutput;
}



//Get the Program to start
void View::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(fishingPage);
}


//Display the fish labels into their new position
void View::displayFish1(int x1, int y1, int x2, int y2){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->fish1Label,"pos");
    animation->setDuration(25);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}

void View::displayFish2(int x1, int y1, int x2, int y2){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->fish2Label,"pos");
    animation->setDuration(25);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}

void View::displayFish3(int x1, int y1, int x2, int y2){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->fish3Label,"pos");
    animation->setDuration(25);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}

// Display the spear moving from initial position to final position
void View::displaySpear(int x1, int y1, int x2, int y2){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->spearLabel,"pos");
    animation->setDuration(25);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}

// send the position of cursor to rotate the spear
void View::mouseMoveEvent(QMouseEvent *event){

    if(ui->stackedWidget->currentIndex() == fishingPage){
        QPoint point = event->pos();
        emit sendPosition(point.x(), point.y());
    }
}

// set the spear label when it is shot
void View::updateSpearLabel(QPixmap map){
    ui->spearLabel->setAlignment(Qt::AlignCenter);
    ui->spearLabel->setPixmap(map);
}

// reset the spear label when going back to the fishing page
void View::resetSpearLabel(QPixmap map){
    ui->spearLabel->setGeometry(325, 0, 150, 150);
    ui->spearLabel->setAlignment(Qt::AlignCenter);
    ui->spearLabel->setPixmap(map);
}

// send a signal to shot the spear
void View::mousePressEvent(QMouseEvent *event){
    if(ui->stackedWidget->currentIndex() == fishingPage){
        QPoint point = event->pos();
        emit shootSpear(point.x(), point.y());
    }
}

void View::on_freshWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(fishingPage);

    QPixmap backgroundPix;
    backgroundPix.load(":/Background_Pond.png");
    ui->fishingBackgroundImageLabel->setPixmap(backgroundPix.scaled(800,570));

    emit updateWorld(ui->freshWaterButton->text());

    //reset progress bar for next level
    ui->progressBar2NextLevel->setValue(pondProgess);
}


void View::on_smoothWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(fishingPage);

    QPixmap backgroundPix;
    backgroundPix.load(":/Background_River.png");
    ui->fishingBackgroundImageLabel->setPixmap(backgroundPix.scaled(800,570));

    emit updateWorld(ui->smoothWaterButton->text());

    //reset progress bar for next level
    ui->progressBar2NextLevel->setValue(riverProgess);
}


void View::on_saltWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(fishingPage);

    QPixmap backgroundPix;
    backgroundPix.load(":/Background_Ocean.png");
    ui->fishingBackgroundImageLabel->setPixmap(backgroundPix.scaled(800,570));

    emit updateWorld(ui->saltWaterButton->text());

    //reset progress bar for next level
    ui->progressBar2NextLevel->setValue(seaProgess);
}


void View::setUpQuiz(QString question, QString answer, QString randAnswer1,
                     QString randAnswer2, QString randAnswer3,
                     QString fishPic, QString fishName){
    // Set up quiz background
    ui->quizBackgroundImageLabel->setStyleSheet("border-image: url(:/Background_QuizInfoPage.png)");


    ui->stackedWidget->setCurrentIndex(quizPage);
    ui->quizFishName->setText(fishName);
    ui->quizQ1Label->setText(question);

    //Randomize the result of buttons but check the answers to randomize
    int randNum = randAnswer3 != "N/A"? rand() % 4: rand() % 2;
    setButtonQuizVisibility(randAnswer3);


    switch (randNum) {
    case 0:
        ui->answ1Button->setText(answer);
        ui->answ1Button_2->setText(randAnswer1);
        ui->answ1Button_3->setText(randAnswer2);
        ui->answ1Button_4->setText(randAnswer3);
        break;
    case 1:
        ui->answ1Button->setText(randAnswer1);
        ui->answ1Button_2->setText(answer);
        ui->answ1Button_3->setText(randAnswer2);
        ui->answ1Button_4->setText(randAnswer3);
        break;
    case 2:
        ui->answ1Button->setText(randAnswer1);
        ui->answ1Button_2->setText(randAnswer2);
        ui->answ1Button_3->setText(answer);
        ui->answ1Button_4->setText(randAnswer3);
    case 3:
        ui->answ1Button->setText(randAnswer1);
        ui->answ1Button_2->setText(randAnswer2);
        ui->answ1Button_3->setText(randAnswer3);
        ui->answ1Button_4->setText(answer);
        break;
    }


    //Display the fish picture
    QPixmap pix;
    pix.load(fishPic);
    ui->fishPicLabel->setPixmap(pix.scaled(ui->fishPicLabel->width(), ui->fishPicLabel->height()));

    //results label
    ui->resultLabel->setVisible(false);

    //enable buttons
    ui->answ1Button->setEnabled(true);
    ui->answ1Button_2->setEnabled(true);
    ui->answ1Button_3->setEnabled(true);
    ui->answ1Button_4->setEnabled(true);

    //setVisible button
    ui->quizBackFishButton->setVisible(false);


}


void View::setButtonQuizVisibility(QString answ){

    if(answ == "N/A"){
        ui->answ1Button_3->setVisible(false);
        ui->answ1Button_4->setVisible(false);
    }
    else{
        ui->answ1Button_3->setVisible(true);
        ui->answ1Button_4->setVisible(true);
    }
}


void View::displayCountDown(QString time){
    ui->countDownLabel->setText(time);
    if(time == "0"){
        //send wrong answer to model
        disableQuizButtons();
        QString question = ui->quizQ1Label->text();
        emit checkUserAnswer(question, " ");
    }
}



void View::setUpInfo(QString q1,QString a1, QString q2, QString a2,
                     QString q3, QString a3, QString q4, QString a4,
                     QString fish, QString fishPic){

    ui->stackedWidget->setCurrentIndex(infoPage);
    ui->fishNameLabel->setText(fish);

    ui->infoQ1Label->setText(q1);
    ui->infoQ2Label->setText(q2);
    ui->infoQ3Label->setText(q3);
    ui->infoQ4Label->setText(q4);


    ui->infoA1Label->setText(a1);
    ui->infoA2Label->setText(a2);
    //Make the label to wrap up text
    ui->infoA3Label->setWordWrap(true);
    ui->infoA3Label->setText(a3);
    ui->infoA4Label->setText(a4);

     //Display the fish picture
    QPixmap pix;
    pix.load(fishPic);
    ui->inforFishPicLabel->setPixmap(pix.scaled(ui->inforFishPicLabel->width(), ui->inforFishPicLabel->height()));
    ui->fishInfoPageBackgroundImagelabel->setStyleSheet("border-image: url(:/Background_FishInfoPage.png)");
}

//**********************Journal *****************************
void View::setUpJournal(QVector<QString> info, QVector<QString> questions){

    QString fishPic;
    int count = 1;
    QString infoInLabel;
    ui->journalTittleLabel->setText(info[0]);
    ui->journalPageLabel->setText(info[1]);

    for(int i = 2; i < info.size(); i++){
        infoInLabel = "";
        //if it has not been cath
        if(info[i] == "uncached"){
            displayJournalLabels("uncached", ":/unknownFish.png", count);
            count++;
        }
        if(info[i] != "uncached"){
            fishPic = info[i];
            i++;
            int qNum = 0;
            for(int j = i; j < i+4; j++){
                infoInLabel += questions[qNum] + info[j] + "\n";
                qNum++;
            }
            displayJournalLabels(infoInLabel, fishPic, count);
            i += 3;
            count++;
        }
    }
}



//Helper method to display journal
void View::displayJournalLabels(QString info, QString fishPic, int fishNum){
    QPixmap pix;
    pix.load(fishPic);

    switch(fishNum){
    case 1:
        ui->journalInfoLabel_1->setText(info);
        ui->journalPicLabel_1->setPixmap(pix.scaled(ui->journalPicLabel_1->width(), ui->journalPicLabel_1->height()));
        break;
    case 2:
        ui->journalInfoLabel_2->setText(info);
        ui->journalPicLabel_2->setPixmap(pix.scaled(ui->journalPicLabel_2->width(), ui->journalPicLabel_2->height()));
        break;
    case 3:
        ui->journalInfoLabel_3->setText(info);
        ui->journalPicLabel_3->setPixmap(pix.scaled(ui->journalPicLabel_3->width(), ui->journalPicLabel_3->height()));
        break;
    case 4:
        ui->journalInfoLabel_4->setText(info);
        ui->journalPicLabel_4->setPixmap(pix.scaled(ui->journalPicLabel_4->width(), ui->journalPicLabel_4->height()));
        break;
    case 5:
        ui->journalInfoLabel_5->setText(info);
        ui->journalPicLabel_5->setPixmap(pix.scaled(ui->journalPicLabel_5->width(), ui->journalPicLabel_5->height()));
        break;
    }
}


void View::on_journalKeepFishingButton_clicked()
{
    emit resetWorld();
    ui->stackedWidget->setCurrentIndex(fishingPage);
}


void View::on_journalButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(journalPage);
    emit getJournal(journalPageNum);
}


void View::on_journalNextButton_clicked()
{
    if(journalPageNum<5)
        journalPageNum++;
    emit getJournal(journalPageNum);
}


void View::on_journalPrevButton_clicked()
{
    if(journalPageNum>0)
        journalPageNum--;
    emit getJournal(journalPageNum);
}

//**********************************************************

//Answer Buttons
void View::on_answerButton1_clicked(){

    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button->text();
    emit checkUserAnswer(question,answer);
    //disable buttons after selecting once
    disableQuizButtons();
}
void View::on_answerButton2_clicked(){

    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button_2->text();
    emit checkUserAnswer(question,answer);
    //disable buttons after selecting once
    disableQuizButtons();
}
void View::on_answerButton3_clicked(){
    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button_3->text();
    emit checkUserAnswer(question,answer);
    //disable buttons after selecting once
    disableQuizButtons();
}


void View::on_answ1Button_4_clicked()
{
    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button_4->text();
    emit checkUserAnswer(question,answer);
    //disable buttons after selecting once
    disableQuizButtons();
}

void View::disableQuizButtons(){
    //disable buttons after selecting once
    ui->answ1Button->setEnabled(false);
    ui->answ1Button_2->setEnabled(false);
    ui->answ1Button_3->setEnabled(false);
    ui->answ1Button_4->setEnabled(false);
}


void View::showResult(bool result, QString answer){
    if(result)
        ui->resultLabel->setText("You are Correct! \n The answer is: \n" + answer);
    else
        ui->resultLabel->setText("You are incorrect, try again \n This is the correct answer: \n" + answer);
    ui->resultLabel->setVisible(true);
    ui->quizBackFishButton->setVisible(true);
}



// Uncomment this when working on audios
void View::playBGM(QMediaPlayer::MediaStatus status){
    if (bgmPlayer->hasAudio()){
        bgmPlayer->play();
    }
    else{
        std::cout << "No media found" << std::endl;
    }
}
void View::pressMusicButton(){
    if(bgmPlayer->playbackState() == QMediaPlayer::PlayingState){
        bgmPlayer->stop();
        emit updateMainMenuMusicButton("Music: off");
    }
    else{
        bgmPlayer->play();
        emit updateMainMenuMusicButton("Music: on");
    }
}
void View::pressTestSoundButton(){
    SE_GameOver.setVolume(audioVolumn);
    SE_GameOver.play();
}


void View::updateNextLevelProgress(int progress, QChar waterType){
    //updated progress bar for nextlevel
    ui->progressBar2NextLevel->setValue(progress);

    //if progessbar is 5 or 100% we unlock the next level
    // we can remove the condition for watertype not equal to s, if we create another level after sea
    if(progress == 5 )
    {
        ui->congratsLabel->setVisible(true);
        ui->closeCongratsButton->setVisible(true);
        if(waterType == 's')
        {
            ui->congratsLabel->setText("Congrats you made it to the end of the level. \n We hope to release more levels soon. \n Keep up catching the fish and fill in the journal :D");
        }
        ui->closeCongratsButton->setEnabled(true);

        //TODO unlock the next level here
        if(waterType == 'p'){

            ui->smoothWaterButton->setEnabled(true);

        }
        else if(waterType =='r')
        {
            ui->saltWaterButton->setEnabled(true);
        }
    }

    if(waterType == 's')
        seaProgess = progress;
    else if(waterType == 'p')
        pondProgess = progress;
    else
        riverProgess = progress;
}

void View::updateNextSpearProgress(int progress){
    ui->progressBar2GetNewSpear->setValue(progress);
}




void View::on_return2FishButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(fishingPage);
}


void View::on_return2MenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(startPage);
}


void View::on_quizBackFishButton_clicked()
{
    emit resetWorld();
    ui->stackedWidget->setCurrentIndex(fishingPage);
}


void View::on_infoBackButton_clicked()
{
    emit resetWorld();
    ui->stackedWidget->setCurrentIndex(fishingPage);
}


void View::on_closeCongratsButton_clicked()
{
    ui->congratsLabel->setVisible(false);
    ui->closeCongratsButton->setEnabled(false);
    ui->closeCongratsButton->setVisible(false);
}

/**
 * @brief View::closeEvent
 * Opens a warning message, letting the user know they are exiting the game and giving them the choice to exit out or cancel the action.
 * @param event
 */
void View::closeEvent(QCloseEvent *event){

    //TODO: didn't stop the crash do more research
    QMessageBox::StandardButton closeBtn = QMessageBox::warning(this, "Spear Fishing",
                                                                tr("Are you sure you want to close the Game?"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::No);
    if(closeBtn != QMessageBox::Yes){
        event->ignore();
    }
    else{
        event->accept();
    }
}
