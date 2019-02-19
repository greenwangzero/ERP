#include "api.h"

api::api()

{
    QString url=url1+"?key="+appkey;
    QNetworkRequest httpRequest;
    httpRequest.setUrl(QUrl(url));
    httpRequest.setRawHeader("Accept","text/html, application/xhtml+xml, application/xml; q=0.9, */*; q=0.8");
    httpRequest.setRawHeader("Accept-Encoding", "gzip, deflate");
    httpRequest.setRawHeader("Accept-Language","zh-CN,zh;q=0.8");
    httpRequest.setRawHeader("Cache-Control", "no-cache");
    httpRequest.setRawHeader("Connection","keep-alive");
    httpRequest.setRawHeader("Host","op.juhe.cn");
    httpRequest.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36 Edge/17.17134");
    manager = new QNetworkAccessManager(this);
    manager->get(httpRequest);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}
int api::getapi(){

}
void api::replyFinished(QNetworkReply *reply){
    QString all = reply->readAll();
    qDebug()<<all;
}
