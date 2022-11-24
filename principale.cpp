#include "principale.h"
#include "ui_principale.h"

principale::principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principale)
{
    ui->setupUi(this);
    afficheur.set_url(ui->urlEdit->text());
}

principale::~principale()
{
    delete ui;
}

void principale::owm_afficher()
{
    QString ville;
    ville = ui->urlEdit->text();

    afficheur.set_url("https://api.openweathermap.org");
    QJsonDocument documentJSON = QJsonDocument::fromJson(afficheur.get_jowm(ville));

    double owm = afficheur.get_owm(ville);
    ui->owmSpinBox->setValue(owm);
}

void principale::changer_url()
{
    afficheur.set_url(ui->urlEdit->text());
}
