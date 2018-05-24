/********************************************************************************
** Form generated from reading UI file 'json.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSON_H
#define UI_JSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JSON
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *JSON)
    {
        if (JSON->objectName().isEmpty())
            JSON->setObjectName(QStringLiteral("JSON"));
        JSON->resize(427, 127);
        centralwidget = new QWidget(JSON);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 0, 181, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 40, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 40, 80, 23));
        JSON->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JSON);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 427, 20));
        JSON->setMenuBar(menubar);

        retranslateUi(JSON);

        QMetaObject::connectSlotsByName(JSON);
    } // setupUi

    void retranslateUi(QMainWindow *JSON)
    {
        JSON->setWindowTitle(QApplication::translate("JSON", "Enviar JSON", nullptr));
        label->setText(QApplication::translate("JSON", "Desea Enviar el JSON", nullptr));
        pushButton->setText(QApplication::translate("JSON", "Enviar", nullptr));
        pushButton_2->setText(QApplication::translate("JSON", "Canselar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JSON: public Ui_JSON {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSON_H
