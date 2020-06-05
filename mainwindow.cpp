#include "mainwindow.h"
#include "ui_mainwindow.h"

extern int Pole[8][8];
int Temp[8][8];
extern int peretvor;
extern bool rok[2];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    for (int i=0;i<16;i++)
        peIIIka[i]=false;
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++)
            Temp[i][j]=Pole[i][j];
    peIIIka1->moveto(QPointF(0,6));
    peIIIka2->moveto(QPointF(1,6));
    peIIIka3->moveto(QPointF(2,6));
    peIIIka4->moveto(QPointF(3,6));
    peIIIka5->moveto(QPointF(4,6));
    peIIIka6->moveto(QPointF(5,6));
    peIIIka7->moveto(QPointF(6,6));
    peIIIka8->moveto(QPointF(7,6));

    PeIIIka1->moveto(QPointF(0,1));
    PeIIIka2->moveto(QPointF(1,1));
    PeIIIka3->moveto(QPointF(2,1));
    PeIIIka4->moveto(QPointF(3,1));
    PeIIIka5->moveto(QPointF(4,1));
    PeIIIka6->moveto(QPointF(5,1));
    PeIIIka7->moveto(QPointF(6,1));
    PeIIIka8->moveto(QPointF(7,1));

    Slon1->moveto(QPointF(0,0));
    Konb1->moveto(QPointF(1,0));
    Offecer1->moveto(QPointF(2,0));
    Dama->moveto(QPointF(3,0));
    Korol->moveto(QPointF(4,0));
    Offecer2->moveto(QPointF(5,0));
    Konb2->moveto(QPointF(6,0));
    Slon2->moveto(QPointF(7,0));

    slon1->moveto(QPointF(0,7));
    konb1->moveto(QPointF(1,7));
    offecer1->moveto(QPointF(2,7));
    dama->moveto(QPointF(3,7));
    korol->moveto(QPointF(4,7));
    offecer2->moveto(QPointF(5,7));
    konb2->moveto(QPointF(6,7));
    slon2->moveto(QPointF(7,7));

    ui->graphicsView->setMinimumSize(620,620);
    ui->graphicsView->setMaximumSize(620,620);
    QGraphicsPixmapItem *board =
            scene->addPixmap(QPixmap("C:/Users/salim/Desktop/1234.jpg"));
    scene->addItem(PeIIIka1);
    scene->addItem(PeIIIka2);
    scene->addItem(PeIIIka3);
    scene->addItem(PeIIIka4);
    scene->addItem(PeIIIka5);
    scene->addItem(PeIIIka6);
    scene->addItem(PeIIIka7);
    scene->addItem(PeIIIka8);

    scene->addItem(Slon1);
    scene->addItem(Slon2);
    scene->addItem(Dama);
    scene->addItem(Korol);
    scene->addItem(Offecer1);
    scene->addItem(Offecer2);
    scene->addItem(Konb1);
    scene->addItem(Konb2);

    scene->addItem(peIIIka1);
    scene->addItem(peIIIka2);
    scene->addItem(peIIIka3);
    scene->addItem(peIIIka4);
    scene->addItem(peIIIka5);
    scene->addItem(peIIIka6);
    scene->addItem(peIIIka7);
    scene->addItem(peIIIka8);

    scene->addItem(slon1);
    scene->addItem(slon2);
    scene->addItem(dama);
    scene->addItem(korol);
    scene->addItem(offecer1);
    scene->addItem(offecer2);
    scene->addItem(konb1);
    scene->addItem(konb2);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updatea()));
    timer->start(100);
}
bool flag2=false;
int jj=-1;
int ii;
void MainWindow::peret()
{
    int j=-1;
    int i;
    if (!flag2)
    {
    for (i=0;i<8;i++)
    {
        if (Pole[i][0]==10)
        {
            flag2=true;
            j=0;
            break;
        }
        if (Pole[i][7]==20)
        {
            flag2=true;
            j=7;
            break;
        }
    }

    if (j!=-1&&flag2)
    {
        ii=i;
        jj=j;
        Transform *wind=new Transform;
        wind->show();
    }
    }
    if (ii!=-1&&peretvor!=0)
    {
        i=ii;
        j=jj;
        flag2=false;
        if ((!isFigur[0])&&(!peIIIka[0])&&((PeIIIka1->pos().x()-60)/68==i)&&((PeIIIka1->pos().y()-60)/68==j))
        {
            peIIIka[0]=true;
            delete PeIIIka1;
            if (peretvor==1)
            {
                PeIIIka1 = new figure(12);
                scene->addItem(PeIIIka1);
                PeIIIka1->moveto(QPointF(i,j));
                Pole[i][j]=21;
            }else if (peretvor==2)
            {
                PeIIIka1 = new figure(13);
                scene->addItem(PeIIIka1);
                PeIIIka1->moveto(QPointF(i,j));
                Pole[i][j]=22;
            }else if (peretvor==3)
            {
                PeIIIka1 = new figure(14);
                scene->addItem(PeIIIka1);
                PeIIIka1->moveto(QPointF(i,j));
                Pole[i][j]=23;
            }else if (peretvor==4)
            {
                PeIIIka1 = new figure(15);
                scene->addItem(PeIIIka1);
                PeIIIka1->moveto(QPointF(i,j));
                Pole[i][j]=24;
            }
        }
        if ((!isFigur[1])&&(!peIIIka[1])&&((PeIIIka2->pos().x()-60)/68==i)&&((PeIIIka2->pos().y()-60)/68==j))
                {
                    peIIIka[1]=true;
                    delete PeIIIka2;
                    if (peretvor==1)
                    {
                        PeIIIka2 = new figure(12);
                        scene->addItem(PeIIIka2);
                        PeIIIka2->moveto(QPointF(i,j));
                        Pole[i][j]=21;
                    }else if (peretvor==2)
                    {
                        PeIIIka2 = new figure(13);
                        scene->addItem(PeIIIka2);
                        PeIIIka2->moveto(QPointF(i,j));
                        Pole[i][j]=22;
                    }else if (peretvor==3)
                    {
                        PeIIIka2 = new figure(14);
                        scene->addItem(PeIIIka2);
                        PeIIIka2->moveto(QPointF(i,j));
                        Pole[i][j]=23;
                    }else if (peretvor==4)
                    {
                        PeIIIka2 = new figure(15);
                        scene->addItem(PeIIIka2);
                        PeIIIka2->moveto(QPointF(i,j));
                        Pole[i][j]=24;
                    }
        }
        if ((!isFigur[2])&&(!peIIIka[2])&&((PeIIIka3->pos().x()-60)/68==i)&&((PeIIIka3->pos().y()-60)/68==j))
                        {
                            peIIIka[2]=true;
                            delete PeIIIka3;
                            if (peretvor==1)
                            {
                                PeIIIka3 = new figure(12);
                                scene->addItem(PeIIIka3);
                                PeIIIka3->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka3 = new figure(13);
                                scene->addItem(PeIIIka3);
                                PeIIIka3->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka3 = new figure(14);
                                scene->addItem(PeIIIka3);
                                PeIIIka3->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka3 = new figure(15);
                                scene->addItem(PeIIIka3);
                                PeIIIka3->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }

        if ((!isFigur[3])&&(!peIIIka[3])&&((PeIIIka4->pos().x()-60)/68==i)&&((PeIIIka4->pos().y()-60)/68==j))
                        {
                            peIIIka[3]=true;
                            delete PeIIIka4;
                            if (peretvor==1)
                            {
                                PeIIIka4 = new figure(12);
                                scene->addItem(PeIIIka4);
                                PeIIIka4->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka4 = new figure(13);
                                scene->addItem(PeIIIka4);
                                PeIIIka4->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka4 = new figure(14);
                                scene->addItem(PeIIIka4);
                                PeIIIka4->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka4 = new figure(15);
                                scene->addItem(PeIIIka4);
                                PeIIIka4->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }
        if ((!isFigur[4])&&(!peIIIka[4])&&((PeIIIka5->pos().x()-60)/68==i)&&((PeIIIka5->pos().y()-60)/68==j))
                        {
                            peIIIka[4]=true;
                            delete PeIIIka5;
                            if (peretvor==1)
                            {
                                PeIIIka5 = new figure(12);
                                scene->addItem(PeIIIka5);
                                PeIIIka5->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka5 = new figure(13);
                                scene->addItem(PeIIIka5);
                                PeIIIka5->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka5 = new figure(14);
                                scene->addItem(PeIIIka5);
                                PeIIIka5->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka5 = new figure(15);
                                scene->addItem(PeIIIka5);
                                PeIIIka5->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }
        if ((!isFigur[5])&&(!peIIIka[5])&&((PeIIIka6->pos().x()-60)/68==i)&&((PeIIIka6->pos().y()-60)/68==j))
                        {
                            peIIIka[5]=true;
                            delete PeIIIka6;
                            if (peretvor==1)
                            {
                                PeIIIka6 = new figure(12);
                                scene->addItem(PeIIIka6);
                                PeIIIka6->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka6 = new figure(13);
                                scene->addItem(PeIIIka6);
                                PeIIIka6->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka6 = new figure(14);
                                scene->addItem(PeIIIka6);
                                PeIIIka6->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka6 = new figure(15);
                                scene->addItem(PeIIIka6);
                                PeIIIka6->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }
        if ((!isFigur[6])&&(!peIIIka[6])&&((PeIIIka7->pos().x()-60)/68==i)&&((PeIIIka7->pos().y()-60)/68==j))
                        {
                            peIIIka[6]=true;
                            delete PeIIIka7;
                            if (peretvor==1)
                            {
                                PeIIIka7 = new figure(12);
                                scene->addItem(PeIIIka7);
                                PeIIIka7->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka7 = new figure(13);
                                scene->addItem(PeIIIka7);
                                PeIIIka7->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka7 = new figure(14);
                                scene->addItem(PeIIIka7);
                                PeIIIka7->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka7 = new figure(15);
                                scene->addItem(PeIIIka7);
                                PeIIIka7->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }
        if ((!isFigur[7])&&(!peIIIka[7])&&((PeIIIka8->pos().x()-60)/68==i)&&((PeIIIka8->pos().y()-60)/68==j))
                        {
                            peIIIka[7]=true;
                            delete PeIIIka8;
                            if (peretvor==1)
                            {
                                PeIIIka8 = new figure(12);
                                scene->addItem(PeIIIka8);
                                PeIIIka8->moveto(QPointF(i,j));
                                Pole[i][j]=21;
                            }else if (peretvor==2)
                            {
                                PeIIIka8 = new figure(13);
                                scene->addItem(PeIIIka8);
                                PeIIIka8->moveto(QPointF(i,j));
                                Pole[i][j]=22;
                            }else if (peretvor==3)
                            {
                                PeIIIka8 = new figure(14);
                                scene->addItem(PeIIIka8);
                                PeIIIka8->moveto(QPointF(i,j));
                                Pole[i][j]=23;
                            }else if (peretvor==4)
                            {
                                PeIIIka8 = new figure(15);
                                scene->addItem(PeIIIka8);
                                PeIIIka8->moveto(QPointF(i,j));
                                Pole[i][j]=24;
                            }
                        }
        if ((!isFigur[16])&&(!peIIIka[8])&&((peIIIka1->pos().x()-60)/68==i)&&((peIIIka1->pos().y()-60)/68==j))
                {
                    peIIIka[8]=true;
                    delete peIIIka1;
                    if (peretvor==1)
                    {
                        peIIIka1 = new figure(2);
                        scene->addItem(peIIIka1);
                        peIIIka1->moveto(QPointF(i,j));
                        Pole[i][j]=11;
                    }else if (peretvor==2)
                    {
                        peIIIka1 = new figure(3);
                        scene->addItem(peIIIka1);
                        peIIIka1->moveto(QPointF(i,j));
                        Pole[i][j]=12;
                    }else if (peretvor==3)
                    {
                        peIIIka1 = new figure(4);
                        scene->addItem(peIIIka1);
                        peIIIka1->moveto(QPointF(i,j));
                        Pole[i][j]=13;
                    }else if (peretvor==4)
                    {
                        peIIIka1 = new figure(5);
                        scene->addItem(peIIIka1);
                        peIIIka1->moveto(QPointF(i,j));
                        Pole[i][j]=15;
                    }
                }
                if ((!isFigur[17])&&(!peIIIka[9])&&((peIIIka2->pos().x()-60)/68==i)&&((peIIIka2->pos().y()-60)/68==j))
                        {
                            peIIIka[9]=true;
                            delete peIIIka2;
                            if (peretvor==1)
                            {
                                peIIIka2 = new figure(2);
                                scene->addItem(peIIIka2);
                                peIIIka2->moveto(QPointF(i,j));
                                Pole[i][j]=11;
                            }else if (peretvor==2)
                            {
                                peIIIka2 = new figure(3);
                                scene->addItem(peIIIka2);
                                peIIIka2->moveto(QPointF(i,j));
                                Pole[i][j]=12;
                            }else if (peretvor==3)
                            {
                                peIIIka2 = new figure(4);
                                scene->addItem(peIIIka2);
                                peIIIka2->moveto(QPointF(i,j));
                                Pole[i][j]=13;
                            }else if (peretvor==4)
                            {
                                peIIIka2 = new figure(5);
                                scene->addItem(peIIIka2);
                                peIIIka2->moveto(QPointF(i,j));
                                Pole[i][j]=15;
                            }
                        }
                if ((!isFigur[18])&&(!peIIIka[10])&&((peIIIka3->pos().x()-60)/68==i)&&((peIIIka3->pos().y()-60)/68==j))
                                {
                                    peIIIka[10]=true;
                                    delete peIIIka3;
                                    if (peretvor==1)
                                    {
                                        peIIIka3 = new figure(2);
                                        scene->addItem(peIIIka3);
                                        peIIIka3->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka3 = new figure(3);
                                        scene->addItem(peIIIka3);
                                        peIIIka3->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka3 = new figure(4);
                                        scene->addItem(peIIIka3);
                                        peIIIka3->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka3 = new figure(5);
                                        scene->addItem(peIIIka3);
                                        peIIIka3->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                if ((!isFigur[19])&&(!peIIIka[11])&&((peIIIka4->pos().x()-60)/68==i)&&((peIIIka4->pos().y()-60)/68==j))
                                {
                                    peIIIka[11]=true;
                                    delete peIIIka4;
                                    if (peretvor==1)
                                    {
                                        peIIIka4 = new figure(2);
                                        scene->addItem(peIIIka4);
                                        peIIIka4->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka4 = new figure(3);
                                        scene->addItem(peIIIka4);
                                        peIIIka4->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka4 = new figure(4);
                                        scene->addItem(peIIIka4);
                                        peIIIka4->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka4 = new figure(5);
                                        scene->addItem(peIIIka4);
                                        peIIIka4->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                if ((!isFigur[20])&&(!peIIIka[12])&&((peIIIka5->pos().x()-60)/68==i)&&((peIIIka5->pos().y()-60)/68==j))
                                {
                                    peIIIka[12]=true;
                                    delete peIIIka5;
                                    if (peretvor==1)
                                    {
                                        peIIIka5 = new figure(2);
                                        scene->addItem(peIIIka5);
                                        peIIIka5->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka5 = new figure(3);
                                        scene->addItem(peIIIka5);
                                        peIIIka5->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka5 = new figure(4);
                                        scene->addItem(peIIIka5);
                                        peIIIka5->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka5 = new figure(5);
                                        scene->addItem(peIIIka5);
                                        peIIIka5->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                if ((!isFigur[21])&&(!peIIIka[13])&&((peIIIka6->pos().x()-60)/68==i)&&((peIIIka6->pos().y()-60)/68==j))
                                {
                                    peIIIka[13]=true;
                                    delete peIIIka6;
                                    if (peretvor==1)
                                    {
                                        peIIIka6 = new figure(2);
                                        scene->addItem(peIIIka6);
                                        peIIIka6->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka6 = new figure(3);
                                        scene->addItem(peIIIka6);
                                        peIIIka6->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka6 = new figure(4);
                                        scene->addItem(peIIIka6);
                                        peIIIka6->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka6 = new figure(5);
                                        scene->addItem(peIIIka6);
                                        peIIIka6->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                if ((!isFigur[22])&&(!peIIIka[14])&&((peIIIka7->pos().x()-60)/68==i)&&((peIIIka7->pos().y()-60)/68==j))
                                {
                                    peIIIka[14]=true;
                                    delete peIIIka7;
                                    if (peretvor==1)
                                    {
                                        peIIIka7 = new figure(2);
                                        scene->addItem(peIIIka7);
                                        peIIIka7->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka7 = new figure(3);
                                        scene->addItem(peIIIka7);
                                        peIIIka7->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka7 = new figure(4);
                                        scene->addItem(peIIIka7);
                                        peIIIka7->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka7 = new figure(5);
                                        scene->addItem(peIIIka7);
                                        peIIIka7->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                if ((!isFigur[23])&&(!peIIIka[15])&&((peIIIka8->pos().x()-60)/68==i)&&((peIIIka8->pos().y()-60)/68==j))
                                {
                                    peIIIka[15]=true;
                                    delete peIIIka8;
                                    if (peretvor==1)
                                    {
                                        peIIIka8 = new figure(2);
                                        scene->addItem(peIIIka8);
                                        peIIIka8->moveto(QPointF(i,j));
                                        Pole[i][j]=11;
                                    }else if (peretvor==2)
                                    {
                                        peIIIka8 = new figure(3);
                                        scene->addItem(peIIIka8);
                                        peIIIka8->moveto(QPointF(i,j));
                                        Pole[i][j]=12;
                                    }else if (peretvor==3)
                                    {
                                        peIIIka8 = new figure(4);
                                        scene->addItem(peIIIka8);
                                        peIIIka8->moveto(QPointF(i,j));
                                        Pole[i][j]=13;
                                    }else if (peretvor==4)
                                    {
                                        peIIIka8 = new figure(5);
                                        scene->addItem(peIIIka8);
                                        peIIIka8->moveto(QPointF(i,j));
                                        Pole[i][j]=15;
                                    }
                                }
                peretvor=0;
                jj=-1;
                j=-1;
    }
}

void MainWindow::updatea()
{
    this->peret();
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if ((Pole[i][j]!=Temp[i][j])&&(Pole[i][j]!=0))
            {
                if (Pole[i][j]<20)
                {
                    if ((!isFigur[0])&&((PeIIIka1->pos().x()-60)/68==i)&&((PeIIIka1->pos().y()-60)/68==j))
                    {
                        isFigur[0]=true;
                        delete PeIIIka1;
                    }
                    if ((!isFigur[1])&&((PeIIIka2->pos().x()-60)/68==i)&&((PeIIIka2->pos().y()-60)/68==j))
                    {
                        isFigur[1]=true;
                        delete PeIIIka2;
                    }
                    if ((!isFigur[2])&&((PeIIIka3->pos().x()-60)/68==i)&&((PeIIIka3->pos().y()-60)/68==j))
                    {
                        isFigur[2]=true;
                        delete PeIIIka3;
                    }
                    if ((!isFigur[3])&&((PeIIIka4->pos().x()-60)/68==i)&&((PeIIIka4->pos().y()-60)/68==j))
                    {
                        isFigur[3]=true;
                        delete PeIIIka4;
                    }
                    if ((!isFigur[4])&&((PeIIIka5->pos().x()-60)/68==i)&&((PeIIIka5->pos().y()-60)/68==j))
                    {
                        isFigur[4]=true;
                        delete PeIIIka5;
                    }
                    if ((!isFigur[5])&&((PeIIIka6->pos().x()-60)/68==i)&&((PeIIIka6->pos().y()-60)/68==j))
                    {
                        isFigur[5]=true;
                        delete PeIIIka6;
                    }
                    if ((!isFigur[6])&&((PeIIIka7->pos().x()-60)/68==i)&&((PeIIIka7->pos().y()-60)/68==j))
                    {
                        isFigur[6]=true;
                        delete PeIIIka7;
                    }
                    if ((!isFigur[7])&&((PeIIIka8->pos().x()-60)/68==i)&&((PeIIIka8->pos().y()-60)/68==j))
                    {
                        isFigur[7]=true;
                        delete PeIIIka8;
                    }
                    if ((!isFigur[8])&&((Slon1->pos().x()-60)/68==i)&&((Slon1->pos().y()-60)/68==j))
                    {
                        isFigur[8]=true;
                        delete Slon1;
                    }
                    if ((!isFigur[9])&&((Konb1->pos().x()-60)/68==i)&&((Konb1->pos().y()-60)/68==j))
                    {
                        isFigur[9]=true;
                        delete Konb1;
                    }
                    if ((!isFigur[10])&&((Offecer1->pos().x()-60)/68==i)&&((Offecer1->pos().y()-60)/68==j))
                    {
                        isFigur[10]=true;
                        delete Offecer1;
                    }
                    if ((!isFigur[11])&&((Dama->pos().x()-60)/68==i)&&((Dama->pos().y()-60)/68==j))
                    {
                        isFigur[11]=true;
                        delete Dama;
                    }
                    if ((!isFigur[12])&&((Korol->pos().x()-60)/68==i)&&((Korol->pos().y()-60)/68==j))
                    {
                        isFigur[12]=true;
                        delete Korol;
                    }
                    if ((!isFigur[13])&&((Offecer2->pos().x()-60)/68==i)&&((Offecer2->pos().y()-60)/68==j))
                    {
                        isFigur[13]=true;
                        delete Offecer2;
                    }
                    if ((!isFigur[14])&&((Konb2->pos().x()-60)/68==i)&&((Konb2->pos().y()-60)/68==j))
                    {
                        isFigur[14]=true;
                        delete Konb2;
                    }
                    if ((!isFigur[15])&&((Slon2->pos().x()-60)/68==i)&&((Slon2->pos().y()-60)/68==j))
                    {
                        isFigur[15]=true;
                        delete Slon2;
                    }
                }
                    if (Pole[i][j]>19)
                    {
                        if ((!isFigur[16])&&((peIIIka1->pos().x()-60)/68==i)&&((peIIIka1->pos().y()-60)/68==j))
                        {
                            isFigur[16]=true;
                            delete peIIIka1;
                        }
                        if ((!isFigur[17])&&((peIIIka2->pos().x()-60)/68==i)&&((peIIIka2->pos().y()-60)/68==j))
                        {
                            isFigur[17]=true;
                            delete peIIIka2;
                        }
                        if ((!isFigur[18])&&((peIIIka3->pos().x()-60)/68==i)&&((peIIIka3->pos().y()-60)/68==j))
                        {
                            isFigur[18]=true;
                            delete peIIIka3;
                        }
                        if ((!isFigur[19])&&((peIIIka4->pos().x()-60)/68==i)&&((peIIIka4->pos().y()-60)/68==j))
                        {
                            isFigur[19]=true;
                            delete peIIIka4;
                        }
                        if ((!isFigur[20])&&((peIIIka5->pos().x()-60)/68==i)&&((peIIIka5->pos().y()-60)/68==j))
                        {
                            isFigur[20]=true;
                            delete peIIIka5;
                        }
                        if ((!isFigur[21])&&((peIIIka6->pos().x()-60)/68==i)&&((peIIIka6->pos().y()-60)/68==j))
                        {
                            isFigur[21]=true;
                            delete peIIIka6;
                        }
                        if ((!isFigur[22])&&((peIIIka7->pos().x()-60)/68==i)&&((peIIIka7->pos().y()-60)/68==j))
                        {
                            isFigur[22]=true;
                            delete peIIIka7;
                        }
                        if ((!isFigur[23])&&((peIIIka8->pos().x()-60)/68==i)&&((peIIIka8->pos().y()-60)/68==j))
                        {
                            isFigur[23]=true;
                            delete peIIIka8;
                        }
                        if ((!isFigur[24])&&((slon1->pos().x()-60)/68==i)&&((slon1->pos().y()-60)/68==j))
                        {
                            isFigur[24]=true;
                            delete slon1;
                        }
                        if ((!isFigur[25])&&((konb1->pos().x()-60)/68==i)&&((konb1->pos().y()-60)/68==j))
                        {
                            isFigur[25]=true;
                            delete konb1;
                        }
                        if ((!isFigur[26])&&((offecer1->pos().x()-60)/68==i)&&((offecer1->pos().y()-60)/68==j))
                        {
                            isFigur[26]=true;
                            delete offecer1;
                        }
                        if ((!isFigur[27])&&((dama->pos().x()-60)/68==i)&&((dama->pos().y()-60)/68==j))
                        {
                            isFigur[27]=true;
                            delete dama;
                        }
                        if ((!isFigur[28])&&((korol->pos().x()-60)/68==i)&&((korol->pos().y()-60)/68==j))
                        {
                            isFigur[28]=true;
                            delete korol;
                        }
                        if ((!isFigur[29])&&((offecer2->pos().x()-60)/68==i)&&((offecer2->pos().y()-60)/68==j))
                        {
                            isFigur[29]=true;
                            delete offecer2;
                        }
                        if ((!isFigur[30])&&((konb2->pos().x()-60)/68==i)&&((konb2->pos().y()-60)/68==j))
                        {
                            isFigur[30]=true;
                            delete konb2;
                        }
                        if ((!isFigur[31])&&((slon2->pos().x()-60)/68==i)&&((slon2->pos().y()-60)/68==j))
                        {
                            isFigur[31]=true;
                            delete slon2;
                        }
                    }
                    if (Pole[i][j]==30||Pole[i][j]==5)
                        Pole[i][j]=0;

            }
        }
    }
    if (Temp[7][7]==11&&Pole[7][7]==0)
    {
        if (Pole[5][7]==11&&rok[1])
        {
            if (Temp[4][7]==14&&Pole[6][7]==14)
            {
           slon2->moveto(QPointF(5,7));
           rok[1]=false;
            }
        }
    }
    if (Temp[0][7]==11&&Pole[0][7]==0)
    {
        if (Pole[3][7]==11&&rok[1])
        {
            if (Temp[4][7]==14&&Pole[2][7]==14)
            {
           slon1->moveto(QPointF(3,7));
           rok[1]=false;
            }
        }
    }

    if (Temp[7][0]==21&&Pole[7][0]==0)
    {
        if (Pole[5][0]==21&&rok[2])
        {
            if (Temp[4][0]==25&&Pole[6][0]==25)
            {
           Slon2->moveto(QPointF(5,0));
           rok[2]=false;
            }
        }
    }
    if (Temp[0][0]==21&&Pole[0][0]==0)
    {
        if (Pole[3][0]==21&&rok[2])
        {
            if (Temp[4][0]==25&&Pole[2][0]==25)
            {
           Slon1->moveto(QPointF(3,0));
            rok[2]=false;
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
