#include "transform.h"
#include "ui_transform.h"
int peretvor;
Transform::Transform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transform)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setMinimumSize(400,200);
    ui->graphicsView->setMaximumSize(400,200);

    scene->addPixmap(QPixmap("C:/Users/salim/Desktop/figurs/vubir.bmp"));
}

Transform::~Transform()
{
    delete ui;
}


void Transform::on_pushButton_clicked()
{
    peretvor=1;
    this->~Transform();
}

void Transform::on_pushButton_3_clicked()
{
    peretvor=4;
    this->~Transform();
}

void Transform::on_pushButton_4_clicked()
{
    peretvor=2;
    this->~Transform();
}

void Transform::on_pushButton_2_clicked()
{
    peretvor=3;
    this->~Transform();
}
