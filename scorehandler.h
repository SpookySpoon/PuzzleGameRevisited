#pragma once
#include <QObject>

namespace Ui {
class CongratsWindow;
}


class ScoreHandler: public QObject
{
    Q_OBJECT
public:
    ScoreHandler(Ui::CongratsWindow *ui, QObject* parent=nullptr);
    void initScoreData(const QPair<int,int>&);
    void initScoreDataNoRecord(const QPair<int,int>&);
private:
    int gameTime;
    int gameMoves;
    void inputData();
    Ui::CongratsWindow *conWinUI;
private slots:
    void resetHistory();
};
