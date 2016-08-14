#include <QApplication>
#include "widget.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    Widget *window = new Widget;
    window->show();
    return app.exec();
}
