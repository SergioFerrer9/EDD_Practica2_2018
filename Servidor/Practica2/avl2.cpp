#include "avl2.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "json.h"
#include "mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

using namespace std;
using std::cout;
using std::endl;


typedef struct NodoDoble NodoD;
NodoD *primeroD;
NodoD *ultimoD;

typedef struct NodoAVL nodoAVL;
int correlativo=1;

typedef struct NodoInfo NodoI;
NodoI *primeoI;

QString InOrden="";
QString PosOrden="";
QString PreOrden="";
QString Amplitud="";
QString info="";
QString LLave="";
QString JSON="";
QString in="";
QString pos="";
QString pre="";


///***************SOCKETS UDP*************************************************
AVL2::AVL2(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

void::AVL2::SayHello(QString json){
    QByteArray Data;
    Data.append(json);
    socket->writeDatagram(Data,QHostAddress("127.0.0.1"),9108);

}

void AVL2::readyRead(){
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);
    Leer_JSON2(Buffer);


}

void AVL2::Leer_JSON2(QString json){

    QByteArray json_bytes = json.toLocal8Bit();
    auto json_doc=QJsonDocument::fromJson(json_bytes);
    QJsonObject json_obj=json_doc.object();
    QVariantMap json_map = json_obj.toVariantMap();

    QString Nombre =json_map["nombre"].toString();
    char *nom=Nombre.toUtf8().data();

    QString j=Crear_Bloque(nom);

    if(j!=""){
        MainWindow *m = new MainWindow();
        m->setNombre2(j);
    }else{
        cout<<"No se Encontro"<<endl;
    }


}

void AVL2::Conectar(){
    socket->bind(QHostAddress("127.0.0.1"),9107);
}
///***************************************************************************

void AVL2::Agregar_Lista_Doble(char *Nombre, char *hora, char *fecha){
    ///Declarar Nodo de la Lista Doble....
    NodoD *nuevoD;
    nuevoD = (NodoD*)malloc(sizeof(struct NodoDoble));
    nuevoD->Nombre=Nombre;
    nuevoD->Hora=hora;
    nuevoD->Fecha=fecha;
    nuevoD->seleccion=0;
    nuevoD->sig=NULL;
    nuevoD->ant=NULL;
    nuevoD->RAIZ=NULL;

    if(primeroD==NULL){
        nuevoD->ID=contador;
        nuevoD->sig=NULL;
        nuevoD->ant=NULL;
        primeroD=nuevoD;
        ultimoD=nuevoD;
        contador++;

    }else{
            nuevoD->ID=contador;
            nuevoD->sig=NULL;
            nuevoD->ant=ultimoD;
            ultimoD->sig=nuevoD;
            ultimoD=nuevoD;
            contador++;
    }

    Graficar_Lista_Doble();
}

bool AVL2::Buscar_Arbol(char *Nombre, char *hora, char *fecha){
    NodoD *aux=primeroD;
    bool dato=false;
    if(aux!=NULL){
        while(aux!=NULL){
            aux->seleccion=0;
            if(strcmp(aux->Nombre,Nombre)==0){

                dato=true;
                break;
            }

         aux=aux->sig;
        }
    }

    if(dato==true){
        return true;
    }else{
        Agregar_Lista_Doble(Nombre,hora,fecha);
        return  false;
    }

}



void AVL2::Graficar_Lista_Doble(){
    FILE *gra;
    gra=fopen("ListaDoble.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);
    NodoD *aux=primeroD;
    if(aux!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    int a=1;

    while(aux!=NULL){
        fputs("\"",gra);
        fputs("nodoD",gra);
        fprintf(gra,"%d",a);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" " );
            fputs("ID: ",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("&#92;n",gra);
            fputs("Nombre: ",gra);
            fprintf(gra, "%s",aux->Nombre);
            fputs("&#92;n",gra);
            fputs("Hora: ",gra);
            fprintf(gra, "%s",aux->Hora);
            fputs("&#92;n",gra);
            fputs("Fecha: ",gra);
            fprintf(gra, "%s",aux->Fecha);
            if(aux->seleccion==1){
                fputs("\",fillcolor=cyan ];\n",gra);
            }else{
                 fputs("\"];\n",gra);
            }

        a++;
        aux=aux->sig;
    }


    int b =1;
    int c =b+1;
    aux=primeroD;
    if(aux!=NULL){
         while(aux->sig!=NULL){
            /// nodo1---->nodo2 siguintes
            fputs("\"nodoD",gra);
            fprintf(gra,"%d",b);
            fputs("\"-> \"nodoD",gra);
            fprintf(gra,"%d",c);
            fputs( "\";\n",gra);

            fputs("\"nodoD",gra);
            fprintf(gra,"%d",c);
            fputs("\"-> \"nodoD",gra);
            fprintf(gra,"%d",b);
            fputs( "\";\n",gra);

            b++;
            c++;
            aux=aux->sig;
        }
    }


    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Lista Doble\"\n",gra);
    fputs("}\n",gra);

 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Lista de Arboles " );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Niveles\"\n",gra);
        fputs("}\n",gra);

        printf("Lista esta Vacia...");


  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaDoble.dot -o ListaDoble.png");
}


///********************Arbol AVL*********************************************
///Altura del arbol AVL.................................
int Altura(NodoAVL *actual){
    if(actual==NULL){
        return 0;
    }else{
        return actual->Altura;
    }
}

int Mayor(int num1, int num2){
    if(num1>num2){
        return num1;
    }else{
        return num2;
    }
}

///****************ROTACIONES*************************************
NodoAVL *AVL2::Izquierda(NodoAVL *n1){
    NodoAVL *n2 =n1->izq;
    n1->izq=n2->der;
    n2->der=n1;
    n1->Altura=Mayor(Altura(n1->izq),Altura(n1->der)) +1;
    n2->Altura=Mayor(Altura(n2->izq), n1->Altura) +1;
    return n2;
}

NodoAVL *AVL2::Derecha(NodoAVL *n1){
    NodoAVL *n2 =n1->der;
    n1->der=n2->izq;
    n2->izq=n1;
    n1->Altura=Mayor(Altura(n1->izq), Altura(n1->der)) +1;
    n2->Altura=Mayor(Altura(n2->der), n1->Altura) +1;
    return n2;
}

NodoAVL *AVL2::IzquierdaDerecha(NodoAVL *n1){
    n1->izq=Derecha(n1->izq);
    return Izquierda(n1);
}

NodoAVL *AVL2::DerechaIzquierda(NodoAVL *n1){
    n1->der=Izquierda(n1->der);
    return Derecha(n1);
}

///***********BUSCAR**********************************************


///***********INSERTAR EN EL ARBOL AVL****************************
NodoAVL *AVL2::Insertar(NodoAVL *nuevo, NodoAVL *actual){

   if(actual == NULL){
       actual = nuevo;

   }else if(nuevo->Carne < actual->Carne){
       actual->izq=Insertar(nuevo,actual->izq);

       if((Altura(actual->der)-Altura(actual->izq))==-2){

           if(nuevo->Carne < actual->izq->Carne){
               actual=Izquierda(actual);

           }else{

               actual=IzquierdaDerecha(actual);
           }

       }

   }else if(nuevo->Carne > actual->Carne){
       actual->der=Insertar(nuevo,actual->der);

       if((Altura(actual->der) - Altura(actual->izq))==2){

           if(nuevo->Carne > actual->der->Carne){

               actual=Derecha(actual);

           }else{

               actual = DerechaIzquierda(actual);
           }
       }
   }else{

       cout<<"Valores Repetidos...  "<<endl;
       //cout<<nuevo->Nombre<<endl;
   }

       actual->Altura = Mayor(Altura(actual->izq), Altura(actual->der)) + 1;
       return actual;

}

///********METODO PARA OBTENER EL NODO REEMPLAZO****************
NodoAVL *AVL2::Obtener_Reemplazo(NodoAVL *reemp){
    nodoAVL *reemplazarPadre=reemp;
    nodoAVL *reemplazo=reemp;
    nodoAVL *auxiliar=reemp->der;
    while(auxiliar!=NULL){
        reemplazarPadre=reemplazo;
        reemplazo=auxiliar;
        auxiliar=auxiliar->izq;
    }
    if(reemplazo!=reemp->der){
        reemplazarPadre->izq=reemplazo->der;
        reemplazo->der=reemp->der;
    }
    cout<<"El Nodo Reemplazo es "<<reemplazo->Nombre<<endl;
    return reemplazo;
}

///*********EQUILIBRAR ARBOL AVL********************************
void AVL2::Ajustar_Fe(NodoAVL *actual, int Nivel){

        if(actual!=NULL){
           actual->fe=Altura(actual->der)-Altura(actual->izq);
           actual->Altura = Mayor(Altura(actual->izq), Altura(actual->der)) + 1;
           actual->Nivel=Nivel;
              if(actual->izq!=NULL){

               Ajustar_Fe(actual->izq, Nivel+1);

           }
           if(actual->der!=NULL){

            Ajustar_Fe(actual->der, Nivel+1);

           }

         }
}


void AVL2::Agregar_En_AVL(char *archivo, int carne, char *nombre, char *nota){
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){

            if(strcmp(aux->Nombre,archivo)==0){
                NodoAVL *nuevo;
                nuevo=(nodoAVL*)malloc(sizeof(struct NodoAVL));
                nuevo->Carne=carne;
                nuevo->Nombre=nombre;
                nuevo->Nota=nota;
                nuevo->Altura=0;
                nuevo->fe=0;
                nuevo->Nivel=0;
                nuevo->izq=NULL;
                nuevo->der=NULL;
                nuevo->Contador=correlativo++;

                aux->RAIZ=Insertar(nuevo,aux->RAIZ);
                Ajustar_Fe(aux->RAIZ, 0);

            break;
            }
         aux=aux->sig;
        }
    }

}

void AVL2::Agregar_En_AVL2(int ID, int carne, char *nombre, char *nota){
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){

            if(aux->ID==ID){
                NodoAVL *nuevo;
                nuevo=(nodoAVL*)malloc(sizeof(struct NodoAVL));
                nuevo->Carne=carne;
                nuevo->Nombre=nombre;
                nuevo->Nota=nota;
                nuevo->Altura=0;
                nuevo->fe=0;
                nuevo->Nivel=0;
                nuevo->izq=NULL;
                nuevo->der=NULL;
                nuevo->Contador=correlativo++;

                aux->RAIZ=Insertar(nuevo,aux->RAIZ);
                Ajustar_Fe(aux->RAIZ, 0);

            break;
            }
         aux=aux->sig;
        }
    }

    Graficar_AVL();
    Graficar_AVL_Individual(ID);
    Graficar_AVL_Individual2(ID);
}


void AVL2::Graficar_AVL(){

    gra2=fopen("ListaArboles.dot","wt");
    fputs("digraph g {\n ",gra2);
    fputs("node [\n" ,gra2);
    fputs("fontsize = \"10\"\n",gra2);
    fputs("shape = \"Mrecord\"\n",gra2);
    fputs("style =\"filled, bold\"\n",gra2);
    fputs("];\n",gra2);
    NodoD *aux=primeroD;
    if(aux!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra2);
    fputs("node [style=filled];\n",gra2);
    int a=1;

    while(aux!=NULL){
        fputs("\"",gra2);
        fputs("nodoD",gra2);
        fprintf(gra2,"%d",a);
        fputs("\"",gra2);
        fputs("\n[ ",gra2);
        fprintf(gra2, "label=\" " );
        fputs("ID: ",gra2);
        fprintf(gra2, "%d",aux->ID);
        fputs("&#92;n",gra2);
        fputs("Nombre: ",gra2);
        fprintf(gra2, "%s",aux->Nombre);
        fputs("&#92;n",gra2);
        fputs("Hora: ",gra2);
        fprintf(gra2, "%s",aux->Hora);
        fputs("&#92;n",gra2);
        fputs("Fecha: ",gra2);
        fprintf(gra2, "%s",aux->Fecha);
        fputs("\",fillcolor=cyan ];\n",gra2);


            Graficar_AVL(aux->RAIZ);


        a++;
        aux=aux->sig;
    }


    int b =1;
    int c =b+1;
    aux=primeroD;
    if(aux!=NULL){
         while(aux!=NULL){
            /// nodo1---->nodo2 siguintes
            if(aux!=ultimoD){
            fputs("\"nodoD",gra2);
            fprintf(gra2,"%d",b);
            fputs("\"-> \"nodoD",gra2);
            fprintf(gra2,"%d",c);
            fputs( "\";\n",gra2);

            fputs("\"nodoD",gra2);
            fprintf(gra2,"%d",c);
            fputs("\"-> \"nodoD",gra2);
            fprintf(gra2,"%d",b);
            fputs( "\";\n",gra2);

            fputs("\"nodoD",gra2);
            fprintf(gra2,"%d",b);
            fputs("\"-> \"nodo",gra2);
            fprintf(gra2,"%d",aux->RAIZ->Contador);
            fputs( "\";\n",gra2);

            }else{
                fputs("\"nodoD",gra2);
                fprintf(gra2,"%d",b);
                fputs("\"-> \"nodo",gra2);
                fprintf(gra2,"%d",aux->RAIZ->Contador);
                fputs( "\";\n",gra2);

             }


            b++;
            c++;
            aux=aux->sig;
        }
    }


    fputs("fontsize = \"10\"\n",gra2);
    fputs("shape = \"Mrecord\"\n",gra2);
    fputs("color=\"orange\"\n",gra2);
    fputs("style =\"filled, bold\"\n",gra2);
    fputs("label =\"Lista de Arboles\"\n",gra2);
    fputs("}\n",gra2);

 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra2);
        fputs("node [style=filled];\n",gra2);

        fputs("\"",gra2);
        fputs("nodoD",gra2);
        fputs("\"",gra2);
        fputs("\n[ ",gra2);
        fprintf(gra2, "label=\" Lista de Arboles " );
        fputs("\"];\n",gra2);

        fputs("fontsize = \"10\"\n",gra2);
        fputs("shape = \"Mrecord\"\n",gra2);
        fputs("color=\"orange\"\n",gra2);
        fputs("style =\"filled, bold\"\n",gra2);
        fputs("label =\"Niveles\"\n",gra2);
        fputs("}\n",gra2);

        printf("Lista esta Vacia...");


  }
 fputs("}",gra2);
 fclose(gra2);
 system("dot -Tpng ListaArboles.dot -o ListaArboles.png");

}


void AVL2::Graficar_AVL(NodoAVL *actual){
    if(actual != NULL)
    {
        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\" " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("\"];\n",gra2);

        }else{
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\"<C0>| " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("|<C1>\"];\n",gra2);

        }
        if(actual->izq!=NULL){
            Graficar_AVL(actual->izq);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C0->nodo",gra2);
            fprintf(gra2,"%d",actual->izq->Contador);
            fputs("\n",gra2);

        }
        if(actual->der!=NULL){
            Graficar_AVL(actual->der);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C1->nodo",gra2);
            fprintf(gra2,"%d",actual->der->Contador);
            fputs("\n",gra2);
        }

    }
}

void AVL2::Nodo_Info(){
    primeoI=(NodoI*)malloc(sizeof(struct NodoInfo));
    primeoI->Nivel=0;
    primeoI->Ramas=0;
    primeoI->Padres=0;
    primeoI->Hojas=0;
}

void AVL2::Info_AVL(nodoAVL *actual){
    if(actual!=NULL){
        if(actual->Nivel>primeoI->Nivel){
            primeoI->Nivel=actual->Nivel;
        }
        if(actual->izq!=NULL || actual->der!=NULL){
            primeoI->Padres++;
        }else if(actual->izq==NULL && actual->der==NULL){
            primeoI->Hojas++;
        }

        if(actual->izq!=NULL){
            primeoI->Ramas++;
           Info_AVL(actual->izq);
        }
        if(actual->der!=NULL){
            primeoI->Ramas++;
           Info_AVL(actual->der);
        }

    }
}


///****************+Graficar un Arbol de manera Individual**************
void AVL2::Graficar_AVL_Individual(int ID){
   // Recorrido_Amplitud(ID);
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                aux->seleccion=1;
                gra2=fopen("AVL.dot","wt");
                fputs("digraph g {\n ",gra2);
                fputs("node [\n" ,gra2);
                fputs("fontsize = \"10\"\n",gra2);
                fputs("shape = \"Mrecord\"\n",gra2);
                fputs("style =\"filled, bold\"\n",gra2);
                fputs("];\n",gra2);
                fputs("\n subgraph cluster_1 {\n",gra2);
                fputs("node [style=filled];\n",gra2);


                Graficar_AVL_Individual(aux->RAIZ);
                Nodo_Info();
                Info_AVL(aux->RAIZ);



                fputs("fontsize = \"12\"\n",gra2);
                fputs("shape = \"Mrecord\"\n",gra2);
                fputs("color=\"orange\"\n",gra2);
                fputs("style =\"filled, bold\"\n",gra2);

                fprintf(gra2, "label=\" " );
                fputs("Nombre: ",gra2);
                fprintf(gra2, "%s",aux->Nombre);
                fputs("&#92;n",gra2);
                fputs("Nivel: ",gra2);
                fprintf(gra2, "%d",primeoI->Nivel);
                fputs("&#92;n",gra2);
                fputs("Altura: ",gra2);
                fprintf(gra2, "%d",primeoI->Nivel+1);
                fputs("&#92;n",gra2);
                fputs("Ramas: ",gra2);
                fprintf(gra2, "%d",primeoI->Ramas);
                fputs("&#92;n",gra2);
                fputs("Nodos Padre: ",gra2);
                fprintf(gra2, "%d",primeoI->Padres);
                fputs("&#92;n",gra2);
                fputs("Nodos Hoja: ",gra2);
                fprintf(gra2, "%d",primeoI->Hojas);
                fputs("\"\n",gra2);


                fputs("}\n",gra2);
                fputs("}\n",gra2);
                fclose(gra2);
                system("dot -Tpng AVL.dot -o AVL.png");



            }else{
                aux->seleccion=0;
            }
         aux=aux->sig;
        }
    }
}

void AVL2::Graficar_AVL_Individual(NodoAVL *actual){
    if(actual != NULL)
    {
        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\" " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("FE: ",gra2);
            fprintf(gra2, "%d",actual->fe);
            fputs("&#92;n",gra2);
            fputs("Nivel: ",gra2);
            fprintf(gra2, "%d",actual->Nivel);
            fputs("\"];\n",gra2);

        }else{
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\"<C0>| " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("FE: ",gra2);
            fprintf(gra2, "%d",actual->fe);
            fputs("&#92;n",gra2);
            fputs("Nivel: ",gra2);
            fprintf(gra2, "%d",actual->Nivel);
            fputs("|<C1>\"];\n",gra2);

        }
        if(actual->izq!=NULL){
            Graficar_AVL_Individual(actual->izq);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C0->nodo",gra2);
            fprintf(gra2,"%d",actual->izq->Contador);
            fputs("\n",gra2);

        }
        if(actual->der!=NULL){
            Graficar_AVL_Individual(actual->der);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C1->nodo",gra2);
            fprintf(gra2,"%d",actual->der->Contador);
            fputs("\n",gra2);
        }

    }

}

///.........................................................
void AVL2::Graficar_AVL_Individual2(int ID){
    //Recorrido_Amplitud(ID);
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                aux->seleccion=1;
                gra2=fopen("AVL2.dot","wt");
                fputs("digraph g {\n ",gra2);
                fputs("node [\n" ,gra2);
                fputs("fontsize = \"10\"\n",gra2);
                fputs("shape = \"Mrecord\"\n",gra2);
                fputs("style =\"filled, bold\"\n",gra2);
                fputs("];\n",gra2);
                fputs("\n subgraph cluster_1 {\n",gra2);
                fputs("node [style=filled];\n",gra2);


                Graficar_AVL_Individual2(aux->RAIZ);

                fputs("fontsize = \"12\"\n",gra2);
                fputs("shape = \"Mrecord\"\n",gra2);
                fputs("color=\"orange\"\n",gra2);
                fputs("style =\"filled, bold\"\n",gra2);

                fputs("}\n",gra2);
                fputs("}\n",gra2);
                fclose(gra2);
                system("dot -Tpng AVL2.dot -o AVL2.png");


            }else{
                aux->seleccion=0;
            }
         aux=aux->sig;
        }
    }
}

void AVL2::Graficar_AVL_Individual2(NodoAVL *actual){
    if(actual != NULL)
    {
        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\" " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("\"];\n",gra2);

        }else{
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\"<C0>| " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("|<C1>\"];\n",gra2);

        }
        if(actual->izq!=NULL){
            Graficar_AVL_Individual2(actual->izq);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C0->nodo",gra2);
            fprintf(gra2,"%d",actual->izq->Contador);
            fputs("\n",gra2);

        }
        if(actual->der!=NULL){
            Graficar_AVL_Individual2(actual->der);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C1->nodo",gra2);
            fprintf(gra2,"%d",actual->der->Contador);
            fputs("\n",gra2);
        }

    }

}


///*****************Recorridos*******************************
QString AVL2::Mostrar_InOrden(int ID){
    InOrden="";
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){

              InOrden = Mostrar_InOrden(aux->RAIZ);
              int a =InOrden.length();
              InOrden.remove(a-2,2);

             break;
            }
         aux=aux->sig;
        }
    }
   return InOrden;
}

QString AVL2::Mostrar_InOrden(NodoAVL *actual){

    if(actual!=NULL){
        Mostrar_InOrden(actual->izq);
        InOrden+=QString::number(actual->Carne);
        InOrden+=" , ";
        Mostrar_InOrden(actual->der);
    }

    return InOrden;
}


QString AVL2::Mostrar_PosOrden(int ID){
    PosOrden="";
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){

               PosOrden = Mostrar_PosOrden(aux->RAIZ);
               int a =PosOrden.length();
               PosOrden.remove(a-2,2);

             break;
            }
         aux=aux->sig;
        }
    }
   return PosOrden;
}

QString AVL2::Mostrar_PosOrden(NodoAVL *actual){
    if(actual!=NULL){
        Mostrar_PosOrden(actual->izq);
        Mostrar_PosOrden(actual->der);
        PosOrden+=QString::number(actual->Carne);
        PosOrden+=" , ";
    }

    return PosOrden;
}


QString AVL2::Mostrar_PreOrden(int ID){
    PreOrden="";
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){


                PreOrden = Mostrar_PreOrden(aux->RAIZ);
                int a =PreOrden.length();
                PreOrden.remove(a-2,2);

             break;
            }
         aux=aux->sig;
        }
    }
   return PreOrden;
}

QString AVL2::Mostrar_PreOrden(NodoAVL *actual){
    if(actual!=NULL){
        PreOrden+=QString::number(actual->Carne);
        PreOrden+=" , ";
        Mostrar_PreOrden(actual->izq);
        Mostrar_PreOrden(actual->der);

    }

    return PreOrden;

}

///**************PUNTEROS PRIMERO Y ULTIMO DE LA COLA***************
typedef struct nodoCola NodoC;
NodoC *primeroc;
NodoC *ultimoc;

void AVL2::Agregar_Cola(int carne){
    NodoC *nuevo;
    nuevo=(NodoC*)malloc(sizeof(struct nodoCola));
    nuevo->carne=carne;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    if(primeroc==NULL){///Agregar el primer Nodo...
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        primeroc=nuevo;
        ultimoc=nuevo;

    }else{///Agregar un nodo al lado izquierdo......
        nuevo->ant=NULL;
        nuevo->sig=primeroc;
        primeroc->ant=nuevo;
        primeroc=nuevo;

    }

}




void AVL2::Eliminar_Cola(){
    if(primeroc==ultimoc){
        primeroc=NULL;
        ultimoc=NULL;
        cout<<"Se eliminio el ultimo de la Cola...."<<endl;
    }else{
        ultimoc->ant->sig=NULL;
        ultimoc=ultimoc->ant;

    }
}

QString AVL2::Recorrido_Amplitud(int ID){
    Amplitud="";
    primeroc=NULL;
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){

                Agregar_Cola(aux->RAIZ->Carne);
                Amplitud = Mostrar_Anchura(aux->RAIZ);
                int a =Amplitud.length();
                Amplitud.remove(a-2,2);


             break;
            }
         aux=aux->sig;
        }
    }
   return Amplitud;
}

QString AVL2::Mostrar_Anchura(nodoAVL *raiz){
    Amplitud="";

    if(primeroc!=NULL){


        while (primeroc!=NULL) {

            cout<<"Mostrar"<<endl;
            Amplitud = Mostrar_Anchura1(raiz);

        }

   }

    return Amplitud;
}

QString AVL2::Mostrar_Anchura1(NodoAVL *actual){
    if(actual!=NULL ){
     if(ultimoc!=NULL){
         cout<<"Ultimo"<<endl;
      if(actual->Carne==ultimoc->carne){

          cout<<"Recorrido.."<<actual->Carne<<endl;
          Amplitud +=QString::number(actual->Carne);
          Amplitud += " , ";
          if(primeroc!=NULL){
               Eliminar_Cola();
               cout<<"Eliminado"<<endl;
          }

          if(actual->izq!=NULL){
              Agregar_Cola(actual->izq->Carne);
          }
          if(actual->der!=NULL){
              Agregar_Cola(actual->der->Carne);
          }

      }
     }

     if(actual->izq!=NULL){
      cout<<"iz"<<endl;
      Mostrar_Anchura1(actual->izq);
     }

     if(actual->der!=NULL){
      cout<<"der"<<endl;
      Mostrar_Anchura1(actual->der);
     }

 }


  return Amplitud;
}

///*************Modificaciones del Arbol AVL*********************

void AVL2::Editar_AVL(int ID, int Carne, char *Nombre, char *Nota){
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                Recorrer_AVL(aux->RAIZ, Carne, Nombre, Nota);
                Graficar_AVL();
                Graficar_AVL_Individual2(ID);
             break;
            }
         aux=aux->sig;
        }
    }

}


void AVL2::Recorrer_AVL(NodoAVL *actual, int Carne, char *Nombre, char *Nota){
    if(actual!=NULL){

        if(actual->Carne==Carne){
            actual->Nombre=Nombre;
            actual->Nota=Nota;
        }

        if(actual->izq!=NULL){
            Recorrer_AVL(actual->izq, Carne, Nombre, Nota);
        }
        if(actual->der!=NULL){
            Recorrer_AVL(actual->der, Carne, Nombre, Nota);
        }

    }

}

///Obtener la Informacion del Nodo........
QString AVL2::Informacion_Nodo(int ID, int Carne){
    info="";
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                info=Recorrer_AVL_Info(aux->RAIZ,Carne);

            }
         aux=aux->sig;
        }
    }

    return info;
}

QString AVL2::Recorrer_AVL_Info(NodoAVL *actual,int Carne){

    if(actual!=NULL){

        if(actual->Carne==Carne){
            info+=actual->Nombre;
            info+=",";
            info+=actual->Nota;
            return info;
        }

        if(actual->izq!=NULL){
            Recorrer_AVL_Info(actual->izq, Carne);
        }
        if(actual->der!=NULL){
            Recorrer_AVL_Info(actual->der, Carne);
        }

    }

    return info;

}

///************Eliminar en Arbol AVL******************

void AVL2::Eliminar_AVL(int ID, int Carne){
    cout<<"ELIMINAR........"<<endl;
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                nodoAVL *auxiliar=aux->RAIZ;
                nodoAVL *padre=aux->RAIZ;
                bool Izquierdo=true;
                while(auxiliar->Carne!=Carne){
                    padre=auxiliar;
                    if(Carne<auxiliar->Carne){
                        Izquierdo=true;
                        auxiliar=auxiliar->izq;
                    }else{
                        Izquierdo=false;
                        auxiliar=auxiliar->der;
                    }


                }//FIN While


                if(auxiliar->izq==NULL && auxiliar->der==NULL){
                    if(auxiliar==aux->RAIZ){
                        aux->RAIZ=NULL;
                    }else if(Izquierdo){
                        padre->izq=NULL;
                    }else{
                        padre->der=NULL;
                    }
                }else if(auxiliar->der==NULL){
                    if(auxiliar==aux->RAIZ){
                        aux->RAIZ=auxiliar->izq;
                    }else if(Izquierdo){
                        padre->izq=auxiliar->izq;
                    }else{
                        padre->der=auxiliar->izq;
                    }
                }else if(auxiliar->izq==NULL){
                    if(auxiliar==aux->RAIZ){
                        aux->RAIZ=auxiliar->der;
                    }else if(Izquierdo){
                        padre->izq=auxiliar->der;
                    }else{
                        padre->der=auxiliar->izq;
                    }
                }else{
                    nodoAVL *reemplazo=Obtener_Reemplazo(auxiliar);
                    if(auxiliar==aux->RAIZ){
                        aux->RAIZ=reemplazo;
                    }else if(Izquierdo){
                        padre->izq=reemplazo;
                    }else{
                        padre->der=reemplazo;
                    }
                    reemplazo->izq=auxiliar->izq;
                }

                cout<<"Padre.."<<padre->Nombre<<" Hijo.."<<auxiliar->Nombre<<endl;

                padre->fe=Altura(padre->der)-Altura(padre->izq);
                padre->Altura = Mayor(Altura(padre->izq), Altura(padre->der)) + 1;
                Ajustar_Fe(aux->RAIZ,0);
                Ajustar_Fe(aux->RAIZ,0);


            }
         aux=aux->sig;
        }
    }
    Graficar_AVL();
    Graficar_AVL_Individual2(ID);
}

///**********Graficar Sub-Arbol***********************
void AVL2::Graficar_Sub_Arbol(int ID, int carne){
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(aux->ID==ID){
                Graficar_Sub_Arbol2(aux->RAIZ,carne);
             break;
            }
         aux=aux->sig;
        }
    }
}

bool AVL2::Graficar_Sub_Arbol2(NodoAVL *actual, int carne){
    if(actual!=NULL){

        if(actual->Carne==carne){
            gra2=fopen("SubArbol.dot","wt");
            fputs("digraph g {\n ",gra2);
            fputs("node [\n" ,gra2);
            fputs("fontsize = \"10\"\n",gra2);
            fputs("shape = \"Mrecord\"\n",gra2);
            fputs("style =\"filled, bold\"\n",gra2);
            fputs("];\n",gra2);
            fputs("\n subgraph cluster_1 {\n",gra2);
            fputs("node [style=filled];\n",gra2);

            Graficar_Sub_Arbol(actual);

            fputs("fontsize = \"12\"\n",gra2);
            fputs("shape = \"Mrecord\"\n",gra2);
            fputs("color=\"orange\"\n",gra2);
            fputs("style =\"filled, bold\"\n",gra2);

            fputs("}\n",gra2);
            fputs("}\n",gra2);
            fclose(gra2);
            system("dot -Tpng SubArbol.dot -o SubArbol.png");



          return true;
        }

        if(actual->izq!=NULL){
            Graficar_Sub_Arbol2(actual->izq, carne);
        }
        if(actual->der!=NULL){
            Graficar_Sub_Arbol2(actual->der, carne);
        }

    }

    return false;

}

void AVL2::Graficar_Sub_Arbol(NodoAVL *actual){
    if(actual != NULL)
    {
        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\" " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("\"];\n",gra2);

        }else{
            fputs("\"",gra2);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs("\"",gra2);
            fputs("[ ",gra2);
            fprintf(gra2, "label=\"<C0>| " );
            fputs("Carne: ",gra2);
            fprintf(gra2, "%d",actual->Carne);
            fputs("&#92;n",gra2);
            fputs("Nombre: ",gra2);
            fprintf(gra2, "%s",actual->Nombre);
            fputs("&#92;n",gra2);
            fputs("Nota: ",gra2);
            fprintf(gra2, "%s",actual->Nota);
            fputs("|<C1>\"];\n",gra2);

        }
        if(actual->izq!=NULL){
            Graficar_Sub_Arbol(actual->izq);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C0->nodo",gra2);
            fprintf(gra2,"%d",actual->izq->Contador);
            fputs("\n",gra2);

        }
        if(actual->der!=NULL){
            Graficar_Sub_Arbol(actual->der);
            fputs("nodo",gra2);
            fprintf(gra2,"%d",actual->Contador);
            fputs(":C1->nodo",gra2);
            fprintf(gra2,"%d",actual->der->Contador);
            fputs("\n",gra2);
        }

    }
}

///******************Bloque***********************************

QString AVL2::Crear_Bloque(char *Nombre){
    LLave="";
    JSON="";
    pre="";
    pos="";
    in="";
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while (aux!=NULL) {
            if(strcmp(aux->Nombre,Nombre)==0){
                JSON.append("{ \n \"tipo-operacion\":1,\n");
                JSON.append("\"nombre\":\"");
                JSON.append(aux->Nombre);
                JSON.append("\",\n");
                JSON.append("\"llave-unica\":\"<");

                LLave = Crear_LLave(aux->RAIZ);

                int n=LLave.length();
                LLave.remove(n-2,2);///llave...
                JSON.append(LLave);
                JSON.append(">\",\n");

                JSON.append("\"pre-orden\":[\n");

                pre=Pre_Orden(aux->RAIZ);
                int a=pre.length();
                pre.remove(a-2,2);
                JSON.append(pre);
                JSON.append("\n],\n");

                JSON.append("\"post-orden\":[\n");

                pos=Pos_Orden(aux->RAIZ);
                int b=pos.length();
                pos.remove(b-2,2);
                JSON.append(pos);
                JSON.append("\n],\n");

                JSON.append("\"in-orden\":[\n");

                in=In_Orden(aux->RAIZ);
                int c=in.length();
                in.remove(c-2,2);
                JSON.append(in);
                JSON.append("\n]\n}");

               //  cout<<"JSON...\n"<<JSON.toStdString()<<endl;

             break;
            }
         aux=aux->sig;
        }
    }

   return JSON;
}

QString AVL2::Crear_LLave(NodoAVL *actual){
    if(actual!=NULL){

        if(actual->izq!=NULL){
            Crear_LLave(actual->izq);
         }

        LLave.append(QString::number(actual->Carne));
        LLave.append(",");
        LLave.append(actual->Nombre);
        LLave.append(",");
        LLave.append(actual->Nota);
        LLave.append("&&");


        if(actual->der!=NULL){
            Crear_LLave(actual->der);
          }
    }
    return LLave;
}

QString AVL2::In_Orden(NodoAVL *actual){
    if(actual!=NULL){

        if(actual->izq!=NULL){
            In_Orden(actual->izq);
         }
        in.append("{");
        in.append("\"carnet\":");
        in.append(QString::number(actual->Carne));
        in.append(",");
        in.append("\"Nombre\":\"");
        in.append(actual->Nombre);
        in.append("\",");
        in.append("\"Nota\":");
        in.append(actual->Nota);
        in.append("},\n");



        if(actual->der!=NULL){
            In_Orden(actual->der);
          }
    }
    return in;
}

QString AVL2::Pos_Orden(NodoAVL *actual){
    if(actual!=NULL){

        if(actual->izq!=NULL){
            Pos_Orden(actual->izq);
         }

        if(actual->der!=NULL){
            Pos_Orden(actual->der);
          }

        pos.append("{");
        pos.append("\"carnet\":");
        pos.append(QString::number(actual->Carne));
        pos.append(",");
        pos.append("\"Nombre\":\"");
        pos.append(actual->Nombre);
        pos.append("\",");
        pos.append("\"Nota\":");
        pos.append(actual->Nota);
        pos.append("},\n");
    }
    return pos;
}

QString AVL2::Pre_Orden(NodoAVL *actual){
    if(actual!=NULL){

        pre.append("{");
        pre.append("\"carnet\":");
        pre.append(QString::number(actual->Carne));
        pre.append(",");
        pre.append("\"Nombre\":\"");
        pre.append(actual->Nombre);
        pre.append("\",");
        pre.append("\"Nota\":");
        pre.append(actual->Nota);
        pre.append("},\n");

        if(actual->izq!=NULL){
            Pre_Orden(actual->izq);
         }

        if(actual->der!=NULL){
            Pre_Orden(actual->der);
          }

    }
    return pre;
}
