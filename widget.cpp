#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    :QWidget(parent)
{
    connectbtn = new QPushButton("Connect to Server",this);
    messageFromServerlbl = new QLabel("Message From Server",this);
    messagebox = new QTextEdit(this);
    status = new QLabel("Status",this);
    statuslbl = new QLabel("DisConnect",this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(connectbtn);
    layout->addWidget(messageFromServerlbl);
    layout->addWidget(messagebox);
    layout->addWidget(status);
    layout->addWidget(statuslbl);

    this->setLayout(layout);

    //program
    client = new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),
            this,SLOT(readmessage()));
    connect(client,SIGNAL(connected()),
            this,SLOT(setconnected()));
    connect(connectbtn,SIGNAL(clicked(bool)),
            this,SLOT(clicked()));
}

void Widget::readmessage()
{
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        messagebox->append("Message:"+line);

    }
}

void Widget::setconnected()
{
    statuslbl->setText("Connected");
}

void Widget::clicked()
{
    client->connectToHost("localhost",4444);
}                                     
