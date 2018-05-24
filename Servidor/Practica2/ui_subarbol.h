/********************************************************************************
** Form generated from reading UI file 'subarbol.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBARBOL_H
#define UI_SUBARBOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subarbol
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Subarbol)
    {
        if (Subarbol->objectName().isEmpty())
            Subarbol->setObjectName(QStringLiteral("Subarbol"));
        Subarbol->resize(759, 523);
        centralwidget = new QWidget(Subarbol);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 741, 481));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 479));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        Subarbol->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Subarbol);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 759, 20));
        Subarbol->setMenuBar(menubar);

        retranslateUi(Subarbol);

        QMetaObject::connectSlotsByName(Subarbol);
    } // setupUi

    void retranslateUi(QMainWindow *Subarbol)
    {
        Subarbol->setWindowTitle(QApplication::translate("Subarbol", "Sub-Arbol", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Subarbol: public Ui_Subarbol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBARBOL_H
