#include "scorehandler.h"
#include "staticfunctions.h"
#include <QDebug>

ScoreHandler::ScoreHandler(QObject *parent):QObject (parent)
{}

void ScoreHandler::initScoreData(const QPair<int,int>& results)
{
    StaticFunctions::updateScore(results.first,results.second);
    inputData(results);
    emit statsReady();
}

void ScoreHandler::initScoreDataNoRecord(const QPair<int,int>& results)
{
    inputData(results);
    emit statsReady();
}

void ScoreHandler::resetHistory()
{
    StaticFunctions::resetScore(gameTime,gameMoves);
    QPair<int,int> currentStats(gameTime,gameMoves);
    inputData(currentStats);
}

void ScoreHandler::inputData(const QPair<int,int>& results)
{
    gameTime=results.first;
    gameMoves=results.second;
    QList<int> history=StaticFunctions::getScore();
    bestGameTime=history.at(0);
    bestGameMoves=history.at(1);
    bestComboGameTime=history.at(2);
    bestComboGameMoves=history.at(3);
    reportData();
}

void ScoreHandler::reportData()
{
    emit reportGameTime(gameTime);
    emit reportGameMoves(gameMoves);
    emit reportBestGameTime(bestGameTime);
    emit reportBestGameMoves(bestGameMoves);
    emit reportBestComboGameTime(bestComboGameTime);
    emit reportBestComboGameMoves(bestComboGameMoves);
}
