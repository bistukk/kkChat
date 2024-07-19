#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filesrvdlg.h"
#include "filecntdlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
    ui->labelUser->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    myUdpSocket = new QUdpSocket(this);
    myUdpPort = 23232;
    myUdpSocket->bind(myUdpPort, QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(myUdpSocket, SIGNAL(readyRead()), this, SLOT(recvAndProcessChatMsg()));
    myfsrv = new FileSrvDlg(this);
    connect(myfsrv, SIGNAL(sendFileName(QString)), this, SLOT(getSfileName(QString)));
}

void MainWindow::on_sendPushButton_clicked()
{
    sendChatMsg(ChatMsg);
}

void MainWindow::sendChatMsg(ChatMsgType msgType, QString rmtName)
{
    QByteArray qba;
    QDataStream write(&qba, QIODevice::WriteOnly);
    QString locHostIp = getLocHostIp();
    QString locChatMsg = getLocChatMsg();
    write << msgType << myname;
    switch (msgType)
    {
    case ChatMsg:
        write << locHostIp << locChatMsg;
        break;
    case OnLine:
        write << locHostIp;
        break;
    case OffLine:
        break;
    case SfileName:
        write << locHostIp << rmtName << myFileName;
        break;
    case RefFile:
        write << locHostIp << rmtName;
        break;
    }
    myUdpSocket->writeDatagram(qba, qba.length(), QHostAddress::Broadcast, myUdpPort);
}

void MainWindow::recvAndProcessChatMsg()
{
    while (myUdpSocket->hasPendingDatagrams())
    {
        QByteArray qba;
        qba.resize(myUdpSocket->pendingDatagramSize());
        myUdpSocket->readDatagram(qba.data(), qba.size());
        QDataStream read(&qba, QIODevice::ReadOnly);
        int msgType;
        read >> msgType;
        QString name, hostip, chatmsg, rname, fname;
        QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch (msgType)
        {
        case ChatMsg: {
            read >> name >> hostip >> chatmsg;
            ui->chatTextBrowser->setTextColor(Qt::darkGreen);
            ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 14));
            ui->chatTextBrowser->append("【" + name + "】" + curtime);
            ui->chatTextBrowser->append(chatmsg);
            break;
        }
        case OnLine:
            read >> name >> hostip;
            onLine(name, curtime);
            break;
        case OffLine:
            read >> name;
            offLine(name, curtime);
            break;
        case SfileName:
            read >> name >> hostip >> rname >> fname;
            recvFileName(name, hostip, rname, fname);
            break;
        case RefFile:
            read >> name >> hostip >> rname;
            if (myname == rname) myfsrv->cntRefused();
            break;
        }
    }
}

void MainWindow::onLine(QString name, QString time)
{
    bool notExist = ui->userListTableWidget->findItems(name, Qt::MatchExactly).isEmpty();
    if (notExist)
    {
        QTableWidgetItem *newuser = new QTableWidgetItem(name);
        ui->userListTableWidget->insertRow(0);
        ui->userListTableWidget->setItem(0, 0, newuser);
        ui->chatTextBrowser->setTextColor(Qt::gray);
        ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 12));
        ui->chatTextBrowser->append(tr("%1 %2 上线！").arg(time).arg(name));
        sendChatMsg(OnLine);
    }
}

void MainWindow::offLine(QString name, QString time)
{
    int row = ui->userListTableWidget->findItems(name, Qt::MatchExactly).first()->row();
    ui->userListTableWidget->removeRow(row);
    ui->chatTextBrowser->setTextColor(Qt::gray);
    ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 12));
    ui->chatTextBrowser->append(tr("%1 %2 离线！").arg(time).arg(name));
}

QString MainWindow::getLocHostIp()
{
    QList<QHostAddress> addrlist = QNetworkInterface::allAddresses();
    foreach (QHostAddress addr, addrlist)
    {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) return addr.toString();
    }
    return 0;
}

QString MainWindow::getLocChatMsg()
{
    QString chatmsg = ui->chatTextEdit->toHtml();
    ui->chatTextEdit->clear();
    ui->chatTextEdit->setFocus();
    return chatmsg;
}

void MainWindow::on_searchPushButton_clicked()
{
    myname = this->windowTitle();
    ui->userLabel->setText(myname);
    sendChatMsg(OnLine);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    sendChatMsg(OffLine);
}

void MainWindow::getSfileName(QString fname)
{
    myFileName = fname;
    int row = ui->userListTableWidget->currentRow();
    QString rmtName = ui->userListTableWidget->item(row, 0)->text();
    sendChatMsg(SfileName, rmtName);
}

void MainWindow::on_transPushButton_clicked()
{
    if(ui->userListTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0, tr("选择好友"), tr("请先选择文件接收方!"), QMessageBox::Ok);
        return;
    }
    myfsrv->show();
}

void MainWindow::recvFileName(QString name, QString hostip, QString rmtname, QString filename)
{
    if(myname == rmtname)
    {
        int result = QMessageBox::information(this, tr("收到文件"), tr("好友 %1 给你发送文件: \r\n%2, 是否接受? ")
                                             .arg(name).arg(filename), QMessageBox::Yes, QMessageBox::No);
        if(result == QMessageBox::Yes)
        {
            QString fname = QFileDialog::getSaveFileName(0, tr("保 存"), filename);
            if(!fname.isEmpty())
            {
                FileCntDlg *fcnt = new FileCntDlg(this);
                fcnt->getLocPath(fname);
                fcnt->getSrvAddr(QHostAddress(hostip));
                fcnt->show();
            }
        }else{
            sendChatMsg(RefFile, name);
        }
    }
}



void MainWindow::on_recordButton_pressed()
{
    ui->recordButton->setText("松开识别");

    // 检查指针是否已经初始化，如果已经初始化则先释放之前的对象
    if (audio) {
        delete audio;
        audio = nullptr;
    }

    audio = new Audio;
    audio->startAudio("D:\\1.pcm");
}

void MainWindow::on_recordButton_released()
{
    if (audio) {
        // 停止录音
        audio->stopAudio();
        // 修改按钮文字
        ui->recordButton->setText("开始识别");

        // 开始识别
        Speech *m_speech = new Speech(this);
        if (!m_speech) {
            qDebug() << "Failed to create Speech object";
            return;
        }

        QString text = m_speech->speechIdentify("D:\\1.pcm");
        if (text.isEmpty()) {
            qDebug() << "Speech recognition failed";
        } else {
            ui->chatTextEdit->setText(text);
        }

        ui->recordButton->setText("按住说话");

        // 释放Speech对象
        delete m_speech;
        m_speech = nullptr;

        // 释放Audio对象
        delete audio;
        audio = nullptr;
    }
}


