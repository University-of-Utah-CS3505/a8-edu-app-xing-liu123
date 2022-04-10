#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model &model, QWidget *parent = nullptr);
    ~View();


signals:
    void newPositiontValue(int height, int width);

private slots:
    void updateFish1();
    void updateFish2();
    void updateFish3();

private:
    Ui::View *ui;
    b2World *world;
    b2Body* body;
    b2Body* fish2;
    b2Body* fish3;
    QTimer timer;
    QImage image;
    //void labelNewposition(int height, int width);

};
#endif // VIEW_H


