#include "splitterwidget.h"
#include <QSplitter>
#include <QTextEdit>
#include <QHBoxLayout>


SplitterWidget::SplitterWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout(this);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal);

    QSplitter *splitterLeft =new QSplitter(Qt::Vertical,splitterMain);
    splitterLeft->setOpaqueResize(false);

    QSplitter *splitterRight =new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);


    QTextEdit *textLeft =new QTextEdit(QObject::tr("Left Widget"),splitterLeft);
    textLeft->setAlignment(Qt::AlignCenter);
    QTextEdit *textUp =new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom =new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(0,1);
    splitterMain->setStretchFactor(1,1);

    splitterRight->setStretchFactor(0,3);
    splitterRight->setStretchFactor(1,1);

    splitterMain->setWindowTitle(QObject::tr("Splitter"));

    hLayout->addWidget(splitterMain);
    this->setLayout(hLayout);
}
