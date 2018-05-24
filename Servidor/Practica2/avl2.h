#ifndef AVL2_H
#define AVL2_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

struct NodoInfo
{
   int Nivel;
   int Ramas;
   int Padres;
   int Hojas;
};

struct nodoCola{
    int carne;
    struct nodoCola *sig;
    struct nodoCola *ant;
};

///**************NODO ARBOL AVL***************************
struct NodoAVL{
    int Carne;
    char *Nombre;
    char *Nota;
    struct NodoAVL *izq;
    struct NodoAVL *der;
    int Altura;
    int fe;
    int Nivel;
    int Contador;
};

///**************Nodo Pibote de cada Arbol AVL...
struct NodoDoble{
    int ID;
    char *Nombre;
    char *Hora;
    char *Fecha;
    int seleccion;
    struct NodoDoble *sig;
    struct NodoDoble *ant;
    struct NodoAVL *RAIZ;

};

class AVL2 : public QObject
{
    Q_OBJECT
public:
    explicit AVL2(QObject *parent = nullptr);
    void SayHello(QString json);
    void Conectar();
    void Leer_JSON2(QString json);

    ///*************METODOS DEL ARBOL AVL*********************

    void Insertar(char *nombre);
    NodoAVL *Insertar(NodoAVL *nuevo, NodoAVL *actual);
    NodoAVL *Buscar(char *nombre, NodoAVL *actual);
    void Graficar_AVL();
    void Graficar_AVL(NodoAVL *actual);
    void Graficar_AVL_Individual(int ID);
    void Graficar_AVL_Individual(NodoAVL *actual);
    void Graficar_AVL_Individual2(int ID);
    void Graficar_AVL_Individual2(NodoAVL *actual);
    void Graficar_Sub_Arbol(int ID, int carne);
    bool Graficar_Sub_Arbol2(NodoAVL *actual, int carne);
    void Graficar_Sub_Arbol(NodoAVL *actual);
    int Factor_Equilibrio(NodoAVL *actual);
    void Ajustar_Fe(NodoAVL *actual, int Nivel);
    void Equilibrar_AVL(NodoAVL *actual);
    NodoAVL *Obtener_Reemplazo(NodoAVL *reemp);
    NodoAVL *Izquierda(NodoAVL *actual);
    NodoAVL *Derecha(NodoAVL *actual);
    NodoAVL *IzquierdaDerecha(NodoAVL *actual);
    NodoAVL *DerechaIzquierda(NodoAVL *actual);
    FILE *gra2;

    QString Mostrar_InOrden(int ID);
    QString Mostrar_InOrden(NodoAVL *actual);
    QString Mostrar_PreOrden(int ID);
    QString Mostrar_PreOrden(NodoAVL *actual);
    QString Mostrar_PosOrden(int ID);
    QString Mostrar_PosOrden(NodoAVL *actual);
    QString Mostrar_Anchura(NodoAVL *actual);
    QString Mostrar_Anchura1(NodoAVL *actual);
    QString Recorrido_Amplitud(int ID);
    void Agregar_Cola(int carne);
    void Eliminar_Cola();

    void Eliminar_AVL(int ID, int Carne);
    void Agregar_En_AVL(char *archivo, int carne, char *nombre, char *nota);
    void Agregar_En_AVL2(int ID, int carne, char* nombre, char *nota);
    void Nodo_Info();
    void Info_AVL(NodoAVL *actual);

    void Editar_AVL(int ID, int Carne, char *Nombre, char *Nota);
    void Recorrer_AVL(NodoAVL *actual, int Carne, char *Nombre, char *Nota);

    QString Informacion_Nodo(int ID, int Carne);
    QString Recorrer_AVL_Info(NodoAVL *actual, int Carne);

    QString Crear_Bloque(char *Nombre);
    QString Crear_LLave(NodoAVL *actual);
    QString In_Orden(NodoAVL *actual);
    QString Pos_Orden(NodoAVL *actual);
    QString Pre_Orden(NodoAVL *actual);

    ///*************Metodos de la Lista Doble........

    int contador=1;
    void Agregar_Lista_Doble(char *Nombre, char *hora, char *fecha);
    void Graficar_Lista_Doble();
    bool Buscar_Arbol(char *Nombre, char *hora, char *fecha);

    void Leer_JSON(QString json);


signals:
    void Emitir_Nombre_JSON(char *nombre);

public slots:
    void readyRead();

private:
     QUdpSocket *socket;

};



#endif // AVL2_H
