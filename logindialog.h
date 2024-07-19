#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QFile>
#include "qdom.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_loginPushButton_clicked();
    void showKChatWindow();

private:
    Ui::LoginDialog *ui;
    MainWindow *kChatWindow;
    QDomDocument mydoc;
};

#endif // LOGINDIALOG_H
