#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

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
    QPushButton *m_connect;
    QPushButton *m_disconnect;
};

#endif // WIDGET_H
