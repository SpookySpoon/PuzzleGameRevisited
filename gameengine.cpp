#include "gameengine.h"
#include "puzzlemanager.h"
#include "ui_puzzleform.h"
#include "congratulator.h"
#include "puzzleform.h"
#include "scorekeeper.h"

GameEngine::GameEngine(QObject* parent)
    :QObject (parent)
    , pM (new PuzzleManager(this))
    , cong(new Congratulator(this))
    , ui(new Ui::PuzzleForm)
    , pF(new PuzzleForm(ui))
    , sC(new ScoreKeeper(this))
{
    ui->setupUi(pF);
    connect(this,SIGNAL(callNewGame()),pM,SLOT(onNewGame()));
    connect(this,SIGNAL(callTryAgain()),pM,SLOT(onRestart()));
    connect(pM,SIGNAL(assignedOrder(QList<QString>)),pF,SLOT());
}


void GameEngine::newGame()
{
    emit callNewGame();
}

void GameEngine::tryAgain()
{
    emit callTryAgain();
}
