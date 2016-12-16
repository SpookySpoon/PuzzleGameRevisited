#pragma once
#include <QPair>
#include <QObject>

namespace Ui {
class PuzzleForm;
}


class PuzzleManager: public QObject
{
    Q_OBJECT
public:
    PuzzleManager(Ui::PuzzleForm *uiPuzForm, QObject* parent=nullptr);
private:
    QStringList currentOrder, initialOrder, winningOrder;
    void checkWin();
    Ui::PuzzleForm *uiPuzForm=nullptr;
private slots:
    void onPushedButton();
    void onRestart();
    void onNewGame();
    void onCheat();
signals:
    void gameWon();
    void buttonMoved();
};

