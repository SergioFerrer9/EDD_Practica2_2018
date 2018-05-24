#ifndef JSON_H
#define JSON_H


#include <QMainWindow>

namespace Ui {
class JSON;
}

class JSON : public QMainWindow
{
    Q_OBJECT

public:
    explicit JSON(QWidget *parent = 0);
    void setJSON(QString json);
    ~JSON();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::JSON *ui;
};

#endif // JSON_H
