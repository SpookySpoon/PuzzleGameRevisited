#include <QDebug>
#include "puzzlemanager.h"
#include "time.h"

PuzzleManager::PuzzleManager(QObject* parent):QObject(parent)
{
    qDebug()<<"constructing order";
    for (int i=1;i<=15;i++)
    {
        initialOrder<<QString("pushButton_%1").arg(i);
    }
    initialOrder<<" ";
    currentOrder=initialOrder;
    connect(this,SIGNAL(assignedOrder(QList<QString>)),this,SLOT(testSlot(QList<QString>)));
}


void PuzzleManager::onPushedButton()
{
    qDebug()<<"arrived at onPushedButton";
    QString senderW=sender()->objectName();
    qDebug()<<"sender name is: "<<senderW;
    int index = currentOrder.indexOf(senderW);
    int column = index%4;
    int row = index/4;
    qDebug()<<"index is: "<<index;
    qDebug()<<"column is: "<<column<<" and row is: "<<row;
    bool mark=false;
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
                    currentOrder.replace(newIndex,senderW);
                    currentOrder.replace(index,QString(" "));
                    emit assignedOrder(currentOrder);
                    qDebug()<<"new order was announced";
                    qDebug()<<"one to last item"<<currentOrder.at(14);
                    qDebug()<<"last item"<<currentOrder.at(15);
                    mark=true;
                    break;
                }
            }
        }
        else
        {break;}
    }
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

void PuzzleManager::shuffleButtons()
{
    QList<QString> randPick=initialOrder;
    currentOrder.clear();
    srand (time(NULL));
    while(!randPick.isEmpty())
    {
        int iSecret = (rand() % (randPick.count()) + 1)-1;
        currentOrder<<randPick.takeAt(iSecret);
    }
    currentOrder<<" ";
}
