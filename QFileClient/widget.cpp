#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_ServerIP(NULL),
      m_connect(NULL),
      m_disconnect(NULL),
      m_clientSocket(NULL)
{
    m_ServerIP = new QLineEdit(this);
    m_ServerPort = new QLineEdit(this);
    m_connect = new QPushButton(this);
    m_disconnect = new QPushButton(this);
    m_clientSocket = new QTcpSocket(this);

    m_connect->setText("logIN");
    m_disconnect->setText("logOUT");

    connect(m_connect, SIGNAL(clicked()), this, SLOT(login()));
    connect(m_disconnect, SIGNAL(clicked()), this, SLOT(logout()));

    QVBoxLayout *pVLayout = new QVBoxLayout();
    QHBoxLayout *pHLayout = new QHBoxLayout();

    pHLayout->addWidget(m_connect);
    pHLayout->addWidget(m_disconnect);
    pVLayout->addWidget(m_ServerIP);
    pVLayout->addWidget(m_ServerPort);
    pVLayout->addLayout(pHLayout);

    this->setLayout(pVLayout);
}

Widget::~Widget()
{

}

void Widget::login()
{
    char *data = "mengxuxin";
    if (m_ServerIP->text().trimmed().isEmpty())
    {
        return;
    }
    try
    {
        m_clientSocket->connectToHost(QHostAddress(m_ServerIP->text()), m_ServerPort->text().toInt());
        m_clientSocket->write(data);
    }
    catch(QException &e)
    {
        QMessageBox::about(this, "cuole", "e");
    }
}

void Widget::logout()
{

}
