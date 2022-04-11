#include "view.h"
#include "model.h"
#include "ui_view.h"

View::View(Model &model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    //ui->widget->show();
    QPixmap pix;
    pix.load(":/fish1.png");
    QPixmap pix2;
    pix2.load(":/fish2.png");

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
    ui->fish1Label->setGeometry(y * 100, x * 100,
                                ui->fish1Label->width(), ui->fish1Label->height());
}
void View::displayFish2(int x, int y){
    ui->fish2Label->setGeometry(y * 100, x * 100,
                                ui->fish2Label->width(), ui->fish2Label->height());

}
void View::displayFish3(int x, int y){
    ui->fish3Label->setGeometry(y * 100, x * 100,
                                ui->fish3Label->width(), ui->fish3Label->height());

}


