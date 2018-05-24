#ifndef BLOQUE_H
#define BLOQUE_H

#include <QMainWindow>

namespace Ui {
class Bloque;
}

class Bloque : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bloque(QWidget *parent = 0);
    ~Bloque();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bloque *ui;
};

#endif // BLOQUE_H
