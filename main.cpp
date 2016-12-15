#include <QApplication>
#include "gameengine.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameEngine ee;

    return a.exec();
}

