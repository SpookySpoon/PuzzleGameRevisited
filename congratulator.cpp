#include "congratulator.h"
#include <QDebug>
#include "staticfunctions.h"
#include "congratulatorui.h"
#include "ui_congratswindow.h"
#include "scorehandler.h"
#include "gameengine.h"

Congratulator::Congratulator(const QPair<int,int>& results, bool regime, QObject *parent)
    :QObject(parent),stats(results), gameRegime(regime)
{}

Congratulator::~Congratulator()
{
    qDebug()<<"destroy";
    if(!conWindow->isHidden())
    {
        qDebug()<<"hide";
        conWindow->hide();
    }
    conWindow->deleteLater();
    delete ui;
}

void Congratulator::setUpCongratulator()
{
    ui=new Ui::CongratsWindow;
    conWindow = new CongratulatorUI(ui);
    ui->setupUi(conWindow);
    sHandler = new ScoreHandler(ui,this);
    setConnections();
    if(gameRegime)
    {
        ui->lableCheers->setText("Congratulations, you've solved a broblem!!");
        StaticFunctions::updateScore(stats.first,stats.second);
    }
    else
    {
        ui->lableCheers->setText("Nice practise, now go play it for real!");
    }
    sHandler->initScoreData(stats);
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
