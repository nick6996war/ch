#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <cmath>
#include <cstdlib>
#include <QMessageBox>


extern int Pole[8][8];
extern bool rok[2];
bool FromTo(int xfrom,int yfrom,int xto,int yto);
class figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int clas;
    figure(int);
    ~figure();
    void moveto(QPointF);
    bool put(int,int);
    bool FromTo(int xfrom,int yfrom,int xto,int yto,bool temp);
    void transfer(int,int);
signals:

private:
    bool check(int,int,int,int);
    QPointF from;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // FIGURE_H
