#ifndef SUBARBOL_H
#define SUBARBOL_H

#include <QMainWindow>

namespace Ui {
class Subarbol;
}

class Subarbol : public QMainWindow
{
    Q_OBJECT

public:
    explicit Subarbol(QWidget *parent = 0);
    ~Subarbol();

private:
    Ui::Subarbol *ui;

public:
    void Setear();
};

#endif // SUBARBOL_H
