#ifndef REQUESTS_H
#define REQUESTS_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class Req : public QObject{
Q_OBJECT
public:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
    void sendGet(QString Url);
private slots:
    void getReplyFinished(QNetworkReply *reply);
};

#endif // REQUESTS_H

