#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requests.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Req* req = new Req();
    req->sendGet("https://cloud-api.yandex.net/v1/disk/");
}
