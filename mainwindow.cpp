#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtWebKit/QWebView>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

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

//QNetworkAccessManager manager;

void MainWindow::on_pushButton_clicked()
{

    QUrl url("http://www.google.com");
    ui->webView->load(url);


    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll();

    QString x = "Nine pineapples";
    QString y = x.mid(5, 4);            // y == "pine"
    QString z = x.mid(5);               // z == "pineapples"
    ui->label5->setText(html);
   /* QNetworkAccessManager *manager;
    QNetworkRequest request(url);
    QNetworkReply *reply(manager.get(request));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    qDebug(reply->readAll()); */

}
