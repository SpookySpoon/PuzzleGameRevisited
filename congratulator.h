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
    Congratulator(const QPair<int,int>& results, bool gameRegime, QObject* parent=nullptr);
    ~Congratulator();
    void setUpCongratulator();
private:
    QPair<int,int> stats;
    bool gameRegime;
    ScoreHandler *sHandler=nullptr;
    CongratulatorUI *conWindow=nullptr;
    Ui::CongratsWindow *ui=nullptr;
    void setConnections();
public slots:
    void showWindow();
signals:
    void initScoreHandler(const QPair<int,int>&);
    void initScoreHandlerNoRecord(const QPair<int,int>&);
};
