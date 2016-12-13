#pragma once
#include <QObject>

class PuzzleManager;
class ScoreKeeper;
class PuzzleForm;
namespace Ui {
class PuzzleForm;
}


class GameEngine: public QObject
{
    Q_OBJECT
public:
    GameEngine(QObject* parent=nullptr);
private:
    PuzzleManager *pM;
    Ui::PuzzleForm *ui;
    PuzzleForm *pF;
    ScoreKeeper *sK;
    bool gameRegime=true;
private slots:
    void newGame();
    void tryAgain();
    void cheat();
    void onWin(const QPair<int,int>& stats);
    void close();
signals:
    void callNewGame();
    void callTryAgain();
    void cheatTest();

};
