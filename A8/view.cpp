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
    //    bgmPlayer->setAudioOutput(bgmOutput);
    //    bgmPlayer->setSource(QUrl("qrc:/new/audio/Water_Churning.mp3"));
    //    bgmOutput->setVolume(50);
    //    connect(bgmPlayer, &QMediaPlayer::mediaStatusChanged, this, &View::playmedia);



    // ui->widget->show();

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

    //Set up the initial Widget
    ui->stackedWidget->setCurrentIndex(0);
    time = new QTimer(this);


    //Connections to set up first
    connect(this,
            &View::updateWorld,
            &model,
            &Model::setUpWorld);

    //Connection for timer
    connect(time,
            &QTimer::timeout,
            &model,
            &Model::updateFish1);
    connect(time,
            &QTimer::timeout,
            &model,
            &Model::updateFish2);
    connect(time,
            &QTimer::timeout,
            &model,
            &Model::updateFish3);
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
    connect(&model,
            &Model::startTime,
            this,
            &View::startTime);

    // connects for spear
    connect(this,
            &View::shootSpear,
            &model,
            &Model::startTimer);
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


//Start timer.
void View::startTime(){
    time->start(75);
}


//Get the Program to start
void View::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


//Display the fish labels into their new position
void View::displayFish1(int x, int y){
    std::cout << "hit " << std::endl;
    ui->fish1Label->setGeometry(x * 100, y * 100,
                                ui->fish1Label->width(), ui->fish1Label->height());
}
void View::displayFish2(int x, int y){
    ui->fish2Label->setGeometry(x * 100, y * 100,
                                ui->fish2Label->width(), ui->fish2Label->height());

}
void View::displayFish3(int x, int y){
    ui->fish3Label->setGeometry(x * 100, y * 100,
                                ui->fish3Label->width(), ui->fish3Label->height());

}

void View::displaySpear(int x1, int y1, int x2, int y2){

    QPropertyAnimation *animation = new QPropertyAnimation(ui->spearLabel,"pos");
    animation->setDuration(100);
    animation->setStartValue(QPoint(x1,y1));
    animation->setEndValue(QPoint(x2,y2));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}


void View::mouseMoveEvent(QMouseEvent *event){
    QPoint point = event->pos();
    emit sendPosition(point.x(), point.y());
}

void View::updateSpearLabel(QPixmap map){
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





// Uncomment this when working on audios
//void View::playmedia(QMediaPlayer::MediaStatus status){
//    if (bgmPlayer->hasAudio()){
//        bgmPlayer->play();
//    }
//    else{
//        std::cout << "No media found" << std::endl;
//    }
//}

