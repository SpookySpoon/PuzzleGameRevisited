#pragma once
#include <QObject>

class ScoreHandler: public QObject
{
    Q_OBJECT
public:
    ScoreHandler(QObject* parent=nullptr);
private:
    int gameTime;
    int gameMoves;
    int bestGameTime;
    int bestGameMoves;
    int bestComboGameTime;
    int bestComboGameMoves;
    void inputData(const QPair<int,int>&);
    void reportData();
private slots:
    void initScoreData(const QPair<int,int>&);
    void initScoreDataNoRecord(const QPair<int,int>&);
    void resetHistory();
signals:
    void reportGameTime(int);
    void reportGameMoves(int);
    void reportBestGameTime(int);
    void reportBestGameMoves(int);
    void reportBestComboGameTime(int);
    void reportBestComboGameMoves(int);
    void statsReady();
};
