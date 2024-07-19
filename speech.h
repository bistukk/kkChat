#ifndef SPEECH_H
#define SPEECH_H

#include <QObject>
#include "http.h"
#include <QJsonDocument>
#include<QJsonParseError>
#include<QJsonObject>
#include<QJsonArray>
#include<QHostInfo>
#include<QFile>
#include<QMessageBox>

//获取access_token相关
const QString baiduTokenUrl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id = "API_Key";
const QString client_secret = "Secret_Key";

//语音识别相关
const QString baiduSpeechUrl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2";

class Speech : public QObject
{
    Q_OBJECT
public:
    explicit Speech(QObject *parent = nullptr);

    QString speechIdentify(QString fileName);
    QString getJsonValue(QByteArray ba, QString key);

signals:

};

#endif // SPEECH_H
