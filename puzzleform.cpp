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
