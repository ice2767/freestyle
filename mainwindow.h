#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>

#include "mylabel.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLabel *m_label;
    QLabel *m_label2;

    MyLabel *m_myLabel;
    QPushButton *m_button;

    QVBoxLayout *m_verticalLayout;
    QGridLayout *m_gridLayout;
    QHBoxLayout *m_hLayout;
    QWidget *m_MyWidget;
public slots:
    void slot_m_button_click();
protected:
    bool m_bAnimationStart;

};

#endif // MAINWINDOW_H
