#pragma once
#include <QPair>
#include <QObject>

class PuzzleManager: public QObject
{
    Q_OBJECT
public:
    PuzzleManager(QObject* parent=nullptr);
private:
    QList<QString> currentOrder, initialOrder;
    void shuffleButtons();
private slots:
    void onPushedButton();
    void onRestart();
    void onNewGame();
signals:
    void assignedOrder(QList<QString>);
};

