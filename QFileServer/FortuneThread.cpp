#include <QtNetwork>
#include "FortuneThread.h"

FortuneThread::FortuneThread(int socketDescriptor, const QString &text, QObject *parent) :
    QThread(parent),
    m_socketDescriptor(socketDescriptor),
    m_text(text)
{
}

void FortuneThread::run()
{
    QTcpSocket tcpSocket;

    if (!tcpSocket.setSocketDescriptor(m_socketDescriptor))
    {
        emit error(tcpSocket.error());
        return;
    }


    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    tcpSocket.write(block, strlen(block));
    qint64 count = file.write(block);
    file.close();
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}

QByteArray FortuneThread::Bytearr()
{
    return block;
}
