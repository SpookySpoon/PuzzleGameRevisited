#include <QDateTime>
#include <QDebug>
#include "puzzleform.h"
#include "ui_puzzleform.h"

PuzzleForm::PuzzleForm(Ui::PuzzleForm *someUi, QWidget *parent) :
    QWidget(parent),
    ui(someUi)
{
    ui->setupUi(this);
}

PuzzleForm::~PuzzleForm()
{
    delete ui;
}

void PuzzleForm::showTime(int someTime)
{
    ui->lableElapsedTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(someTime).toUTC().toString("hh:mm:ss")));
}

void PuzzleForm::showMoves(int someMoves)
{
    ui->labelMoves->setText(QString("Moves: %1").arg(someMoves));
}
