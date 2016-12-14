#include <QDebug>
#include <QMessageBox>
#include "puzzlemanager.h"
#include "time.h"

PuzzleManager::PuzzleManager(QObject* parent):QObject(parent)
{
    for (int i=1;i<=15;i++)
    {
        winningOrder<<QString("pushButton_%1").arg(i);
    }
    winningOrder<<" ";
    currentOrder=winningOrder;
    initialOrder=winningOrder;
}

void PuzzleManager::onNewGame()
{
    shuffleButtons();
    initialOrder=currentOrder;
    emit assignedOrder(currentOrder);
}

void PuzzleManager::onRestart()
{
    currentOrder=initialOrder;
    emit assignedOrder(currentOrder);
}

void PuzzleManager::onCheat()
{
    currentOrder=winningOrder;
    currentOrder.replace(15,QString("pushButton_15"));
    currentOrder.replace(14,QString(" "));
    emit assignedOrder(currentOrder);
}

void PuzzleManager::onPushedButton()
{
    QString senderW=sender()->objectName();
    int index = currentOrder.indexOf(senderW);
    int column = index%4;
    int row = index/4;
    bool mark=false;

//    QMessageBox opa1;
//    opa1.setText(QString("attempting to move Button %1").arg(senderW));
//    opa1.exec();



    for (int switchRowColumn=0; switchRowColumn<=1;switchRowColumn++)
    {
        if(!mark)
        {
            for(int i=-1;i<=1;i+=2)
            {
                int tempCol = std::max(column+i*switchRowColumn,0);
                tempCol=std::min(tempCol,3);
                int tempRow = std::max(row+i*(1-switchRowColumn),0);
                tempRow=std::min(tempRow,3);
                int newIndex=tempRow*4+tempCol;
                if(currentOrder.at(newIndex)==" ")
                {
//                    QMessageBox opa;
//                    opa.setText(QString("moving Button %1").arg(senderW));
//                    opa.exec();
                    currentOrder.replace(newIndex,senderW);
                    currentOrder.replace(index,QString(" "));
                    emit assignedOrder(currentOrder);
                    emit buttonMoved();
                    mark=true;
                    break;
                }
            }
        }
        else
        {break;}
    }
    checkWin();
}


void PuzzleManager::shuffleButtons()
{
    QList<QString> randPick=initialOrder;
    randPick.removeLast();
    currentOrder.clear();
    srand (time(NULL));
    while(!randPick.isEmpty())
    {
        int iSecret = (rand() % (randPick.count()) + 1)-1;
        currentOrder<<randPick.takeAt(iSecret);
    }
    currentOrder<<" ";
}

void PuzzleManager::checkWin()
{
    if(currentOrder==winningOrder)
    {
        emit gameWon();
    }
}
