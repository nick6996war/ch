#include "figure.h"
bool rock[3]={true,true,true};
bool rock1[3]={true,true,true};
bool rok[2]={false,false};

int pereh[6];
int bot =0;
bool hod=false;
int Pole[8][8]={{21,20,0,0,0,0,10,11}
                ,{22,20,0,0,0,0,10,12}
                ,{23,20,0,0,0,0,10,13}
                ,{24,20,0,0,0,0,10,15}
                ,{25,20,0,0,0,0,10,14}
                ,{23,20,0,0,0,0,10,13}
                ,{22,20,0,0,0,0,10,12}
                ,{21,20,0,0,0,0,10,11}};
int cordes[2];
int press=0;

bool figure::FromTo(int xfrom,int yfrom,int xto,int yto,bool temp)
{
    if ((xto==xfrom)&&(yto==yfrom))
    {
        return false;
    }
    if ((Pole[xto][yto]<20)&&(Pole[xfrom][yfrom]>19))
        {
        if (Pole[xfrom][yfrom]==20)
        {
            if ((yfrom==1)&&(xfrom==xto)&&(Pole[xto][yto]==0))
            {
                if ((yto==2)||(yto==3))
                { 
                    if (yto==3&&Pole[xfrom][2]==0)
                    {
                        if (temp)
                        {
                            return true;
                        }
                        Pole[xfrom][yfrom]=0;
                        if (yto==3)
                        {
                            if(Pole[xto-1][yto]==10||Pole[xto+1][yto]==10)
                            {
                                pereh[0]=1;
                                pereh[1]=xto;
                                pereh[2]=yto-1;
                            }

                        }
                        Pole[xto][yto]=20;
                       return true;
                    }else if (yto==2)
                    {
                        if (temp)
                        {
                            return true;
                        }
                        Pole[xfrom][yfrom]=0;
                        Pole[xto][yto]=20;
                       return true;
                    }
                }
            }else if ((xfrom==xto)&&(Pole[xto][yto]==0))
                {
                if (yto-yfrom==1)
                {
                    if (temp)
                    {
                        return true;
                    }
                        Pole[xfrom][yfrom]=0;
                        Pole[xto][yto]=20;
                        return true;
                }
            }else if((yto-yfrom==1)&&((xto-xfrom==1)||(xfrom-xto==1)))
            {
                if (Pole[xto][yto]<19&&Pole[xto][yto]!=0)
                {
                    if (temp)
                    {
                        return true;
                    }
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=20;
                return true;
                }
            }
            if(yfrom==4)
            {
                if (yto==5&&(xfrom==pereh[4]+1||xfrom==pereh[4]-1))
                {
                    if (pereh[3]==1&&xto==pereh[4]&&yto==pereh[5])
                    {
                        if (temp)
                        {
                            return true;
                        }
                        Pole[xfrom][yfrom]=0;
                        Pole[xto][yto-1]=30;
                        Pole[xto][yto]=20;
                       return true;
                    }
                }
            }
        }
        if (Pole[xfrom][yfrom]==21)
        {
            bool flag = false;
            if (yto==yfrom)
            {
                int x=xto-xfrom;
                if (x<0)
                    x*=-1;
                for (int i=1;i<x;i++)
                {
                    if (xto>xfrom)
                    {
                        if(Pole[xfrom+i][yfrom]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }else if(xto<xfrom)
                    {
                        if(Pole[xfrom-i][yfrom]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }else if(xto==xfrom)
            {
                int y=yto-yfrom;
                if (y<0)
                    y*=-1;
                for (int i=1;i<y;i++)
                {
                    if (yto>yfrom)
                    {
                        if(Pole[xfrom][yfrom+i]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }else if(yto<yfrom)
                    {
                        if(Pole[xfrom][yfrom-i]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }else
                flag=true;
            if (!flag)
            {
                if (temp)
                {
                    return true;
                }
                if (xfrom==0&&yfrom==0)
                    rock1[1]=false;
                if (xfrom==7&&yfrom==0)
                    rock1[0]=false;
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=21;
                return true;
            }
        }
        if (Pole[xfrom][yfrom]==22)
        {
                int x=xfrom-xto;
                int y=yfrom-yto;
                if (x<0)
                    x*=-1;
                if (y<0)
                    y*=-1;
                if ((x!=0)&&(y!=0)&&(x+y==3))
                {
                    if (temp)
                    {
                        return true;
                    }
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=22;
                    return true;
                }
        }
        if (Pole[xfrom][yfrom]==23)
        {
            bool flag = false;
            int x=xfrom-xto;
            int y=yfrom-yto;
            if (x<0)
                x*=-1;
            if (y<0)
                y*=-1;
            if (x==y)
            {
                if ((xfrom>xto)&&(yfrom>yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom-i][yfrom-i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom<xto)&&(yfrom>yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom+i][yfrom-i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom>xto)&&(yfrom<yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom-i][yfrom+i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom<xto)&&(yfrom<yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom+i][yfrom+i]!=0)
                        {
                            flag = true;
                        }
                    }
                }

                if (!flag)
                {
                    if (temp)
                    {
                        return true;
                    }
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=23;
                return true;
                }
            }
        }
        if (Pole[xfrom][yfrom]==24)
        {
            bool flag = false;
            int x=xfrom-xto;
            int y=yfrom-yto;
            if (x<0)
                x*=-1;
            if (y<0)
                y*=-1;
            if (x==y)
            {
                if ((xfrom>xto)&&(yfrom>yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom-i][yfrom-i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom<xto)&&(yfrom>yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom+i][yfrom-i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom>xto)&&(yfrom<yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom-i][yfrom+i]!=0)
                        {
                            flag = true;
                        }
                    }
                }else if ((xfrom<xto)&&(yfrom<yto))
                {
                    for(int i=1;i<x;i++)
                    {
                        if(Pole[xfrom+i][yfrom+i]!=0)
                        {
                            flag = true;
                        }
                    }
                }

                if (!flag)
                {
                    if (temp)
                    {
                        return true;
                    }
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=24;
                return true;
                }
            }

            flag = false;
            if (yto==yfrom)
            {
                for (int i=1;i<x;i++)
                {
                    if (xto>xfrom)
                    {
                        if(Pole[xfrom+i][yfrom]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }else if(xto<xfrom)
                    {
                        if(Pole[xfrom-i][yfrom]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }else if(xto==xfrom)
            {
                for (int i=1;i<y;i++)
                {
                    if (yto>yfrom)
                    {
                        if(Pole[xfrom][yfrom+i]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }else if(yto<yfrom)
                    {
                        if(Pole[xfrom][yfrom-i]!=0)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }else
                flag=true;
            if (!flag)
            {
                if (temp)
                {
                    return true;
                }
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=24;
                return true;
            }
        }
        if (Pole[xfrom][yfrom]==25)
        {
            int x=xfrom-xto;
            int y=yfrom-yto;
            if (x<0)
                x*=-1;
            if (y<0)
                y*=-1;
            if ((x+y<3)&&(x!=2)&&(y!=2))
            {
                if (temp)
                {
                    return true;
                }
                if (xfrom==4&&yfrom==0)
                    rock1[2]=false;
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=25;
                return true;
            }
            if (xfrom==4&&yfrom==0)
            {
                if (yto==0&&rock1[2])
                {
                    if(Pole[5][yto]==0&&xto==6&&rock1[0])
                    {

                        if(check(xfrom,yfrom,xfrom,yfrom))
                        if (check(xfrom,yfrom,xfrom+1,yfrom))
                        {
                            if (temp)
                            {
                                return true;
                            }
                        rock1[2]=false;
                        rok[2]=true;
                        Pole[xfrom][yfrom]=0;
                        Pole[xto][yto]=25;
                        Pole[xto-1][yto]=21;
                        Pole[7][yto]=0;
                        return true;
                        }
                    }else if((Pole[3][yto]==0)&&(Pole[2][yto]==0)&&(Pole[1][yto]==0&&xto==2)&&rock1[1])
                    {
                                if(check(xfrom,yfrom,xfrom,yfrom))
                                if (check(xfrom,yfrom,xfrom-1,yfrom))
                                {
                                    if (temp)
                                    {
                                        return true;
                                    }
                        rock1[2]=false;
                        rok[2]=true;
                        Pole[xfrom][yfrom]=0;
                        Pole[xto][yto]=25;
                        Pole[xto+1][yto]=21;
                        Pole[0][yto]=0;
                        return true;
                        }
                    }
                }
            }
            }
        }
    if ((Pole[xto][yto]>19||Pole[xto][yto]==0)&&(Pole[xfrom][yfrom]<20))
    {   
    if (Pole[xfrom][yfrom]==10)
    {
        if ((yfrom==6)&&(xfrom==xto)&&(Pole[xto][yto]==0))
        {
            if ((yto==4)||(yto==5))
            {
                if (yto==4&&Pole[xfrom][5]==0)
                {
                    if (temp)
                    {
                        return true;
                    }
                    Pole[xfrom][yfrom]=0;
                    if (yto==4)
                    {

                        if(Pole[xto-1][yto]==20||Pole[xto+1][yto]==20)
                        {
                            pereh[3]=1;
                            pereh[4]=xto;
                            pereh[5]=yto+1;
                        }

                    }
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=10;
                   return true;
                }else if (yto==5)
                {
                    if (temp)
                    {
                        return true;
                    }
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=10;
                   return true;
                }
            }
        }else if ((xfrom==xto)&&(Pole[xto][yto]==0))
            {
            if (yto-yfrom==-1)
            {
                if (temp)
                {
                    return true;
                }
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=10;
                    return true;
            }
        }else if((yto-yfrom==-1)&&((xto-xfrom==1)||(xfrom-xto==1)))
        {
            if (Pole[xto][yto]>19)
            {
                if (temp)
                {
                    return true;
                }
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=10;
            return true;
            }
        }
        if(yfrom==3)
        {
            if (yto==2&&(xfrom==pereh[1]+1||xfrom==pereh[1]-1))
            {
                if (pereh[0]==1&&xto==pereh[1]&&yto==pereh[2])
                {
                    if (temp)
                    {
                        return true;
                    }
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto+1]=5;
                    Pole[xto][yto]=10;
                   return true;
                }
            }
        }
    }
    if (Pole[xfrom][yfrom]==11)
    {
        bool flag = false;
        if (yto==yfrom)
        {
            int x=xto-xfrom;
            if (x<0)
                x*=-1;
            for (int i=1;i<x;i++)
            {
                if (xto>xfrom)
                {
                    if(Pole[xfrom+i][yfrom]!=0)
                    {
                        flag=true;
                        break;
                    }
                }else if(xto<xfrom)
                {
                    if(Pole[xfrom-i][yfrom]!=0)
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }else if(xto==xfrom)
        {
            int y=yto-yfrom;
            if (y<0)
                y*=-1;
            for (int i=1;i<y;i++)
            {
                if (yto>yfrom)
                {
                    if(Pole[xfrom][yfrom+i]!=0)
                    {
                        flag=true;
                        break;
                    }
                }else if(yto<yfrom)
                {
                    if(Pole[xfrom][yfrom-i]!=0)
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }else
            flag=true;
        if (!flag)
        {
            if (temp)
            {
                return true;
            }
            if (xfrom==7&&yfrom==7)
                rock[0]=false;
            if (xfrom==0&&yfrom==7)
                rock[1]=false;
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=11;
            return true;
        }
    }
    if (Pole[xfrom][yfrom]==12)
    {
            int x=xfrom-xto;
            int y=yfrom-yto;
            if (x<0)
                x*=-1;
            if (y<0)
                y*=-1;
            if ((x!=0)&&(y!=0)&&(x+y==3))
            {
                if (temp)
                {
                    return true;
                }
                Pole[xfrom][yfrom]=0;
                Pole[xto][yto]=12;
                return true;
            }
    }
    if (Pole[xfrom][yfrom]==13)
    {
        bool flag = false;
        int x=xfrom-xto;
        int y=yfrom-yto;
        if (x<0)
            x*=-1;
        if (y<0)
            y*=-1;
        if (x==y)
        {
            if ((xfrom>xto)&&(yfrom>yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom-i][yfrom-i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom<xto)&&(yfrom>yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom+i][yfrom-i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom>xto)&&(yfrom<yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom-i][yfrom+i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom<xto)&&(yfrom<yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom+i][yfrom+i]!=0)
                    {
                        flag = true;
                    }
                }
            }

            if (!flag)
            {
                if (temp)
                {
                    return true;
                }
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=13;
            return true;
            }
        }
    }
    if (Pole[xfrom][yfrom]==15)
    {
        bool flag = false;
        int x=xfrom-xto;
        int y=yfrom-yto;
        if (x<0)
            x*=-1;
        if (y<0)
            y*=-1;
        if (x==y)
        {
            if ((xfrom>xto)&&(yfrom>yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom-i][yfrom-i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom<xto)&&(yfrom>yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom+i][yfrom-i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom>xto)&&(yfrom<yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom-i][yfrom+i]!=0)
                    {
                        flag = true;
                    }
                }
            }else if ((xfrom<xto)&&(yfrom<yto))
            {
                for(int i=1;i<x;i++)
                {
                    if(Pole[xfrom+i][yfrom+i]!=0)
                    {
                        flag = true;
                    }
                }
            }

            if (!flag)
            {
                if (temp)
                {
                    return true;
                }
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=15;
            return true;
            }
        }

        flag = false;
        if (yto==yfrom)
        {
            for (int i=1;i<x;i++)
            {
                if (xto>xfrom)
                {
                    if(Pole[xfrom+i][yfrom]!=0)
                    {
                        flag=true;
                        break;
                    }
                }else if(xto<xfrom)
                {
                    if(Pole[xfrom-i][yfrom]!=0)
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }else if(xto==xfrom)
        {
            for (int i=1;i<y;i++)
            {
                if (yto>yfrom)
                {
                    if(Pole[xfrom][yfrom+i]!=0)
                    {
                        flag=true;
                        break;
                    }
                }else if(yto<yfrom)
                {
                    if(Pole[xfrom][yfrom-i]!=0)
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }else
            flag=true;
        if (!flag)
        {
            if (temp)
            {
                return true;
            }
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=15;
            return true;
        }
    }
    if (Pole[xfrom][yfrom]==14)
    {
        int x=xfrom-xto;
        int y=yfrom-yto;
        if (x<0)
            x*=-1;
        if (y<0)
            y*=-1;
        if ((x+y<3)&&(x!=2)&&(y!=2))
        {
            if (temp)
            {
                return true;
            }
            if (xfrom==4&&yfrom==7)
                rock[2]=false;
            Pole[xfrom][yfrom]=0;
            Pole[xto][yto]=14;
            return true;
        }
        if (xfrom==4&&yfrom==7)
        {
            if (yto==7)
            {
                if((Pole[5][yto]==0&&xto==6)&&(rock[2]&&rock[0]))
                {
                    if(check(xfrom,yfrom,xfrom,yfrom))
                    if (check(xfrom,yfrom,xfrom+1,yfrom))
                    {
                        if (temp)
                        {
                            return true;
                        }
                    rok[1]=true;
                    rock[2]=false;
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=14;
                    Pole[xto-1][yto]=11;
                    Pole[7][yto]=0;
                    return true;
                    }
                }else if((Pole[3][yto]==0)&&(Pole[2][yto]==0)&&(Pole[1][yto]==0&&xto==2)&&(rock[2]&&rock[1]))
                {
                    if(check(xfrom,yfrom,xfrom,yfrom))
                    if (check(xfrom,yfrom,xfrom-1,yfrom))
                    {
                        if (temp)
                        {
                            return true;
                        }
                    rok[1]=true;
                    rock[2]=false;
                    Pole[xfrom][yfrom]=0;
                    Pole[xto][yto]=14;
                    Pole[xto+1][yto]=11;
                    Pole[0][yto]=0;
                    return true;
                    }
                }
            }
        }
        }
    }
    return false;
}

figure::figure(int clas)
{
    this->clas=clas;
}
figure::~figure()
{

}
QRectF figure::boundingRect() const
{
    return QRectF (-13,-30,27,60);
}

void figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    if (clas==1)
    painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/PeIIIka.png"));
    else if (clas==5)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/dama.png"));
    else if (clas==6)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/korol.png"));
    else if (clas==4)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Oficer.png"));
    else if (clas==3)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Konb.png"));
    else if (clas==2)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Slon.png"));
    else if (clas==11)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/PeIIIka2.png"));
    else if (clas==15)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/dama2.png"));
    else if (clas==16)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/korol2.png"));
    else if (clas==14)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Oficer2.png"));
    else if (clas==13)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Konb2.png"));
    else if (clas==12)
     painter->drawPixmap(-13,-30,27,60,QPixmap("C:/Users/salim/Desktop/figurs/Slon2.png"));
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

bool figure::put(int x,int y)
{
    int xfrom,yfrom,xto,yto;
    if (Pole[x][y]>19)
    {
        for (xfrom=0;xfrom<8;xfrom++)
        {
            for (yfrom=0;yfrom<8;yfrom++)
            {
                if(Pole[xfrom][yfrom]<20&&Pole[xfrom][yfrom]!=0)
                {
                    for(xto=0;xto<8;xto++)
                    {
                        for( yto=0;yto<8;yto++)
                        {
                            if(xfrom==xto&&yfrom==yto)
                            {
                                continue;
                            }
                            if (this->FromTo(xfrom,yfrom,xto,yto,1))
                            {
                                if(check(xfrom,yfrom,xto,yto))
                                {
                                    char temp[100];
                                    temp[0]=xfrom+48;
                                    temp[1]=' ';
                                    temp[2]=yfrom+48;
                                    temp[3]=' ';
                                    temp[4]=xto+48;
                                    temp[5]=' ';
                                    temp[6]=yto+48;
                                    temp[7]=' ';
                                    temp[8]=Pole[xfrom][yfrom]/10+48;
                                    temp[9]=Pole[xfrom][yfrom]-((temp[8]-48)*10)+48;
                                    temp[10]=0;
                                    QMessageBox box;
                                    box.setText(temp);
                                    box.exec();
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        for (xfrom=0;xfrom<8;xfrom++)
        {
            for (yfrom=0;yfrom<8;yfrom++)
            {
                if(Pole[xfrom][yfrom]>19)
                {
                    for(xto=0;xto<8;xto++)
                    {
                        for(yto=0;yto<8;yto++)
                        {
                            if(xfrom==xto&&yfrom==yto)
                            {
                                continue;
                            }
                            if (this->FromTo(xfrom,yfrom,xto,yto,1))
                            {
                                if(check(xfrom,yfrom,xto,yto))
                                {
                                    char temp[100];
                                    temp[0]=xfrom+48;
                                    temp[1]=' ';
                                    temp[2]=yfrom+48;
                                    temp[3]=' ';
                                    temp[4]=xto+48;
                                    temp[5]=' ';
                                    temp[6]=yto+48;
                                    temp[7]=' ';
                                    temp[8]=Pole[xfrom][yfrom]/10+48;
                                    temp[9]=Pole[xfrom][yfrom]-((temp[8]-48)*10)+48;
                                    temp[10]=0;
                                    QMessageBox box;
                                    box.setText(temp);
                                    box.exec();
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (press)
    {
        press++;
        return;
    }
    press++;
    from=mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);

}

void figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (!press)
    {
        press--;
        return;
    }
    press--;
    this->setCursor(QCursor(Qt::ArrowCursor));
    QPointF cord;
    cord=mapToScene(event->pos());
    int fromx=(from.x()-27)/68;
    int fromy=(from.y()-27)/68;
    int cordx=(cord.x()-27)/68;
    int cordy=(cord.y()-27)/68;
    if ((Pole[fromx][fromy]<20&&hod==false)||(Pole[fromx][fromy]>19&&hod==true))
    {
    if (Pole[fromx][fromy]>0&&Pole[fromx][fromy]<20)
        if (Pole[cordx][cordy]>0&&Pole[cordx][cordy]<20)
        {
            this->moveto(QPointF(fromx,fromy));
            return;
        }
    if (Pole[fromx][fromy]>20)
        if (Pole[cordx][cordy]>20)
        {
            this->moveto(QPointF(fromx,fromy));
            return;
        }

    if (check((from.x()-27)/68,(from.y()-27)/68,(cord.x()-27)/68,(cord.y()-27)/68))
    {
        if (FromTo((from.x()-27)/68,(from.y()-27)/68,(cord.x()-27)/68,(cord.y()-27)/68,0))
        {
            if (hod)
                hod=false;
            else
                hod=true;
        int tempx = cord.x();
        int tempy = cord.y();
         tempx = (tempx-27)/68;
         tempy = (tempy-27)/68;
         if(Pole[tempx][tempy]>19)
         {
             pereh[3]=0;
         }
         if(Pole[tempx][tempy]<20)
         {
             pereh[0]=0;
         }
         int tempi,tempj;
         if (Pole[tempx][tempy]>19)
         {
             for (int i=0;i<8;i++)
             {
                 for (int j=0;j<8;j++)
                 {
                     if (Pole[i][j]<20&&Pole[i][j]!=0)
                     {
                         tempi=i;
                         tempj=j;
                         break;
                     }
                 }
             }
         }else{
             for (int i=0;i<8;i++)
             {
                 for (int j=0;j<8;j++)
                 {
                     if (Pole[i][j]>19)
                     {
                         tempi=i;
                         tempj=j;
                         break;
                     }
                 }
             }
         }
        this->setPos(tempx*68+60,tempy*68+60);

            if(bot==0)
            {
                 if (!check(tempi,tempj,tempi,tempj))
                 {
                     if (!put(tempx,tempy))
                     {
                         QMessageBox box;
                         box.setText("Мат!");
                         box.exec();
                     }else{
                     QMessageBox box;
                     box.setText("Шах!");
                     box.exec();
                     }
                 }else{
                     if (!put(tempx,tempy))
                     {
                         QMessageBox box;
                         box.setText("Пат!");
                         box.exec();
                     }
                    }
            }else if (bot==1)
            {

            }

        }else{
            int tempx = from.x();
            int tempy = from.y();
            tempx = (tempx-27)/68;
            tempy = (tempy-27)/68;
            this->setPos(tempx*68+60,tempy*68+60);
        }
    }else{
        int tempx = from.x();
        int tempy = from.y();
        tempx = (tempx-27)/68;
        tempy = (tempy-27)/68;
        this->setPos(tempx*68+60,tempy*68+60);
    }
    }else{
        int tempx = from.x();
        int tempy = from.y();
        tempx = (tempx-27)/68;
        tempy = (tempy-27)/68;
        this->setPos(tempx*68+60,tempy*68+60);
    }
    Q_UNUSED(event);
}

void figure::transfer(int x, int y)
{
}

bool figure::check(int xfrom,int yfrom,int xto,int yto)
{
    bool flag = true;
    if (Pole[xfrom][yfrom]>19)
    {
        int Temp[8][8];
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                Temp[i][j]=Pole[i][j];
            }
        }
        int x,y;

        Temp[xto][yto]=Temp[xfrom][yfrom];
        if (!(xfrom==xto&&yfrom==yto))
        Temp[xfrom][yfrom]=0;

        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                if (Temp[i][j]==25)
                {
                    x=i;
                    y=j;
                }
            }
        }

        for (int i=x+1;i<8;i++)
        {
            if (Temp[i][y]>20)
            {
                break;
            }
            if ((Temp[i][y]==11)||(Temp[i][y]==15))
            {
                flag=false;
            }
            if (Temp[i][y]>0)
                break;
        }
        for (int i=y+1;i<8;i++)
        {
            if (Temp[x][i]>20)
            {
                break;
            }
            if ((Temp[x][i]==11)||(Temp[x][i]==15))
            {
                flag=false;
            }
            if (Temp[x][i]>0)
                break;
        }
        for (int i=x-1;i>=0;i--)
        {
            if (Temp[i][y]>20)
            {
                break;
            }
            if ((Temp[i][y]==11)||(Temp[i][y]==15))
            {
                flag=false;
            }
            if (Temp[i][y]>0)
                break;
        }
        for (int i=y-1;i>=0;i--)
        {
            if (Temp[x][i]>20)
            {
                break;
            }
            if ((Temp[x][i]==11)||(Temp[x][i]==15))
            {
                flag=false;
            }
            if (Temp[x][i]>0)
                break;
        }
        if ((Temp[x-1][y+1]==10)||(Temp[x+1][y+1]==10))
            flag=false;


        for (int i=1;i<8;i++)
        {
            if (x+i>7||y+i>7)
                break;
            if (Temp[x+i][y+i]>19)
            {
                break;
            }
            if ((Temp[x+i][y+i]==13)||(Temp[x+i][y+i]==15))
            {
                flag=false;
            }
            if (Temp[x+i][y+i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x-i<0||y+i>7)
                break;
            if (Temp[x-i][y+i]>19)
            {
                break;
            }
            if ((Temp[x-i][y+i]==13)||(Temp[x-i][y+i]==15))
            {
                flag=false;
            }
            if (Temp[x-i][y+i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x+i>7||y-i<0)
                break;
            if (Temp[x+i][y-i]>19)
            {
                break;
            }
            if ((Temp[x+i][y-i]==13)||(Temp[x+i][y-i]==15))
            {
                flag=false;
            }
            if (Temp[x+i][y-i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x-i<0||y-i<0)
                break;
            if (Temp[x-i][y-i]>19)
            {
                break;
            }
            if ((Temp[x-i][y-i]==13)||(Temp[x-i][y-i]==15))
            {
                flag=false;
            }
            if (Temp[x-i][y-i]>0)
                break;
        }

        if (x+1<8&&y+2<8)
        if (Temp[x+1][y+2]==12)
            flag=false;
        if (x-1>-1&&y+2<8)
        if (Temp[x-1][y+2]==12)
            flag=false;

        if (x+1<8&&y-2>-1)
        if (Temp[x+1][y-2]==12)
            flag=false;

        if (x-1>-1&&y-2>-1)
        if (Temp[x-1][y-2]==12)
            flag=false;

        if (x+2<8&&y+1<8)
        if (Temp[x+2][y+1]==12)
            flag=false;
        if (x-2>-1&&y+1<8)
        if (Temp[x-2][y+1]==12)
            flag=false;
        if (x+2<8&&y-1>-1)
        if (Temp[x+2][y-1]==12)
            flag=false;
        if (x-2>-1&&y-1>-1)
        if (Temp[x-2][y-1]==12)
            flag=false;

        if (x+1<8&&y+1<8)
        if (Temp[x+1][y+1]==14)
            flag=false;
        if (x+1<8)
        if (Temp[x+1][y]==14)
            flag=false;
        if (x+1<8&&y-1>-1)
        if (Temp[x+1][y-1]==14)
            flag=false;

        if (y+1<8)
        if (Temp[x][y+1]==14)
            flag=false;
        if (y-1>-1)
        if (Temp[x][y-1]==14)
            flag=false;

        if (x-1>-1&&y+1<8)
        if (Temp[x-1][y+1]==14)
            flag=false;
        if (x-1>-1)
        if (Temp[x-1][y]==14)
        flag=false;
        if (x-1>-1&&y-1>-1)
        if (Temp[x-1][y-1]==14)
            flag=false;
    }else{
        int Temp[8][8];
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                Temp[i][j]=Pole[i][j];
            }
        }
        int x,y;

        Temp[xto][yto]=Temp[xfrom][yfrom];
        if (!(xfrom==xto&&yfrom==yto))
        Temp[xfrom][yfrom]=0;

        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                if (Temp[i][j]==14)
                {
                    x=i;
                    y=j;
                }
            }
        }

        for (int i=x+1;i<8;i++)
        {
            if ((Temp[i][y]<20)&&(Temp[i][y]!=0))
            {
                break;
            }
            if ((Temp[i][y]==21)||(Temp[i][y]==24))
            {
                flag=false;
            }
            if (Temp[i][y]>0)
                break;
        }
        for (int i=y+1;i<8;i++)
        {
            if ((Temp[x][i]<20)&&(Temp[x][i]!=0))
            {
                break;
            }
            if ((Temp[x][i]==21)||(Temp[x][i]==24))
            {
                flag=false;
            }
            if (Temp[x][i]>0)
                break;
        }
        for (int i=x-1;i>=0;i--)
        {
            if ((Temp[i][y]<20)&&(Temp[i][y]!=0))
            {
                break;
            }
            if ((Temp[i][y]==21)||(Temp[i][y]==24))
            {
                flag=false;
            }
            if (Temp[i][y]>0)
                break;
        }
        for (int i=y-1;i>=0;i--)
        {
            if ((Temp[x][i]<20)&&(Temp[x][i]!=0))
            {
                break;
            }
            if ((Temp[x][i]==21)||(Temp[x][i]==24))
            {
                flag=false;
            }
            if (Temp[x][i]>0)
                break;
        }
        if ((Temp[x-1][y-1]==20)||(Temp[x+1][y-1]==20))
            flag=false;


        for (int i=1;i<8;i++)
        {
            if (x+i>7||y+i>7)
                break;
            if ((Temp[x+i][y+i]<20)&&(Temp[x+i][y+i]!=0))
            {
                break;
            }
            if ((Temp[x+i][y+i]==23)||(Temp[x+i][y+i]==24))
            {
                flag=false;
            }
            if (Temp[x+i][y+i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x-i<0||y+i>7)
                break;
            if ((Temp[x-i][y+i]<20)&&(Temp[x-i][y+i]!=0))
            {
                break;
            }
            if ((Temp[x-i][y+i]==23)||(Temp[x-i][y+i]==24))
            {
                flag=false;
            }
            if (Temp[x-i][y+i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x+i>7||y-i<0)
                break;
            if ((Temp[x+i][y-i]<20)&&(Temp[x+i][y-i]!=0))
            {
                break;
            }
            if ((Temp[x+i][y-i]==23)||(Temp[x+i][y-i]==24))
            {
                flag=false;
            }
            if (Temp[x+i][y-i]>0)
                break;
        }
        for (int i=1;i<8;i++)
        {
            if (x-i<0||y-i<0)
                break;
            if ((Temp[x-i][y-i]<20)&&(Temp[x-i][y-i]!=0))
            {
                break;
            }
            if ((Temp[x-i][y-i]==23)||(Temp[x-i][y-i]==24))
            {
                flag=false;
            }
            if (Temp[x-i][y-i]>0)
                break;
        }
        if (x+1>-1&&y+2<8)
        if (Temp[x+1][y+2]==22)
            flag=false;
        if (x-1>-1&&y+2<8)
        if (Temp[x-1][y+2]==22)
            flag=false;
        if (x+1>-1&&y-2>-1)
        if (Temp[x+1][y-2]==22)
            flag=false;
        if (x-1>-1&&y-2>-1)
        if (Temp[x-1][y-2]==22)
            flag=false;

        if (x+2<8&&y+1<8)
        if (Temp[x+2][y+1]==22)
            flag=false;
        if (x-2>-1&&y+1<8)
        if (Temp[x-2][y+1]==22)
            flag=false;
        if (x+2<8&&y-1>-1)
        if (Temp[x+2][y-1]==22)
            flag=false;
        if (x-2>-1&&y-1>-1)
        if (Temp[x-2][y-1]==22)
            flag=false;

        if (x+1<8&&y+1<8)
        if (Temp[x+1][y+1]==25)
            flag=false;
        if (x+1<8)
        if (Temp[x+1][y]==25)
            flag=false;
        if (x+1<8&&y-1>-1)
        if (Temp[x+1][y-1]==25)
            flag=false;

        if (y+1<8)
        if (Temp[x][y+1]==25)
            flag=false;
        if (y-1>-1)
        if (Temp[x][y-1]==25)
            flag=false;

        if (x-1>-1&&y+1<8)
        if (Temp[x-1][y+1]==25)
            flag=false;
        if (x-1>-1)
        if (Temp[x-1][y]==25)
        flag=false;
        if (x-1>-1&&y-1>-1)
        if (Temp[x-1][y-1]==25)
            flag=false;
    }
    return flag;
}

void figure::moveto(QPointF cord)
{
    this->setPos(cord.x()*68+60,cord.y()*68+60);
}
