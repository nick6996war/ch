#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure.h"
#include <QGraphicsScene>
#include <QTimer>
#include "transform.h"

extern int Pole[8][8];

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsScene *scene = new QGraphicsScene;
    bool peIIIka[16];
    bool isFigur[32];
    Ui::MainWindow *ui;
    figure *peIIIka1 = new figure(1);
    figure *peIIIka2 = new figure(1);
    figure *peIIIka3 = new figure(1);
    figure *peIIIka4 = new figure(1);
    figure *peIIIka5 = new figure(1);
    figure *peIIIka6 = new figure(1);
    figure *peIIIka7 = new figure(1);
    figure *peIIIka8 = new figure(1);
    figure *dama = new figure(5);
    figure *korol = new figure(6);
    figure *offecer1 = new figure(4);
    figure *offecer2 = new figure(4);
    figure *konb1 = new figure(3);
    figure *konb2 = new figure(3);
    figure *slon1 = new figure(2);
    figure *slon2 = new figure(2);
    figure *PeIIIka1 = new figure(11);
    figure *PeIIIka2 = new figure(11);
    figure *PeIIIka3 = new figure(11);
    figure *PeIIIka4 = new figure(11);
    figure *PeIIIka5 = new figure(11);
    figure *PeIIIka6 = new figure(11);
    figure *PeIIIka7 = new figure(11);
    figure *PeIIIka8 = new figure(11);
    figure *Dama = new figure(15);
    figure *Korol = new figure(16);
    figure *Offecer1 = new figure(14);
    figure *Offecer2 = new figure(14);
    figure *Konb1 = new figure(13);
    figure *Konb2 = new figure(13);
    figure *Slon1 = new figure(12);
    figure *Slon2 = new figure(12);
    void peret();
public slots:
        void updatea();
private slots:
        void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
