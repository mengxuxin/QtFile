#include <QString>
#include "MyTcpServer.h"
#include "FortuneThread.h"

MyTcpServer::MyTcpServer(QObject *parent) :
    QTcpServer(parent)
{
    fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent. They only think they are.");
}

void MyTcpServer::incomingConnection(qintptr handle)
{
    QString fortune = fortunes.at(qrand() % fortunes.size());
    FortuneThread *thread = new FortuneThread(handle, fortune, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

    if (!thread->Bytearr().isEmpty())
        emit sendString(thread->Bytearr());
}
