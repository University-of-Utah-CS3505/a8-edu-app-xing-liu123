/**
 * Team: BAGJL
 * Students: Brittney Morales, Adriana Salazar, Xing Liu, Jinwen Lei, Gonzalo Tello
 * Course: CS3505
 * Date: April 26, 2022
 *
 **/

#include "view.h"
#include "model.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    View w(m);
    w.show();
    return a.exec();
}


