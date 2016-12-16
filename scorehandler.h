#pragma once
#include <QObject>

namespace Ui {
class CongratsWindow;
}

class ScoreHandler: public QObject
{
    Q_OBJECT
public:
    ScoreHandler(Ui::CongratsWindow *ui, bool gameRegime, const QPair<int,int>& results, QObject* parent=nullptr);

private:
    int gameTime;
    int gameMoves;
    void inputData();
    Ui::CongratsWindow *conWinUI;
    void initScoreData(const QPair<int,int>&);
private slots:
    void resetHistory();
};
