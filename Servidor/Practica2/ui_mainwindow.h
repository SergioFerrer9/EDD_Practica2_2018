/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_Archivo;
    QAction *actionInOrden;
    QAction *actionPostOrden;
    QAction *actionPreOrden;
    QAction *actionAmplitud;
    QAction *actionLlave_Unica;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuRecorridos;
    QMenu *menuBloque;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1235, 619);
        actionCargar_Archivo = new QAction(MainWindow);
        actionCargar_Archivo->setObjectName(QStringLiteral("actionCargar_Archivo"));
        actionInOrden = new QAction(MainWindow);
        actionInOrden->setObjectName(QStringLiteral("actionInOrden"));
        actionPostOrden = new QAction(MainWindow);
        actionPostOrden->setObjectName(QStringLiteral("actionPostOrden"));
        actionPreOrden = new QAction(MainWindow);
        actionPreOrden->setObjectName(QStringLiteral("actionPreOrden"));
        actionAmplitud = new QAction(MainWindow);
        actionAmplitud->setObjectName(QStringLiteral("actionAmplitud"));
        actionLlave_Unica = new QAction(MainWindow);
        actionLlave_Unica->setObjectName(QStringLiteral("actionLlave_Unica"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1050, 220, 111, 23));
        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(730, 10, 251, 491));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 249, 489));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1010, 50, 181, 25));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 560, 59, 21));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1010, 10, 181, 25));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 510, 971, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1050, 250, 111, 23));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(1010, 90, 181, 25));
        gridLayout_5 = new QGridLayout(layoutWidget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 0, 1, 1, 1);

        layoutWidget_3 = new QWidget(centralWidget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(1010, 130, 181, 25));
        gridLayout_6 = new QGridLayout(layoutWidget_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_6->addWidget(lineEdit_4, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1050, 300, 111, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1050, 330, 111, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1050, 360, 111, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1050, 390, 111, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 721, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 697, 452));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        scrollArea_3 = new QScrollArea(tab_2);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 697, 452));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_8 = new QLabel(scrollAreaWidgetContents_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_9->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1050, 170, 111, 23));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1050, 470, 111, 23));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(1050, 510, 111, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1235, 20));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuRecorridos = new QMenu(menuMenu);
        menuRecorridos->setObjectName(QStringLiteral("menuRecorridos"));
        menuBloque = new QMenu(menuBar);
        menuBloque->setObjectName(QStringLiteral("menuBloque"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuBloque->menuAction());
        menuMenu->addAction(actionCargar_Archivo);
        menuMenu->addAction(menuRecorridos->menuAction());
        menuRecorridos->addAction(actionInOrden);
        menuRecorridos->addAction(actionPostOrden);
        menuRecorridos->addAction(actionPreOrden);
        menuRecorridos->addAction(actionAmplitud);
        menuBloque->addAction(actionLlave_Unica);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Practica2", nullptr));
        actionCargar_Archivo->setText(QApplication::translate("MainWindow", "Cargar", nullptr));
        actionInOrden->setText(QApplication::translate("MainWindow", "InOrden", nullptr));
        actionPostOrden->setText(QApplication::translate("MainWindow", "PostOrden", nullptr));
        actionPreOrden->setText(QApplication::translate("MainWindow", "PreOrden", nullptr));
        actionAmplitud->setText(QApplication::translate("MainWindow", "Amplitud", nullptr));
        actionLlave_Unica->setText(QApplication::translate("MainWindow", "Crear Bloque", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Lista de Arboles", nullptr));
        label_2->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Clave    ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Recorrido", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "ID Arbol", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Arbol Individual", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Nombre", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Nota     ", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Editar", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Eliminar", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Agregar", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Sub-Arbol", nullptr));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        label_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Info. Nodo", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "Enviar JSON", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
        menuRecorridos->setTitle(QApplication::translate("MainWindow", "Recorridos", nullptr));
        menuBloque->setTitle(QApplication::translate("MainWindow", "Bloque", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
