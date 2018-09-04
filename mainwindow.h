#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void getReplyFinished();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkReply *reply;
    QNetworkAccessManager manager;

    void sendGet(QString url);
};

#endif // MAINWINDOW_H
