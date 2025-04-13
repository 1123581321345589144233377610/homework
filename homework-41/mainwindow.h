#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateDisplay();
    void on_startStopButton_clicked();
    void on_resetButton_clicked();
    void on_lapButton_clicked();
private:
    Ui::MainWindow *ui;
    Stopwatch stopwatch;
};
#endif // MAINWINDOW_H
