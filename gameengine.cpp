#include "gameengine.h"
#include "puzzlemanager.h"
#include "ui_puzzleform.h"
#include "congratulator.h"
#include "puzzleform.h"
#include "scorekeeper.h"
#include <QDebug>
#include <QPushButton>

GameEngine::GameEngine(QObject* parent)
    :QObject (parent)
    , pM (new PuzzleManager(this))
    , cong(new Congratulator(this))
    , ui(new Ui::PuzzleForm)
    , pF(new PuzzleForm(ui))
    , sK(new ScoreKeeper(this))
{
    ui->setupUi(pF);
    connect(this,SIGNAL(callNewGame()),pM,SLOT(onNewGame()));
    connect(this,SIGNAL(callTryAgain()),pM,SLOT(onRestart()));
    connect(pM,SIGNAL(assignedOrder(QList<QString>)),pF,SLOT(arrangePuzzle(QList<QString>)));
    for (int i=1;i<=15;i++)
    {
        QPushButton* puzButt=pF->findChild<QPushButton*>(QString("pushButton_%1").arg(i));
        connect(puzButt,SIGNAL(clicked()),pM,SLOT(onPushedButton()));
    }
    connect(this,SIGNAL(changeGameRegime(bool)),cong,SLOT(setGameRegime(bool)));
    connect(ui->buttonRestart,SIGNAL(clicked()),this,SLOT(tryAgain()));
    connect(ui->buttonShuffle,SIGNAL(clicked()),this,SLOT(newGame()));
    connect(this,SIGNAL(callNewGame()),pM,SLOT(onNewGame()));
    connect(this,SIGNAL(callTryAgain()),pM,SLOT(onRestart()));
    connect(sK,SIGNAL(reportScore(QPair<int,int>)),cong,SLOT(prepareWindow(QPair<int,int>)));
    connect(sK,SIGNAL(reportMoves(int)),pF,SLOT(showMoves(int)));
    connect(sK,SIGNAL(reportTime(int)),pF,SLOT(showTime(int)));
//    pF->show();
}


void GameEngine::newGame()
{
    emit callNewGame();
    emit changeGameRegime(true);
}

void GameEngine::tryAgain()
{
    emit callTryAgain();
    emit changeGameRegime(false);
}
