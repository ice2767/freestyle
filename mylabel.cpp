#include "mylabel.h"

MyLabel::MyLabel(QString image,QWidget *parent):QLabel(parent)
{
    qDebug("[%s:%s:%d] ",__FILE__,__func__, __LINE__);

    QPixmap tmpPixmap(image);
    //setCursor(Qt::PointingHandCursor);
    m_index = 0 ;
    for(int i=0;i<10;i++)//进入
    {
        m_pixmapList<<tmpPixmap.copy(i*(tmpPixmap.width()/10),0,tmpPixmap.width()/10,tmpPixmap.height());
    }
    m_animation=new QPropertyAnimation(this,"");
    m_animation->setStartValue(0);
    m_animation->setEndValue(9);
    m_animation->setDuration(600);
    m_animation->setLoopCount(-1);
    connect(m_animation,SIGNAL(valueChanged(QVariant)),this,SLOT(slotValuechange(QVariant)));

    setPixmap(m_pixmapList.at(m_index));


    //m_animation->start();
}

#if 1
void MyLabel::paintEvent(QPaintEvent *)
{
    //qDebug("[%s:%s:%d] ",__FILE__,__func__, __LINE__);
    QPainter painter(this);
    QPixmap pm = m_pixmapList.at(m_index);
    painter.drawPixmap(0,0,pm.width(),pm.height(),pm);
}

void MyLabel::slotValuechange(QVariant var)
{
    m_index=var.toInt();
    //qDebug("[%s:%s:%d] m_enterIndex = %d",__FILE__,__func__, __LINE__,m_index);
    update();
}

void MyLabel::animationControl(bool flag)
{
    if (flag){
        m_animation->start();
    }else{
        m_animation->stop();
    }
}
#endif
