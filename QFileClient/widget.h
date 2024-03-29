#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtNetwork>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void login();
    void logout();

private:
    QLineEdit *m_ServerIP;
    QLineEdit *m_ServerPort;
    QPushButton *m_connect;
    QPushButton *m_disconnect;
    QTcpSocket *m_clientSocket;
};

#endif // WIDGET_H
