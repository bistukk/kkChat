#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    ui->usrLineEdit->setFocus();
    ui->labelCover->setScaledContents(true);
    ui->labelCover->raise();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginPushButton_clicked()
{
    showKChatWindow();
}

void LoginDialog::showKChatWindow()
{
    QFile file("userlog.xml");
    file.open(QIODevice::ReadOnly);
    mydoc.setContent(&file);
    file.close();
    QDomElement root = mydoc.documentElement();
    if (root.hasChildNodes())
    {
        QDomNodeList userList = root.childNodes();
        bool exist = false;
        for (int i = 0; i < userList.count(); i++)
        {
            QDomNode user = userList.at(i);
            QDomNodeList record = user.childNodes();
            QString uname = record.at(0).toElement().text();
            QString pword = record.at(1).toElement().text();
            if (uname == ui->usrLineEdit->text())
            {
                exist = true;
                if (!(pword == ui->pwdLineEdit->text()))
                {
                    QMessageBox::warning(0, QObject::tr("提示"), "密码错误！请重新输入。");
                    ui->pwdLineEdit->clear();
                    ui->pwdLineEdit->setFocus();
                    return;
                }
            }
        }
        if (!exist)
        {
            QMessageBox::warning(0, QObject::tr("提示"), "此用户不存在！请重新输入。");
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
            return;
        }
        kChatWindow = new MainWindow(0);
        kChatWindow->setWindowTitle(ui->usrLineEdit->text());
        kChatWindow->show();
    }
}




