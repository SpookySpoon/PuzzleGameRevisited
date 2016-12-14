#pragma once
#include <QPair>
#include <QObject>

class PuzzleManager: public QObject
{
    Q_OBJECT
public:
    PuzzleManager(QObject* parent=nullptr);
private:
    QList<QString> currentOrder, initialOrder, winningOrder;
    void shuffleButtons();
    void checkWin();
private slots:
    void onPushedButton();
    void onRestart();
    void onNewGame();
    void onCheat();
signals:
    void assignedOrder(const QVariant&);
    void gameWon();
    void buttonMoved();
};

