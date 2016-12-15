#include <QFile>
#include <QMap>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <time.h>
#include "staticfunctions.h"
#include "ui_puzzleform.h"


QList<int> StaticFunctions::getScore()
{
    QList<int> results;
    QFile tempFile("MyPuzzleScore.txt");
    QString raw="";
    if(tempFile.open(QIODevice::ReadOnly))
    {
        QTextStream txtMngr (&tempFile);
        raw = txtMngr.readLine();
        tempFile.close();
    }
    QStringList cutRaw = raw.split("[::]",QString::SkipEmptyParts);
    if(cutRaw.count()<5||raw=="")
    {
        results<<-1;
    }
    else
    {
        for(auto i:cutRaw)
        {
            results<<i.toInt();
        }
    }
    return results;
}

void StaticFunctions::updateScore(const int time, const int moves)
{
    QList<int> currentRecords=StaticFunctions::getScore();
    int bestTime, bestScore, bestTimeComb, bestScoreComb, gamesPlayed;
    if(currentRecords.at(0)>0)
    {
        bestTime=currentRecords.takeFirst();
        bestScore=currentRecords.takeFirst();
        bestTimeComb=currentRecords.takeFirst();
        bestScoreComb=currentRecords.takeFirst();
        gamesPlayed=currentRecords.takeFirst();
        if(bestTime>time)
        {
            bestTime=time;
        }
        if(bestScore>moves)
        {
            bestScore=moves;
        }
        if((bestTimeComb>time)&&(bestScoreComb>moves))
        {
            bestTimeComb=time;
            bestScoreComb=moves;
        }
        gamesPlayed++;
    }
    else
    {
        bestTime=time;
        bestScore=moves;
        bestTimeComb=time;
        bestScoreComb=moves;
        gamesPlayed=1;
    }
    QString sendResults =QString("%1[::]%2[::]%3[::]%4[::]%5").
            arg(bestTime).arg(bestScore).arg(bestTimeComb).arg(bestScoreComb).arg(gamesPlayed);
    QFile tempFile("MyPuzzleScore.txt");
    if(tempFile.open(QIODevice::Truncate|QIODevice::WriteOnly))
    {
        QTextStream outStream(&tempFile);
        outStream<<sendResults<<endl;
        tempFile.close();
    }
    else
    {
        QMessageBox noScoreBox;
        noScoreBox.setText("No score table was created.\nCheck your folder access parameters.");
        noScoreBox.exec();
    }
}

void StaticFunctions::resetScore(const int time, const int moves)
{
    QFile tempFile("MyPuzzleScore.txt");
    QString sendResults =QString("%1[::]%2[::]%3[::]%4[::]%5").
            arg(time).arg(moves).arg(time).arg(moves).arg(1);
    if(tempFile.open(QIODevice::Truncate|QIODevice::WriteOnly))
    {
        QTextStream outStream(&tempFile);
        outStream<<sendResults<<endl;
        tempFile.close();
    }
    else
    {
        QMessageBox noScoreBox;
        noScoreBox.setText("History reset failed.\nCheck your folder access parameters.");
        noScoreBox.exec();
    }
}

bool StaticFunctions::puzzleMover(QStringList& order, const QString& button)
{
    int indexSpace = order.indexOf(QString(" "));
    int columnSpace = indexSpace%4;
    int rowSpace = indexSpace/4;
    int indexButt = order.indexOf(button);
    int columnButt = indexButt%4;
    int rowButt = indexButt/4;
    int rowDiff=abs(rowSpace-rowButt);
    int colDiff=abs(columnSpace-columnButt);
    if(rowDiff+colDiff==1)
    {
        order.replace(indexSpace,button);
        order.replace(indexButt,QString(" "));
        return true;
    }
    else
    {
        return false;
    }
}

void StaticFunctions::transPuzOrder(const QStringList& order, Ui::PuzzleForm* someUiPuzForm)
{
    QMap<QWidget*,int> buttMap;
    for (int i=0;i<someUiPuzForm->gridLayout->count();i++)
    {
        QWidget* tempW=someUiPuzForm->gridLayout->itemAt(i)->widget();
        buttMap.insert(tempW,order.indexOf(tempW->objectName()));
    }
    for(auto i:buttMap.keys())
    {
        int index=buttMap.value(i);
        someUiPuzForm->gridLayout->addWidget(i,index/4,index%4);
    }
}

void StaticFunctions::shuffleList(QStringList& initialOrder)
{
    QStringList randPick=initialOrder;
    randPick.removeLast();
    initialOrder.clear();
    srand (time(NULL));
    while(!randPick.isEmpty())
    {
        int iSecret = (rand() % (randPick.count()) + 1)-1;
        initialOrder<<randPick.takeAt(iSecret);
    }
    initialOrder<<" ";
}

