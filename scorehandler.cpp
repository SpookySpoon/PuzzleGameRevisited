#include "scorehandler.h"
#include "staticfunctions.h"
#include "ui_congratswindow.h"
#include <QDebug>
#include <QDateTime>

ScoreHandler::ScoreHandler(Ui::CongratsWindow *ui, bool gameRegime, const QPair<int,int>& results, QObject *parent)
    :QObject (parent),conWinUI(ui)
{
    if(gameRegime)
    {
        conWinUI->lableCheers->setText("Congratulations, you've solved a broblem!!");
        StaticFunctions::updateScore(results.first,results.second);
    }
    else
    {
        ui->lableCheers->setText("Nice practise, now go play it for real!");
    }
    initScoreData(results);
}

void ScoreHandler::initScoreData(const QPair<int,int>& results)
{
    gameTime=results.first;
    gameMoves=results.second;
    inputData();
}

void ScoreHandler::resetHistory()
{
    StaticFunctions::resetScore(gameTime,gameMoves);
    inputData();
}

void ScoreHandler::inputData()
{
    QList<int> history=StaticFunctions::getScore();
    conWinUI->lableCurScoreTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(gameTime).toUTC().toString("hh:mm:ss")));
    conWinUI->lableCurScoreMoves->setText(QString("Number of moves: %1").arg(gameMoves));
    conWinUI->lableHistBTime->setText(QString("Your best time: %1").arg(QDateTime::fromTime_t(history.at(0)).toUTC().toString("hh:mm:ss")));
    conWinUI->lableHistBMoves->setText(QString("The least number of moves: %1").arg(history.at(1)));
    conWinUI->lableHistComboTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(history.at(2)).toUTC().toString("hh:mm:ss")));
    conWinUI->lableHistComboMoves->setText(QString("Number of moves: %1").arg(history.at(3)));
}

