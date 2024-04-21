#include "window.h"

#include <QApplication>


int main(int argc, char** argv)
{
    QApplication application(argc, argv);

    Window w;

    w.setWindowTitle("Комп’ютерний магазин");
    w.show();

    return application.exec();
}
