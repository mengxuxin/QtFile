#include <QVBoxLayout>
#include <QHBoxLayout>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_ServerIP(NULL),
      m_connect(NULL),
      m_disconnect(NULL)
{
    m_ServerIP = new QLineEdit(this);
    m_connect = new QPushButton(this);
    m_disconnect = new QPushButton(this);

    m_connect->setText("logIN");
    m_disconnect->setText("logOUT");

    connect(m_connect, SIGNAL(clicked()), this, SLOT(login()));
    connect(m_disconnect, SIGNAL(clicked()), this, SLOT(logout()));

    QVBoxLayout *pVLayout = new QVBoxLayout();
    QHBoxLayout *pHLayout = new QHBoxLayout();

    pVLayout->addWidget(m_connect);
    pVLayout->addWidget(m_disconnect);
    pHLayout->addWidget(m_ServerIP);
    pHLayout->addLayout(pVLayout);

    this->setLayout(pHLayout);
}

Widget::~Widget()
{

}

void Widget::login()
{

}

void Widget::logout()
{

}
