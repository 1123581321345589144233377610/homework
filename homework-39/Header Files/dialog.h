#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void onPushButtonClicked();
private:
    Ui::Dialog *ui;
    QSqlDatabase database;
};

#endif // DIALOG_H
