#include "scorehandler.h"
#include "scoremanager.h"

ScoreHandler::ScoreHandler(QObject *parent):QObject (parent)
{}

void ScoreHandler::initScoreData(QPair<int,int> results)
{
    scoreManager::updateScore(results.first,results.second);
    inputData(results);
    emit statsReady();
}

void ScoreHandler::initScoreDataNoRecord(QPair<int,int> results)
{
    inputData(results);
    emit statsReady();
}

void ScoreHandler::resetHistory()
{
    scoreManager::resetScore(gameTime,gameMoves);
    inputData(QPair<int,int>(gameTime,gameMoves));
}

void ScoreHandler::inputData(QPair<int,int> results)
{
    gameTime=results.first;
    gameMoves=results.second;
    QList<int> history=scoreManager::getScore();
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
