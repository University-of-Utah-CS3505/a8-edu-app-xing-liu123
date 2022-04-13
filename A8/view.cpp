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
    spearImage.load(":/spear.png");

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
    connect(&model,
            &Model::sendCollision,
            this,
            &View::notifyCollision);

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

void View::notifyCollision(){
    ui->stackedWidget->setCurrentIndex(4);

}

void View::mouseMoveEvent(QMouseEvent *event){

//    if(point.x() <= this->size().width() && point.y() <= this->size().height()
//            && point.x() > 0 && point.y() > 0 ){
//        QString s("X: ");
//        s.append(QString::number(point.x()));
//        s.append(" Y: ");
//        s.append(QString::number(point.y()));
//        ui->locationLabel->setText(s);
//    }

    QPoint point = event->pos();
    QImage rotated;
    QPixmap spearPix;

    if(point.y() > 75){
        double deltaX = point.x() - 400;
        double deltaY = point.y() - 75;
        double radian = -atan(deltaX/deltaY);
        double angle = radian*180 / M_PI;

        rotated = spearImage.transformed(QTransform().rotate(angle));
        spearPix = QPixmap::fromImage(rotated.scaled(150*(sin(abs(radian)) + cos(abs(radian))),150*(sin(abs(radian)) + cos(abs(radian)))));
    }
    else if(point.x() <= 400){
        rotated = spearImage.transformed(QTransform().rotate(90));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }
    else{
        rotated = spearImage.transformed(QTransform().rotate(-90));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }

    ui->spearLabel->setAlignment(Qt::AlignCenter);

    ui->spearLabel->setPixmap(spearPix);
}

void View::mousePressEvent(QMouseEvent *event){

    QPoint point = event->pos();
    if(point.y() > 75){
        float x = point.x() - 400;
        float y = point.y() - 75;
        emit shootSpear(x, y);
    }
    else if(point.x() <= 400){
        emit shootSpear(-1, 0);
    }
    else{
        emit shootSpear(1, 0);
    }
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
