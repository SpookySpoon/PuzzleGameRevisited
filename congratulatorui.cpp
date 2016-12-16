#include <QDateTime>
#include <QDebug>
#include <QCloseEvent>
#include "congratulatorui.h"
#include "ui_congratswindow.h"

CongratulatorUI::CongratulatorUI(Ui::CongratsWindow *someUi, QWidget* parent):QDialog(parent), ui(someUi)
{}

void CongratulatorUI::closeEvent(QCloseEvent *event)
{
    emit isClosed();
    event->accept();
}
