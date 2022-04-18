#include "view.h"
#include "model.h"
#include "ui_view.h"
#include <iostream>
#include <QPropertyAnimation>

View::View(Model &model,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{

    ui->setupUi(this);
    this->setMouseTracking(true);


    // Audios
    // Uncomment this when working on audios
    bgmOutput->setVolume(0.2f);
    bgmPlayer->setAudioOutput(bgmOutput);
    bgmPlayer->setSource(QUrl("qrc:/Waves.mp3"));
    connect(bgmPlayer, &QMediaPlayer::mediaStatusChanged, this, &View::playBGM);
    connect(ui->mainMenuMucisButton, &QPushButton::pressed, this, &View::pressMusicButton);
    connect(this, &View::updateMainMenuMusicButton, ui->mainMenuMucisButton, &QPushButton::setText);




    //Set up labels
    QPixmap water;
    water.load(":/water/freshW.jpg");
    ui->freshPicLabel->setPixmap(water.scaled(ui->freshPicLabel->width(), ui->freshPicLabel->height()));
    water.load(":/water/smoothW.jpg");
    ui->smoothPicLabel->setPixmap(water.scaled(ui->smoothPicLabel->width(), ui->smoothPicLabel->height()));
    water.load(":/water/saltW1.jpg");
    ui->saltPicLabel->setPixmap(water.scaled(ui->saltPicLabel->width(), ui->saltPicLabel->height()));

    QPixmap animatedFish;
    animatedFish.load(":/fish1.png");
    ui->fish1Label->setPixmap(animatedFish.scaled(ui->fish1Label->width(), ui->fish1Label->height()));
    ui->fish3Label->setPixmap(animatedFish.scaled(ui->fish3Label->width(), ui->fish3Label->height()));
    animatedFish.load(":/fish2.png");
    ui->fish2Label->setPixmap(animatedFish.scaled(ui->fish2Label->width(), ui->fish2Label->height()));

    QPixmap spearPix;
    spearPix.load(":/spear.png");
    ui->spearLabel->setPixmap(spearPix.scaled(ui->spearLabel->width(), ui->spearLabel->height()));
//    ui->spearLabel->setStyleSheet("QLabel{background-color : red}");
    //Set up the initial Widget
    ui->stackedWidget->setCurrentIndex(0);
    time = new QTimer(this);

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

}


View::~View()
{
    delete ui;
    delete time;

    // Uncomment this when working on audios
//    delete bgmPlayer;
//    delete bgmOutput;
//    delete soundEffectOutput;
//    delete audioDevice;
}



//Get the Program to start
void View::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


//Display the fish labels into their new position
void View::displayFish1(int x1, int y1, int x2, int y2){
//    std::cout << "hit " << std::endl;
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

void View::displaySpear(int x1, int y1, int x2, int y2){
    QPropertyAnimation *animation = new QPropertyAnimation(ui->spearLabel,"pos");
    animation->setDuration(25);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}


void View::mouseMoveEvent(QMouseEvent *event){
    QPoint point = event->pos();
    emit sendPosition(point.x(), point.y());
    QString s("X: ");
            s.append(QString::number(point.x()));
            s.append(" Y: ");
            s.append(QString::number(point.y()));
            ui->locationLabel->setText(s);
}

void View::updateSpearLabel(QPixmap map){
    ui->spearLabel->setAlignment(Qt::AlignCenter);
    ui->spearLabel->setPixmap(map);
}

void View::resetSpearLabel(QPixmap map){
    ui->spearLabel->setGeometry(325, 0, 150, 150);
    ui->spearLabel->setAlignment(Qt::AlignCenter);
    ui->spearLabel->setPixmap(map);
}



void View::mousePressEvent(QMouseEvent *event){
    QPoint point = event->pos();
    emit shootSpear(point.x(), point.y());
}

void View::on_freshWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    emit updateWorld(ui->freshWaterButton->text());
}


void View::on_smoothWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    emit updateWorld(ui->smoothWaterButton->text());
}


void View::on_saltWaterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    emit updateWorld(ui->saltWaterButton->text());
}


void View::setUpQuiz(QString question, QString answer, QString randAnswer1,
                     QString randAnswer2, QString fishPic, QString fishName){

    ui->stackedWidget->setCurrentIndex(4);
    ui->quizFishName->setText(fishName);
    ui->quizQ1Label->setText(question);

    //TODO: Get the answers of the buttons to wrap up if necesary


    //Randomize the result of buttons
    int randNum = rand() % 3;
    switch (randNum) {
    case 0:
        ui->answ1Button->setText(answer);
        ui->answ1Button_2->setText(randAnswer1);
        ui->answ1Button_3->setText(randAnswer2);
        break;
    case 1:
        ui->answ1Button->setText(randAnswer1);
        ui->answ1Button_2->setText(answer);
        ui->answ1Button_3->setText(randAnswer2);
        break;
    case 2:
        ui->answ1Button->setText(randAnswer1);
        ui->answ1Button_2->setText(randAnswer2);
        ui->answ1Button_3->setText(answer);
        break;
    }


    //Display the fish picture
    QPixmap pix;
    pix.load(fishPic);
    ui->fishPicLabel->setPixmap(pix.scaled(ui->fishPicLabel->width(), ui->fishPicLabel->height()));

    //results label
    ui->resultLabel->setVisible(false);

    //enable buttons
    ui->answ1Button->setDisabled(false);
    ui->answ1Button_2->setDisabled(false);
    ui->answ1Button_3->setDisabled(false);

    //setVisible button
    ui->quizBackFishButton->setVisible(false);

}


void View::setUpInfo(QString q1,QString a1, QString q2, QString a2,
                     QString q3, QString a3, QString q4, QString a4,
                     QString fish, QString fishPic){

    ui->stackedWidget->setCurrentIndex(3);
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
    ui->stackedWidget->setCurrentIndex(1);
}


void View::on_journalButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(journalPage);
    emit getJournal(journalPageNum);
}


void View::on_journalNextButton_clicked()
{
    journalPageNum++;
    emit getJournal(journalPageNum);
}


void View::on_journalPrevButton_clicked()
{
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
    ui->answ1Button->setDisabled(true);
    ui->answ1Button_2->setDisabled(true);
    ui->answ1Button_3->setDisabled(true);
}
void View::on_answerButton2_clicked(){

    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button_2->text();
    emit checkUserAnswer(question,answer);

    //disable buttons after selecting once
    ui->answ1Button->setDisabled(true);
    ui->answ1Button_2->setDisabled(true);
    ui->answ1Button_3->setDisabled(true);
}
void View::on_answerButton3_clicked(){
    QString question = ui->quizQ1Label->text();
    QString answer = ui->answ1Button_3->text();
    emit checkUserAnswer(question,answer);

    //disable buttons after selecting once
    ui->answ1Button->setDisabled(true);
    ui->answ1Button_2->setDisabled(true);
    ui->answ1Button_3->setDisabled(true);
}

void View::showResult(bool result){

    if(result)
        ui->resultLabel->setText("You are Correct!");
    else
        ui->resultLabel->setText("You are incorrect, try again");
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






void View::on_return2FishButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void View::on_return2MenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void View::on_quizBackFishButton_clicked()
{
    emit resetWorld();
    ui->stackedWidget->setCurrentIndex(1);
}


void View::on_infoBackButton_clicked()
{
    emit resetWorld();
    ui->stackedWidget->setCurrentIndex(1);
}

