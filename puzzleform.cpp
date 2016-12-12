#include "puzzleform.h"
#include "ui_puzzleform.h"

PuzzleForm::PuzzleForm(Ui::PuzzleForm *someUi, QWidget *parent) :
    QWidget(parent),
    ui(someUi)
{


//    puzzlePieces
}

PuzzleForm::~PuzzleForm()
{
    delete ui;
}

void PuzzleForm::arrangePuzzle(QList<QString> order)
{
    for (int i_row=0;i_row<4;i_row++)
    {
        for (int i_col=0;i_col<4;i_col++)
        {
            QString buttonName=order.at(i_row*4+i_col);
            QPushButton* opa = qobject_cast<QPushButton*>(this->findChild(buttonName));
            if(opa)
            {
                ui->gridLayout->addWidget(opa,i_row,i_col,1,1);
            }
        }
    }
}
