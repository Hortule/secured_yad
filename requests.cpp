#include "requests.h"
#include <QTextCodec>
#include <QString>
#include <QObject>
#include <QTextCodec>
#include <QString>
#include <QMessageBox>

void Req::sendGet(QString Url)
{   manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(Url);
    //user-agent
    request.setUrl(Url);
    authToken = "AQAAAAAJlF7xAADLW8Sf6NXX-0ugtcoEeY_6dyM";
    request.setRawHeader("Authorization", "OAuth " + authToken);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    reply = manager->get(request);//Получаем данные с сервера
    QObject::connect (manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getReplyFinished(QNetworkReply*)));
    QString answer = reply->readAll();
    qDebug()<<answer;
}

void Req::getReplyFinished(QNetworkReply *reply)
{   qDebug()<<"Task finished";
    QTextCodec* defaultTextCodec = QTextCodec::codecForName("UTF-8");//Нужная нам кодировка
    QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
    QString HTML = decoder->toUnicode(reply->readAll());
    reply->deleteLater();
    qDebug()<<HTML;
}
