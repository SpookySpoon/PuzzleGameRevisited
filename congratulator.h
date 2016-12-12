#pragma once
#include <QPair>
#include <QObject>

namespace Ui {
class CongratsWindow;
}

class ScoreHandler;
class CongratulatorUI;


class Congratulator: public QObject
{
    Q_OBJECT
public:
    Congratulator(QObject* parent=nullptr);
    bool getGR();
private:
    ScoreHandler *sHandler;
    CongratulatorUI *conWindow;
    Ui::CongratsWindow *ui;
    bool gameRegime=true;
    void setConnections();
public slots:
    void prepareWindow(QPair<int,int>);
    void setGameRegime(bool);
    void showWindow();
signals:
    void initScoreHandler(QPair<int,int>);
    void initScoreHandlerNoRecord(QPair<int,int>);

};
