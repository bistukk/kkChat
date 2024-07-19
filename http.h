#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDebug>

class http : public QObject
{
    Q_OBJECT
public:
    explicit http(QObject *parent = nullptr);

    bool post_sync(QString Url, QMap<QString, QString> header, QByteArray requestData, QByteArray &replyData);


signals:

public slots:
};

#endif // HTTP_H
