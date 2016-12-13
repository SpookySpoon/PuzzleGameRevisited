#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include "congratulator.h"
#include "gameengine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Congratulator obana;
//    obana.prepareWindow(QPair<int,int>(15,15));
    GameEngine ee;
    return a.exec();
}





//TESTS
//void testPuzzleManager()
//{
//    PuzzleManager ee;
//    QPushButton pushButton;
//    pushButton_15.setObjectName("pushButton_14");
//    QObject::connect(&pushButton_15,SIGNAL(clicked()),&ee,SLOT(onPushedButton()));
//    pushButton_15.click();

//}
