#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QString>
#include <QPropertyAnimation>
#include <QList>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QString image,QWidget*parent=0);
    void animationControl(bool flag);

protected:
    void paintEvent(QPaintEvent*);//update()可以触发paintEvent()

    QPropertyAnimation *m_animation;
    QList<QPixmap> m_pixmapList;
    int m_index;
    bool m_bStart;

public slots:
    void slotValuechange(QVariant var);

};

#endif // MYLABEL_H
