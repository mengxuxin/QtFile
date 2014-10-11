#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QStringList>
#include <QTcpServer>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr handle);

signals:
    void sendString(QByteArray str);
public slots:

    
private:
    QStringList fortunes;
};

#endif // MYTCPSERVER_H
