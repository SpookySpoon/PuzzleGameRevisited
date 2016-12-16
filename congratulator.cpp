#include "congratulator.h"
#include "congratulatorui.h"
#include "ui_congratswindow.h"
#include "scorehandler.h"
#include "gameengine.h"

Congratulator::Congratulator(const QPair<int,int>& results, bool regime, QObject *parent)
    :QObject(parent),stats(results), gameRegime(regime)
{}

Congratulator::~Congratulator()
{
    if(!conWindow->isHidden())
    {
        conWindow->hide();
    }
    conWindow->deleteLater();
}

void Congratulator::setUpCongratulator()
{
    ui=new Ui::CongratsWindow;
    conWindow = new CongratulatorUI(ui);
    sHandler = new ScoreHandler(ui, gameRegime, stats, this);
    setConnections();
    conWindow->exec();
}

void Congratulator::setConnections()
{
    GameEngine* engine = qobject_cast<GameEngine*>(this->parent());
    if(engine)
    {
        connect(ui->buttonNewGame,SIGNAL(clicked()),this,SLOT(deleteLater()));
        connect(ui->buttonNewGame,SIGNAL(clicked()),engine,SLOT(newGame()));

        connect(ui->buttonTryAgain,SIGNAL(clicked()),this,SLOT(deleteLater()));
        connect(ui->buttonTryAgain,SIGNAL(clicked()),engine,SLOT(tryAgain()));

        connect(ui->buttonQuit,SIGNAL(clicked()),conWindow,SLOT(hide()));
        connect(ui->buttonQuit,SIGNAL(clicked()),this,SLOT(deleteLater()));
        connect(ui->buttonQuit,SIGNAL(clicked()),engine,SLOT(close()));

        connect(conWindow,SIGNAL(isClosed()),this,SLOT(deleteLater()));
        connect(conWindow,SIGNAL(isClosed()),engine,SLOT(newGame()));

        connect(ui->buttonResetHistory,SIGNAL(clicked()),sHandler,SLOT(resetHistory()));
    }
}
