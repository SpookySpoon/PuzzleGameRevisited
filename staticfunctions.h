#pragma once
#include <QList>
namespace Ui {
class PuzzleForm;
}
class StaticFunctions
{
public:
    static void updateScore(const int time, const int moves);
    static QList<int> getScore();
    static void resetScore(const int time, const int moves);
    static bool puzzleMover(QStringList& order, const QString& button);
    static void transPuzOrder(const QStringList& order, Ui::PuzzleForm* someUiPuzForm);
    static void shuffleList(QStringList& initialOrder);
    static QStringList getWinningOrder();
};
