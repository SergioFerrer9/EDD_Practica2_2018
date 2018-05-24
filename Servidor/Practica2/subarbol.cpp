#include "subarbol.h"
#include "ui_subarbol.h"

Subarbol::Subarbol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Subarbol)
{
    ui->setupUi(this);
}

Subarbol::~Subarbol()
{
    delete ui;
}

void Subarbol::Setear(){
    QPixmap pixd("./SubArbol.png");
    ui->label->setPixmap(pixd);
}
