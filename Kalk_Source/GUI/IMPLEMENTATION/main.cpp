#include <iostream>
#include <MODEL/HEADER/logic.h>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    logic* win= new logic();
    return app.exec();
}
