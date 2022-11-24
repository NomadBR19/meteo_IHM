#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <openwm.h>

QT_BEGIN_NAMESPACE
namespace Ui { class principale; }
QT_END_NAMESPACE

class principale : public QMainWindow
{
    Q_OBJECT

public:
    principale(QWidget *parent = nullptr);
    ~principale();

private:
    Ui::principale *ui;
    openwm afficheur;

private slots:
    void changer_url();
    void owm_afficher();
};
#endif // PRINCIPALE_H
