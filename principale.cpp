#include "principale.h"
#include "ui_principale.h"

principale::principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principale)
{
    ui->setupUi(this);
    afficheur.set_url(ui->villeBox->currentText());
}

principale::~principale()
{
    delete ui;
}

void principale::owm_afficher()
{
    QString ville;
    ville = ui->villeBox->currentText();

    afficheur.set_url("https://api.openweathermap.org");
    QJsonDocument documentJSON = QJsonDocument::fromJson(afficheur.get_jowm(ville));

    double temp = afficheur.get_temp(ville);
    QString temps = afficheur.get_temps(ville);
    QString antenne = afficheur.get_ant(ville);
    ui->owmSpinBox->setValue(temp);
    ui->tempEdit->setText(temps);
    ui->antenneEdit->setText(antenne);

    if(ville == "Cordon"){
        QString stalker = "Previye brat, zalyshatysya v ukryty";
        ui->cordon->setText(stalker);
        ui->cordon->setVisible(true);
        ui->owmSpinBox->setValue(999);
        ui->tempEdit->setText("emission");
        ui->antenneEdit->setText("Sidorovich's antenna");
    }
    else {ui->cordon->setVisible(false);}
}

void principale::changer_url()
{
    afficheur.set_url(ui->villeBox->currentText());
}
