#ifndef CONGRATULATORUI_H
#define CONGRATULATORUI_H

#include <QDialog>

namespace Ui {
class CongratsWindow;
}
class CongratulatorUI: public QDialog
{
    Q_OBJECT
public:
    explicit CongratulatorUI(Ui::CongratsWindow *ui,  QWidget* parent = nullptr);
private:
    Ui::CongratsWindow *ui;
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void setGameTime(int);
    void setGameMoves(int);
    void setBestGameTime(int);
    void setBestGameMoves(int);
    void setBestComboGameTime(int);
    void setBestComboGameMoves(int);
signals:
    void isClosed();
};

#endif // CONGRATULATORUI_H
