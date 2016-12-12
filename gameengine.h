#pragma once
#include <QObject>

class PuzzleManager;
class ScoreKeeper;
class Congratulator;
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
    Congratulator *cong;
    PuzzleForm *pF;
    ScoreKeeper *sK;
private slots:
    void newGame();
    void tryAgain();
//    void close();
signals:
    void changeGameRegime(bool);
    void callNewGame();
    void callTryAgain();

};
