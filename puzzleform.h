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
    Ui::PuzzleForm *ui;
    QMap<QString,QPushButton*> puzzlePieces;
private slots:
    void arrangePuzzle(const QList<QString>&);
    void showTime(int);
    void showMoves(int);
};

#endif // PUZZLEFORM_H
