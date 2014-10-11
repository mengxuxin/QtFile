#ifndef FORTUNETHREAD_H
#define FORTUNETHREAD_H

#include <QThread>
#include <QTcpSocket>

class FortuneThread : public QThread
{
    Q_OBJECT
public:
    explicit FortuneThread(int socketDescriptor, const QString &text, QObject *parent = 0);

    void run();
    QByteArray Bytearr();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:


private:
    QString m_text;
    int m_socketDescriptor;
    char block[256];
};

#endif // FORTUNETHREAD_H
