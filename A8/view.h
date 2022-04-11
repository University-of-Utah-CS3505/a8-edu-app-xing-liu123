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
    void displayFish1(int x, int y);
    void displayFish2(int x, int y);
    void displayFish3(int x, int y);
    void startTime();

    void on_startButton_clicked();

private:
    Ui::View *ui;
    QTimer * time;

};
#endif // VIEW_H


