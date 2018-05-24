#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subarbol.h"
#include "bloque.h"
#include "json.h"
#include "avl2.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <QDateTime>
#include <fstream>
#include "QMessageBox"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


using namespace std;
using std::cout;
using std::endl;


AVL2 *avl = new AVL2();



char *Nombre_Bloque;

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

//**************************CARGAR ARCHIVO******************************
void MainWindow::on_actionCargar_Archivo_triggered()
{

 Cargar_Archivo();
 avl->Agregar_Cola(1);


}

void MainWindow::Cargar_Archivo(){
    QString ruta=QFileDialog::getOpenFileName(this, tr("Abrir Archivo"), "",tr("Archivos EDD-B (*.edd-b)"));
    const std::string& path=ruta.toStdString();
    char *path2 =new char[path.length()+1];
    strcpy(path2, path.c_str());
    char *ptr;
    char *archivo;
    char *nombre;

     ptr=strtok(path2,"/");
     if(ptr==NULL){
         cout<<"Termino"<<endl;
     }
     while(ptr!=NULL){
          ptr=strtok(NULL,"/");
          if(ptr!=NULL){
              archivo=ptr;
          }

     }

     nombre=strtok(archivo,".");
     cout<<nombre<<endl; //Nombre del Archivo sin Extension...

     QTime time=QTime::currentTime();
     QDate date=QDate::currentDate();
     QString time_text=time.toString("hh:mm:ss");  //Hora...
     QString date_text=date.toString("dd:MM:yyyy");//Fecha...
     const std::string& h=time_text.toStdString();
     const std::string& d=date_text.toStdString();

     char *hora =new char[h.length()+1];
     strcpy(hora, h.c_str());
     char *fecha =new char[d.length()+1];
     strcpy(fecha, d.c_str());

     if(avl->Buscar_Arbol(nombre,hora,fecha)==false){

           if (ruta != NULL) {
               ifstream archivo (ruta.toLocal8Bit().data());
               if (archivo.is_open()){
                   string linea;
                   while(getline (archivo,linea)){
                       QString linea2=QString::fromLocal8Bit(linea.data());

                       QStringList listado=linea2.split(',');
                       if(listado.length()==3){  //Cantidad de Columnas...

                          int num0=listado[0].toInt(0,10);
                          const std::string& nom0=listado[0].toStdString();
                          char *nom1=new char[nom0.length()+1];
                          strcpy(nom1, nom0.c_str());

                          const std::string& no=listado[1].toStdString();
                          char *nom=new char[no.length()+1];
                          strcpy(nom, no.c_str());

                          QString nn=listado[2];
                          nn =nn.replace("\r\n", "").replace("\n", "").replace("\r", "");
                          const std::string& n=nn.toStdString();

                          char *nota=new char[n.length()+1];
                          strcpy(nota, n.c_str());
                         // nota=strtok(nota,"\n");

                          if(strcmp(nom1,"carnet")==0 |strcmp(nom,"nombre")==0 | strcmp(nota,"nota")==0){
                               cout<<"Error en la Linea del Archivo edd-b"<<endl;
                          }else{
                              avl->Agregar_En_AVL(nombre,num0,nom,nota);
                              cout<<num0<<" , "<<nom<<" , "<<nota<<endl;
                          }


                       }else{
                           QMessageBox::information(NULL,"Advertencia","Error al leer línea");
                       }
                   }

                   archivo.close();

               }else{
                   QMessageBox::information(NULL,"Advertencia","No se puede abrir el archivo");
               }

           }
    }

   avl->Graficar_AVL();
   Mostrar_Lista();
   Mostrar_Lista_Arboles();
}

//**********************Recorridos******************************

/// InOrden.................................
void MainWindow::on_actionInOrden_triggered()
{
    int ID=ui->lineEdit->text().toInt();
    QString InOrden=avl->Mostrar_InOrden(ID);
    ui->textEdit->clear();
    ui->textEdit->setText("InOrden: "+InOrden);
    avl->Graficar_AVL_Individual(ID);
    avl->Graficar_AVL_Individual2(ID);
    Mostrar_Arbol();

}

/// PostOrden.................................
void MainWindow::on_actionPostOrden_triggered()
{
    int ID=ui->lineEdit->text().toInt();
    QString PosOrden=avl->Mostrar_PosOrden(ID);
    ui->textEdit->clear();
    ui->textEdit->setText("PostOrden: "+PosOrden);
    avl->Graficar_AVL_Individual(ID);
    avl->Graficar_AVL_Individual2(ID);
    Mostrar_Arbol();

}

/// PreOrden.................................
void MainWindow::on_actionPreOrden_triggered()
{
    int ID=ui->lineEdit->text().toInt();
    QString PreOrden=avl->Mostrar_PreOrden(ID);
    ui->textEdit->clear();
    ui->textEdit->setText("PreOrden: "+PreOrden);
    avl->Graficar_AVL_Individual(ID);
    avl->Graficar_AVL_Individual2(ID);
    Mostrar_Arbol();
}
/// Amplitud.................................
void MainWindow::on_actionAmplitud_triggered()
{
    int ID=ui->lineEdit->text().toInt();
    QString Anchura=avl->Recorrido_Amplitud(ID);
    ui->textEdit->clear();
    ui->textEdit->setText("Amplitud/Anchura: "+Anchura);
    avl->Graficar_AVL_Individual(ID);
    avl->Graficar_AVL_Individual2(ID);
    Mostrar_Arbol();

}

/// Lista de Arboles.........................
void MainWindow::on_pushButton_clicked()
{
    Mostrar_Lista_Arboles();
}

///*************Mostrar Imagenes*******************************
void MainWindow::Mostrar_Lista_Arboles(){
    QPixmap pixavl("./ListaArboles.png");
    ui->label->setPixmap(pixavl);
}

void MainWindow::Mostrar_Lista(){
    QPixmap pixd("./ListaDoble.png");
    ui->label_2->setPixmap(pixd);

}

void MainWindow::Mostrar_Arbol(){
    QPixmap pixd("./AVL.png");
    ui->label->setPixmap(pixd);

    QPixmap pixd2("./AVL2.png");
    ui->label_8->setPixmap(pixd2);
}

/// Arbol Individual............................
void MainWindow::on_pushButton_2_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    avl->Graficar_AVL_Individual(ID);
    avl->Graficar_AVL_Individual2(ID);
    Mostrar_Arbol();
    avl->Graficar_Lista_Doble();
    Mostrar_Lista();

}

/// Editar......................................
void MainWindow::on_pushButton_3_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    int carne=ui->lineEdit_2->text().toInt();
    char *Nombre=strdup(ui->lineEdit_3->text().toUtf8().constData());
    char *Nota=strdup(ui->lineEdit_4->text().toUtf8().constData());

        avl->Editar_AVL(ID,carne,Nombre,Nota);
        Mostrar_Arbol();


}

/// Eliminar....................................
void MainWindow::on_pushButton_4_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    int carne=ui->lineEdit_2->text().toInt();
    avl->Eliminar_AVL(ID,carne);
    Mostrar_Arbol();

}

/// Agregar.....................................
void MainWindow::on_pushButton_5_clicked()
{

    int ID=ui->lineEdit->text().toInt();
    int carne=ui->lineEdit_2->text().toInt();
    char *Nombre=strdup(ui->lineEdit_3->text().toUtf8().constData());
    char *Nota=strdup(ui->lineEdit_4->text().toUtf8().constData());

    avl->Agregar_En_AVL2(ID, carne, Nombre, Nota);
    Mostrar_Lista_Arboles();
    Mostrar_Arbol();


}

/// Sub-Arbol..................................
void MainWindow::on_pushButton_6_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    int carne=ui->lineEdit_2->text().toInt();
    avl->Graficar_Sub_Arbol(ID,carne);

    Subarbol *sub = new Subarbol();
    sub->Setear();
    sub->show();

}

/// Info.Nodo.................................
void MainWindow::on_pushButton_7_clicked()
{
    QString info="";
    int ID=ui->lineEdit->text().toInt();
    int carne=ui->lineEdit_2->text().toInt();
    info = avl->Informacion_Nodo(ID,carne);
    QStringList listado=info.split(',');
    if(listado.length()==2){
        ui->lineEdit_3->setText(listado[0]);
        ui->lineEdit_4->setText(listado[1]);
    }else{
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }


}

/// SetNombre................................

void MainWindow::setNombre(char *Nombre){
    QString json= avl->Crear_Bloque(Nombre);
    if(json!=""){
        JSON *enviar = new JSON();
        enviar->setJSON(json);
        enviar->show();
    }else{
        cout<<"No se encontro..."<<endl;
    }

}

void MainWindow::setNombre2(QString Nombre){

        JSON *enviar = new JSON();
        enviar->setJSON(Nombre);
        enviar->show();


}


void MainWindow::on_actionLlave_Unica_triggered()
{
    Bloque *bloque = new Bloque();
    bloque->show();

}

/// Enviar JSON
void MainWindow::on_pushButton_8_clicked()
{
   avl->SayHello("Enviando..JSON");


}

void MainWindow::on_pushButton_9_clicked()
{
  avl->Conectar();
}
