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


    //ui->widget->show();
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


    //Ctach, Quiz and info window
    //TODO: Changed this one with Gon code
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


    if(point.x() <= this->size().width() && point.y() <= this->size().height()
            && point.x() > 0 && point.y() > 0 ){
//        std::cout << point.x() <<" " << point.y() << std::endl;
        QString s("X: ");
        s.append(QString::number(point.x()));
        s.append(" Y: ");
        s.append(QString::number(point.y()));
        ui->locationLabel->setText(s);
    }
}



void View::mousePressEvent(QMouseEvent *event){
    emit shootSpear();
}

void View::on_freshWaterButton_clicked()
{
    //TODO: Maybe change?
    ui->stackedWidget->setCurrentIndex(1);

    emit updateWorld(ui->freshWaterButton->text());
}


void View::on_smoothWaterButton_clicked()
{
    //TODO: Maybe change?
    ui->stackedWidget->setCurrentIndex(1);

     emit updateWorld(ui->smoothWaterButton->text());
}


void View::on_saltWaterButton_clicked()
{
    //TODO: Maybe change?
    ui->stackedWidget->setCurrentIndex(1);

     emit updateWorld(ui->saltWaterButton->text());
}


void View::setUpQuiz(QString question, QString answer, QString randAnswer1,
                     QString randAnswer2, QString fishPic){

    //TODO: Maybe change?
    ui->stackedWidget->setCurrentIndex(4);

    //TODO: Randomize the result of buttons
    ui->quizQ1Label->setText(question);
    ui->answ1Button->setText(answer);
    ui->answ1Button_2->setText(randAnswer1);
    ui->answ1Button_3->setText(randAnswer2);

    //TODO Set up the actual fish picture
    QPixmap pix;
    pix.load(":/fishPic.jpg");
    ui->fishPicLabel->setPixmap(pix.scaled(ui->fish1Label->width(), ui->fish1Label->height()));

}


void View::setUpInfo(QString q1,QString a1, QString q2, QString a2,
               QString q3, QString a3, QString q4, QString a4,
                     QString fish){

    //TODO: Maybe change?
    ui->stackedWidget->setCurrentIndex(3);

    ui->fishNameLabel->setText(fish);

      ui->infoQ1Label->setText(q1);
      ui->infoQ2Label->setText(q2);
      ui->infoQ3Label->setText(q3);
      ui->infoQ4Label->setText(q4);


      ui->infoA1Label->setText(a1);
      ui->infoA2Label->setText(a2);
      ui->infoA3Label->setText(a3);
      ui->infoA4Label->setText(a4);

      //TODO Set up the actual fish picture
      QPixmap pix;
      pix.load(":/fishPic.jpg");
      ui->inforFishPicLabel->setPixmap(pix.scaled(ui->inforFishPicLabel->width(), ui->inforFishPicLabel->height()));


}


