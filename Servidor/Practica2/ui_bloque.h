/********************************************************************************
** Form generated from reading UI file 'bloque.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOQUE_H
#define UI_BLOQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bloque
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *Bloque)
    {
        if (Bloque->objectName().isEmpty())
            Bloque->setObjectName(QStringLiteral("Bloque"));
        Bloque->resize(372, 116);
        centralwidget = new QWidget(Bloque);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(12, 40, 351, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 70, 80, 23));
        Bloque->setCentralWidget(centralwidget);

        retranslateUi(Bloque);

        QMetaObject::connectSlotsByName(Bloque);
    } // setupUi

    void retranslateUi(QMainWindow *Bloque)
    {
        Bloque->setWindowTitle(QApplication::translate("Bloque", "Bloque", nullptr));
        pushButton->setText(QApplication::translate("Bloque", "Aceptar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bloque: public Ui_Bloque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOQUE_H
