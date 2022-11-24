#include "openwm.h"

openwm::openwm()
{
}

double openwm::get_temp(QString ville)
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

QString openwm::get_temps(QString ville)
{
    QUrl url = qurl;
    QString path = url.url() + "/data/2.5/weather?q=" + ville + "&appid=431b7f221c177f3f5ccc3a4557f00f24&units=metric";
    url = QUrl(path);

    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    QJsonObject objetJSON = documentJSON.object();
    QJsonValue dataJSON = objetJSON.value("weather");

    qDebug()<< dataJSON.toArray().first().toObject().value("description").toString();

    QString desc = dataJSON.toArray().first().toObject().value("description").toString();
    return desc;
}

QString openwm::get_ant(QString ville)
{
    QUrl url = qurl;
    QString path = url.url() + "/data/2.5/weather?q=" + ville + "&appid=431b7f221c177f3f5ccc3a4557f00f24&units=metric";
    url = QUrl(path);

    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    QJsonObject objetJSON = documentJSON.object();
    QJsonValue dataJSON = objetJSON.value("name");

    qDebug()<< objetJSON.value("name").toString();

    QString desc = objetJSON.value("name").toString();
    return desc;
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
