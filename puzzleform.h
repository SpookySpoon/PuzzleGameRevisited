#pragma once
#include <QWidget>

namespace Ui {
class PuzzleForm;
}

class PuzzleForm : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleForm(Ui::PuzzleForm *ui, QWidget *parent = 0);
    ~PuzzleForm();
private:
    Ui::PuzzleForm *ui=nullptr;
};


