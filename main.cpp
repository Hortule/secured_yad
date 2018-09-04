#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QNetworkRequest>
#include <QTextCodec>
#include <QMessageBox>


void MainWindow::sendGet(QString url)
{
    QNetworkRequest request;
    QNetworkReply *reply;
    QNetworkAccessManager manager;
    //user-agent
    request.setUrl(url);
    request.setRawHeader("Authorization:", " OAuth AQAAAAAJlF7xAADLW8Sf6NXX-0ugtcoEeY_6dyM");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    //reply from server
    reply = manager.get(request);
    connect(reply, SIGNAL(finished()),this,SLOT(getReplyFinished()));
}


void MainWindow::getReplyFinished()
{
    QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");//Нужная нам кодировка
    QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
    if(reply->error() != QNetworkReply::NoError)//Проверяем на ошибки
    {
        QMessageBox *info = new QMessageBox();
        info->information(this,"ERROR",reply->errorString());
        reply->deleteLater();
        return;
    }
    QString HTML = decoder->toUnicode(reply->readAll());
    reply->deleteLater();
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
