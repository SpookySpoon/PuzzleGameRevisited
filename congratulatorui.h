#pragma once

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
signals:
    void isClosed();
};

