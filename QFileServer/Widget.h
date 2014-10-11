#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QtNetwork>
#include <QLabel>
#include <QLineEdit>
#include "MyTcpServer.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void updateLabel(const QByteArray &e);

private:
    MyTcpServer m_tcpServer;
    QLabel *m_label;
    QPushButton *m_quitButton;
    QLineEdit *m_lineEdit;
};

#endif // WIDGET_H
