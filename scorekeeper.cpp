#include "scorekeeper.h"
#include <QTimerEvent>

ScoreKeeper::ScoreKeeper(QObject* parent):QObject(parent)
{}


void ScoreKeeper::reset()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    numberOfMoves=0;
    elapsedSeconds=0;
    emit reportMoves(numberOfMoves);
    emit reportTime(elapsedSeconds);
    timer.start(1000,this);
}

void ScoreKeeper::onMove()
{
    numberOfMoves++;
    emit reportMoves(numberOfMoves);
}

void ScoreKeeper::timerEvent(QTimerEvent* event)
{
    if (event->timerId() == timer.timerId())
    {
        ++elapsedSeconds;
        emit reportTime(elapsedSeconds);
    }
}

void ScoreKeeper::stopTracking()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    const QPair<int,int> stopSignal(elapsedSeconds,numberOfMoves);
    emit reportScore(stopSignal);
}
