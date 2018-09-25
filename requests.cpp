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
    request.setRawHeader("Authorization:", " OAuth AQAAAAAJlF7xAADLW8Sf6NXX-0ugtcoEeY_6dyM");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    reply = manager->get(request);//Получаем данные с сервера
    qDebug()<<"Task finished 1";
    QObject::connect (manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getReplyFinished(QNetworkReply*)));
    QString answer = reply->readAll();
    qDebug()<<answer;
}

void Req::getReplyFinished(QNetworkReply *reply)
{   qDebug()<<"Task finished";
    QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");//Нужная нам кодировка
    QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
    QString HTML = decoder->toUnicode(reply->readAll());
    reply->deleteLater();
}
