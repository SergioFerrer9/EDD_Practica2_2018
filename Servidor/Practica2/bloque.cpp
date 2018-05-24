#include "bloque.h"
#include "ui_bloque.h"
#include "mainwindow.h"

Bloque::Bloque(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bloque)
{
    ui->setupUi(this);
}

Bloque::~Bloque()
{
    delete ui;
}

/// Boton Aceptar.......................
void Bloque::on_pushButton_clicked()
{
    char *Nombre=strdup(ui->lineEdit->text().toUtf8().constData());
    MainWindow *m = new MainWindow();
    m->setNombre(Nombre);
    this->close();

}
