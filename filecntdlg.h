#ifndef FILECNTDLG_H
#define FILECNTDLG_H

#include <QDialog>
#include <QFile>
#include <QTime>
#include <QTcpSocket>    //TCP套接口类库
#include <QHostAddress>  //网络ip地址类库

class QTcpSocket;   //客户端套接字类

namespace Ui {
class FileCntDlg;
}

class FileCntDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileCntDlg(QWidget *parent = 0);
    ~FileCntDlg();
    void getSrvAddr(QHostAddress saddr);    //获取服务器(发送端)IP
    void getLocPath(QString lpath);         //获取本地文件保存路径

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void createConnToSrv();     //连接到服务器

    void readChatMsg();     //读取服务器发送来的文件数据

    void on_cntClosePushButton_clicked();   //"停止"按钮的单击事件过程

private:
    Ui::FileCntDlg *ui;
    QTcpSocket *myCntSocket;        //客户端套接字指针
    QHostAddress mySrvAddr;         //服务器地址
    qint16 mySrvPort;               //服务器端口

    qint64 myTotalBytes;            //总共要接受的字节数
    qint64 myRcvedBytes;            //已接受的字节数
    QByteArray myInputBlock;        //缓存一次收下的数据
    quint16 myBlockSize;            //缓存块大小

    QFile *myLocPathFile;           //待接受文件对象指针
    QString myFileName;             //待收文件名
    qint64 myFileNameSize;          //文件名大小

    QTime mytime;
};

#endif // FILECNTDLG_H
