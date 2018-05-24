#include "json.h"
#include "ui_json.h"
#include "avl2.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;


QString EnviarJSON="";
AVL2 *enviar = new AVL2();
JSON::JSON(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JSON)
{
    ui->setupUi(this);
    enviar->Conectar();
}

JSON::~JSON()
{
    delete ui;
}

///Enviar JSON...
void JSON::on_pushButton_clicked()
{

enviar->SayHello(EnviarJSON);
this->close();

}

///Canselar...
void JSON::on_pushButton_2_clicked()
{

}

void JSON::setJSON(QString json){
    EnviarJSON=json;
}

