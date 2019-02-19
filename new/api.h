#ifndef API_H
#define API_H
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkCookie>
#include<QtNetwork/QNetworkCookieJar>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include<QString>
#include<QDebug>
#include<QList>
#include<QUrl>
#include<QByteArray>

class api: public QObject
{
    Q_OBJECT
public:
    QString appkey="50cf26dbac0ed4fbaf54fa2cf24ac1d6";
    QString url1 = "http://op.juhe.cn/onebox/exchange/query";
     api();

    QNetworkAccessManager *manager;
    int getapi();
public slots:
    void replyFinished(QNetworkReply *);
};

#endif // API_H
