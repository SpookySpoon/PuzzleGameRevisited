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
    for (int i=1;i<=15;i++)
    {
        QPushButton* puzButt=pF->findChild<QPushButton*>(QString("pushButton_%1").arg(i));
        connect(puzButt,SIGNAL(clicked()),pM,SLOT(onPushedButton()));
    }
    connect(ui->buttonRestart,SIGNAL(clicked()),this,SLOT(tryAgain()));
    connect(ui->buttonShuffle,SIGNAL(clicked()),this,SLOT(newGame()));
    connect(ui->buttonCheat,SIGNAL(clicked()),this,SLOT(cheat()));

    connect(this,SIGNAL(callNewGame()),pM,SLOT(onNewGame()));
    connect(this,SIGNAL(callTryAgain()),pM,SLOT(onRestart()));
    connect(this,SIGNAL(cheatTest()),pM,SLOT(onCheat()));
    connect(this,SIGNAL(callNewGame()),sK,SLOT(reset()));
    connect(this,SIGNAL(callTryAgain()),sK,SLOT(reset()));
    connect(this,SIGNAL(changeGameRegime(bool)),cong,SLOT(setGameRegime(bool)));

    connect(pM,SIGNAL(assignedOrder(QList<QString>)),pF,SLOT(arrangePuzzle(QList<QString>)));
    connect(pM,SIGNAL(buttonMoved()),sK,SLOT(onMove()));
    connect(pM,SIGNAL(gameWon()),sK,SLOT(stopTracking()));

    connect(sK,SIGNAL(reportScore(QPair<int,int>)),cong,SLOT(prepareWindow(QPair<int,int>)));
    connect(sK,SIGNAL(reportMoves(int)),pF,SLOT(showMoves(int)));
    connect(sK,SIGNAL(reportTime(int)),pF,SLOT(showTime(int)));

    pF->show();
    emit callNewGame();
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

void GameEngine::cheat()
{
    emit cheatTest();
}
