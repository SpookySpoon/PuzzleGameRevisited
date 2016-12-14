#include "congratulator.h"
#include <QDebug>
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
    sHandler = new ScoreHandler(this);
    setConnections();
    if(gameRegime)
    {
        ui->lableCheers->setText("Congratulations, you've solved a broblem!!");
        emit initScoreHandler(stats);
    }
    else
    {
        ui->lableCheers->setText("Nice practise, now go play it for real!");
        emit initScoreHandlerNoRecord(stats);
    }
}


void Congratulator::showWindow()
{
    conWindow->exec();
}

void Congratulator::setConnections()
{
    GameEngine* engine = qobject_cast<GameEngine*>(this->parent());

    connect(sHandler,SIGNAL(reportBestComboGameMoves(int)),conWindow,SLOT(setBestComboGameMoves(int)));
    connect(sHandler,SIGNAL(reportBestComboGameTime(int)),conWindow,SLOT(setBestComboGameTime(int)));
    connect(sHandler,SIGNAL(reportBestGameMoves(int)),conWindow,SLOT(setBestGameMoves(int)));
    connect(sHandler,SIGNAL(reportBestGameTime(int)),conWindow,SLOT(setBestGameTime(int)));
    connect(sHandler,SIGNAL(reportGameMoves(int)),conWindow,SLOT(setGameMoves(int)));
    connect(sHandler,SIGNAL(reportGameTime(int)),conWindow,SLOT(setGameTime(int)));
    connect(sHandler,SIGNAL(statsReady()),this,SLOT(showWindow()));

    connect(this,SIGNAL(initScoreHandler(const QPair<int,int>&)),sHandler,SLOT(initScoreData(const QPair<int,int>&)));
    connect(this,SIGNAL(initScoreHandlerNoRecord(const QPair<int,int>&)),sHandler,SLOT(initScoreDataNoRecord(const QPair<int,int>&)));

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
