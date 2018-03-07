#include <iostream>
#include <GUI/HEADER/kalkmainwindow.h>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    KalkMainWindow* win= new KalkMainWindow();
    win->show();
    return app.exec();
}
