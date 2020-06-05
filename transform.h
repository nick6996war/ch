#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>

extern int peretvor;
namespace Ui {
class Transform;
}

class Transform : public QWidget
{
    Q_OBJECT

public:
    explicit Transform(QWidget *parent = 0);
    ~Transform();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
