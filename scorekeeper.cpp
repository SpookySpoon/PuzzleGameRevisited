#include <QDateTime>
#include <QTimerEvent>
#include "scorekeeper.h"
#include "ui_puzzleform.h"


ScoreKeeper::ScoreKeeper(Ui::PuzzleForm *ui, QObject* parent)
    :QObject(parent), uiPF(ui)
{}


void ScoreKeeper::reset()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    numberOfMoves=0;
    elapsedSeconds=0;
    uiPF->labelMoves->setText(QString("Moves: %1").arg(numberOfMoves));
    uiPF->lableElapsedTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(elapsedSeconds).toUTC().toString("hh:mm:ss")));
    timer.start(1000,this);
}

void ScoreKeeper::onMove()
{
    numberOfMoves++;
    uiPF->labelMoves->setText(QString("Moves: %1").arg(numberOfMoves));
}

void ScoreKeeper::timerEvent(QTimerEvent* event)
{
    if (event->timerId() == timer.timerId())
    {
        ++elapsedSeconds;
        uiPF->lableElapsedTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(elapsedSeconds).toUTC().toString("hh:mm:ss")));
    }
}

void ScoreKeeper::stopTracking()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    QPair<int,int> stopSignal(elapsedSeconds,numberOfMoves);
    emit reportScore(stopSignal);
}
