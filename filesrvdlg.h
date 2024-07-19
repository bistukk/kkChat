#ifndef FILESRVDLG_H
#define FILESRVDLG_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTime>
#include <QTcpServer>   //TCP服务器类库
#include <QTcpSocket>   //TCP套接口类库

class QFile;
class QTcpServer;
class QTcpSocket;

namespace Ui {
class FileSrvDlg;
}

class FileSrvDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileSrvDlg(QWidget *parent = 0);
    ~FileSrvDlg();
    void cntRefused();  //被客户端拒绝后的处理方法

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void sndChatMsg();   //发送消息方法

    void refreshProgress(qint64 bynum);  //刷新服务器进度条的方法

    void on_openFilePushButton_clicked();   //打开选择要传输的文件

    void on_sendFilePushButton_clicked();   //“发送”按钮单击事件方法

    void on_srvClosePushButton_clicked();   //“停止”按钮单击事件方法

private:
    Ui::FileSrvDlg *ui;
    QTcpServer *myTcpSrv;           //TCP服务器对象指针
    QTcpSocket *mySrvSocket;        //TCP服务套接口指针
    qint16 mySrvPort;

    QFile *myLocPathFile;       //文件对象指针
    QString myPathFile;         //含路径的本地待发送文件名
    QString myFileName;         //文件名(去掉路径部分)

    qint64 myTotalBytes;        //总共要发送的字节数
    qint64 mySendBytes;         //已发送的字节数
    qint64 myBytesTobeSend;     //余下字节数
    qint64 myPayloadSize;       //有效载荷
    QByteArray myOutputBlock;   //缓存一次发送的数据
    QTime mytime;
signals:
    void sendFileName(QString name);
};

#endif // FILESRVDLG_H
