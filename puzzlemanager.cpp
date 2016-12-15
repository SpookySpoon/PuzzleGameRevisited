#include <QDebug>
#include <QMessageBox>
#include "puzzlemanager.h"
#include "staticfunctions.h"
#include "ui_puzzleform.h"


PuzzleManager::PuzzleManager(Ui::PuzzleForm *someUiPuzForm, QObject* parent)
    :QObject(parent), uiPuzForm(someUiPuzForm)
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
    StaticFunctions::shuffleList(initialOrder);
    currentOrder=initialOrder;
    StaticFunctions::transPuzOrder(currentOrder,uiPuzForm);
}

void PuzzleManager::onRestart()
{
    currentOrder=initialOrder;
    StaticFunctions::transPuzOrder(currentOrder,uiPuzForm);
}

void PuzzleManager::onCheat()
{
    currentOrder=winningOrder;
    currentOrder.replace(15,QString("pushButton_15"));
    currentOrder.replace(14,QString(" "));
    StaticFunctions::transPuzOrder(currentOrder,uiPuzForm);
}

void PuzzleManager::onPushedButton()
{
    QString senderW=sender()->objectName();
    if(StaticFunctions::puzzleMover(currentOrder,senderW))
    {
        StaticFunctions::transPuzOrder(currentOrder,uiPuzForm);
        emit buttonMoved();
    }
    checkWin();
}

void PuzzleManager::checkWin()
{
    if(currentOrder==winningOrder)
    {
        emit gameWon();
    }
}
