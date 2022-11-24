#ifndef OPENWM_H
#define OPENWM_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

class openwm
{
private:
    QUrl qurl;
    QByteArray get(QUrl url);
    QByteArray post(QUrl url, QJsonObject json);
    QNetworkAccessManager m;

public:
    openwm();
    void set_url(QString url);
    double get_owm(QString ville);
    QByteArray get_jowm(QString ville);
};

#endif // OPENWM_H
