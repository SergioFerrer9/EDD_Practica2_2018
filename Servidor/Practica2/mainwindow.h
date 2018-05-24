#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QStandarItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Cargar_Archivo();
    void Mostrar_Lista_Arboles();
    void Mostrar_Lista();
    void Mostrar_Arbol();
    void setNombre(char *Nombre);
    void setNombre2(QString Nombre);

    ~MainWindow();

private slots:
    void on_actionCargar_Archivo_triggered();

    void on_actionInOrden_triggered();

    void on_actionPostOrden_triggered();

    void on_actionPreOrden_triggered();

    void on_actionAmplitud_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_actionLlave_Unica_triggered();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
