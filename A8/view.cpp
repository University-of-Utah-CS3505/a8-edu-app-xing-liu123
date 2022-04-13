#include "view.h"
#include "model.h"
#include "ui_view.h"
#include <iostream>
#include <QPropertyAnimation>

View::View(Model &model, QWidget *parent)
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
    QPixmap pix;
    pix.load(":/fish1.png");
    QPixmap pix2;
    pix2.load(":/fish2.png");

    QPixmap spearPix;
    spearPix.load(":/spear.png");
    ui->spearLabel->setPixmap(spearPix.scaled(ui->spearLabel->width(), ui->spearLabel->height()));

    ui->stackedWidget->setCurrentIndex(0);
    time = new QTimer(this);

    ui->fish1Label->setPixmap(pix.scaled(ui->fish1Label->width(), ui->fish1Label->height()));
    ui->fish2Label->setPixmap(pix2.scaled(ui->fish2Label->width(), ui->fish2Label->height()));
    ui->fish3Label->setPixmap(pix.scaled(ui->fish3Label->width(), ui->fish3Label->height()));



    //Connections to set up first
    connect(ui->startButton,
            &QPushButton::clicked,
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

    // Uncomment this when working on audios
//void View::playmedia(QMediaPlayer::MediaStatus status){
//    if (bgmPlayer->hasAudio()){
//        bgmPlayer->play();
//    }
//    else{
//        std::cout << "No media found" << std::endl;
//    }
//}
