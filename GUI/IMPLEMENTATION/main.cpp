#include <iostream>
#include <MODEL/HEADER/AppKalk.h>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AppKalk* kalk= new AppKalk();
    return app.exec();
}
