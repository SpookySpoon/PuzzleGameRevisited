#ifndef PUZZLEFORM_H
#define PUZZLEFORM_H

#include <QWidget>
#include <QPushButton>
#include <QMap>

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
private slots:
    void arrangePuzzle(const QVariant&);
    void showTime(int);
    void showMoves(int);
};

#endif // PUZZLEFORM_H
