#pragma once
#include <QPair>
#include <QObject>
#include <QBasicTimer>


class ScoreKeeper: public QObject
{
    Q_OBJECT
public:
    ScoreKeeper(QObject* parent=nullptr);
private:
    int numberOfMoves;
    int elapsedSeconds;
    QBasicTimer timer;
private slots:
    void reset();
    void stopTracking();
    void onMove();
protected:
    void timerEvent(QTimerEvent *event) override;
signals:
    void reportTime(int);
    void reportMoves(int);
    void reportScore(QPair<int,int>);
};
