#pragma once
#include <QPair>
#include <QObject>
#include <QBasicTimer>

namespace Ui {
class PuzzleForm;
}


class ScoreKeeper: public QObject
{
    Q_OBJECT
public:
    ScoreKeeper(Ui::PuzzleForm *ui, QObject* parent=nullptr);
private:
    int numberOfMoves;
    int elapsedSeconds;
    QBasicTimer timer;
    Ui::PuzzleForm *uiPF;
private slots:
    void reset();
    void stopTracking();
    void onMove();
protected:
    void timerEvent(QTimerEvent *event) override;
signals:
    void reportTime(int);
    void reportMoves(int);
    void reportScore(const QPair<int,int>&);

};
