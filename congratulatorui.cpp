#include <QDateTime>
#include "congratulatorui.h"
#include "ui_congratswindow.h"

CongratulatorUI::CongratulatorUI(Ui::CongratsWindow *someUi, QWidget* parent):QDialog(parent), ui(someUi)
{}

void CongratulatorUI::setGameTime(int value)
{
    ui->lableCurScoreTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(value).toUTC().toString("hh:mm:ss")));
}

void CongratulatorUI::setGameMoves(int value)
{
    ui->lableCurScoreMoves->setText(QString("Your best time: %1").arg(value));
}

void CongratulatorUI::setBestGameTime(int value)
{
    ui->lableHistBTime->setText(QString("Your best time: %1").arg(QDateTime::fromTime_t(value).toUTC().toString("hh:mm:ss")));
}

void CongratulatorUI::setBestGameMoves(int value)
{
    ui->lableHistBMoves->setText(QString("The least number of moves: %1").arg(value));
}

void CongratulatorUI::setBestComboGameTime(int value)
{
    ui->lableHistComboTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(value).toUTC().toString("hh:mm:ss")));
}

void CongratulatorUI::setBestComboGameMoves(int value)
{
    ui->lableHistComboMoves->setText(QString("Number of moves: %1").arg(value));
}
