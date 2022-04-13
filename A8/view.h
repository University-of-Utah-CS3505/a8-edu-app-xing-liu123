#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include "model.h"
#include <QMouseEvent>
#include <QHoverEvent>

    // Uncomment this when working on audios
//#include <QMediaPlayer>
//#include <QAudioOutput>
//#include <QAudioDevice>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model &model, QWidget *parent = nullptr);
    ~View();

    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

signals:
    void newPositiontValue(int height, int width);

    void updateWorld(QString water);
    void shootSpear(float x, float y);
    void collisionWithFish(); //Change in future


private slots:
    void displayFish1(int x, int y);
    void displayFish2(int x, int y);
    void displayFish3(int x, int y);
    void displaySpear(int x1, int y1, int x2, int y2);
    void notifyCollision();
    void startTime();

    // Uncomment this when working on audios
//    void playmedia(QMediaPlayer::MediaStatus status);


    void on_startButton_clicked();
    void setUpQuiz(QString question, QString answer, QString randAnswer1,
                   QString randAnswer2, QString fishPic);
    void setUpInfo(QString q1,QString a1, QString q2, QString a2,
                   QString q3, QString a3, QString q4, QString a4,
                   QString fish);

    void on_freshWaterButton_clicked();

    void on_smoothWaterButton_clicked();

    void on_saltWaterButton_clicked();


private:
    Ui::View *ui;
    QTimer * time;

    void setUpAnswers(QString answer, QString randAnswer1, QString randAnswer2);

    QImage spearImage;


    // Uncomment this when working on audios
//    QMediaPlayer* bgmPlayer = new QMediaPlayer;
//    QAudioOutput* bgmOutput = new QAudioOutput;
//    QAudioOutput* soundEffectOutput = new QAudioOutput;
//    QAudioDevice* audioDevice = new QAudioDevice;
};
#endif // VIEW_H


