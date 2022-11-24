#include "openwm.h"

openwm::openwm()
{
}

double openwm::get_owm(QString ville)
{
    QUrl url = qurl;
    QString path = url.url() + "/data/2.5/weather?q=" + ville + "&appid=431b7f221c177f3f5ccc3a4557f00f24&units=metric";
    url = QUrl(path);

    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    QJsonObject objetJSON = documentJSON.object();
    QJsonValue dataJSON = objetJSON.value("main");

    qDebug()<< objetJSON.value("main").toObject().value("temp").toDouble();

    if(objetJSON.value("main").toObject().value("temp").toDouble())
        {
            return objetJSON.value("main").toObject().value("temp").toDouble();
        }
        else
        {
            return 0;
        }
}

QByteArray openwm::get_jowm(QString ville)
{
    QUrl url = qurl;
        QString path = url.url() + "/data/2.5/weather?q=" + ville + "&appid=431b7f221c177f3f5ccc3a4557f00f24&units=metric";
        url = QUrl(path);

        return get(url);
}

QByteArray openwm::get(QUrl url)
{

    QNetworkRequest requete(url);

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}

void openwm::set_url(QString url)
{
    qurl = QUrl(url);
}
