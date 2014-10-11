#include <QMessageBox>
#include <QtWidgets>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel;
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->setReadOnly(true);
    m_label->setWordWrap(true);
    m_quitButton = new QPushButton(this);
    m_quitButton->setText("quit");
    connect(m_quitButton, SIGNAL(clicked()), this, SLOT(close()));

    if (!m_tcpServer.listen())
    {
        QMessageBox::critical
                (this, tr("thread server"),
                 tr("unable to start server: %1.").arg(m_tcpServer.errorString()));
        close();
        return;
    }
    connect(&m_tcpServer, SIGNAL(sendString(QByteArray)), this, SLOT(updateLabel(QByteArray)));

    QString ipAdress;
    QList<QHostAddress> ipAdressList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAdressList.count(); ++i)
    {
        if (ipAdressList.at(i) != QHostAddress::LocalHost &&
            ipAdressList.at(i).toIPv4Address())
        {
            ipAdress = ipAdressList.at(i).toString();
            break;
        }
    }

    if (ipAdress.isEmpty())
    {
        ipAdress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    m_label->setText(tr("%1 %2").arg(ipAdress).arg(m_tcpServer.serverPort()));

    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->addStretch(1);
    pHBoxLayout->addWidget(m_quitButton);
    pHBoxLayout->addStretch(1);

    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pVBoxLayout->addWidget(m_label);
    pVBoxLayout->addLayout(pHBoxLayout);
    pVBoxLayout->addWidget(m_lineEdit);

    setLayout(pVBoxLayout);
    setWindowTitle(tr("QtFile"));
}

Widget::~Widget()
{

}

void Widget::updateLabel(const QByteArray &e)
{
    m_lineEdit->setText(e);
}
