#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //setAttribute(Qt::WA_TranslucentBackground,true);
    m_bAnimationStart = false ;
#if 1
    m_MyWidget = new QWidget(this);

#if 0
    m_verticalLayout = new QVBoxLayout(m_MyWidget);
#else
    m_gridLayout = new QGridLayout(m_MyWidget);
#endif

    m_myLabel = new MyLabel(":/image/safe_Hover.png");
    qDebug("[%s:%s:%d] ",__FILE__,__func__, __LINE__);
    m_button = new QPushButton();
    m_button->setText("start");

    connect(m_button,SIGNAL(clicked()),this,SLOT(slot_m_button_click()));

    qDebug("[%s:%s:%d] ",__FILE__,__func__, __LINE__);
#if 0
    m_verticalLayout->addWidget(m_myLabel);
    m_verticalLayout->addWidget(m_button);
    m_MyWidget->setLayout(m_verticalLayout);
#else
    m_gridLayout->addWidget(m_myLabel);
    m_gridLayout->addWidget(m_button);
    m_MyWidget->setLayout(m_gridLayout);
#endif

    this->setCentralWidget(m_MyWidget);
#else
    m_myLabel = new MyLabel(":/image/safe_Hover.png",this);
#endif
}

MainWindow::~MainWindow()
{

}

void MainWindow::slot_m_button_click()
{
    if(m_bAnimationStart){
        qDebug("[%s:%s:%d] stop",__FILE__,__func__, __LINE__);
        m_bAnimationStart = false ;
        m_button->setText("start");
        m_myLabel->animationControl(false);
    }else{
        qDebug("[%s:%s:%d] start",__FILE__,__func__, __LINE__);
        m_bAnimationStart = true ;
        m_button->setText("stop");
        m_myLabel->animationControl(true);
    }
}

