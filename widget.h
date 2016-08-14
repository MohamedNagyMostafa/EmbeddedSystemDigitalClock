#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QTcpSocket>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent =0);

public Q_SLOTS:
    void clicked();
    void readmessage();
    void setconnected();

private:
    QTcpSocket *client;
    QLabel *statuslbl;
    QLabel *status;
    QTextEdit *messagebox;
    QLabel *messageFromServerlbl;
    QPushButton *connectbtn;
    QPushButton *send;
    QLineEdit *text;
};

#endif // WIDGET_H
