#include <QDateTime>
#include "puzzleform.h"
#include "ui_puzzleform.h"

PuzzleForm::PuzzleForm(Ui::PuzzleForm *someUi, QWidget *parent) :
    QWidget(parent),
    ui(someUi)
{}

PuzzleForm::~PuzzleForm()
{
    delete ui;
}

void PuzzleForm::arrangePuzzle(const QList<QString>& order)
{
    for (int i_row=0;i_row<4;i_row++)
    {
        for (int i_col=0;i_col<4;i_col++)
        {
            QString buttonName=order.at(i_row*4+i_col);
            QPushButton* opa =this->findChild<QPushButton*>(QString(buttonName));
            if(opa)
            {
                ui->gridLayout->addWidget(opa,i_row,i_col,1,1);
            }
        }
    }
}

void PuzzleForm::showTime(int someTime)
{
    ui->lableElapsedTime->setText(QString("Time: %1").arg(QDateTime::fromTime_t(someTime).toUTC().toString("hh:mm:ss")));
}


void PuzzleForm::showMoves(int someMoves)
{
    ui->labelMoves->setText(QString("Moves: %1").arg(someMoves));
}
