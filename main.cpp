#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(pieces);

    QApplication app(argc, argv);
    MainWindow window;
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/uds.jpg", 1);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/dus.jpg", 2);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lrs.jpg", 3);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/rls.jpg", 4);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/udr.jpg", 5);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lrr.jpg", 6);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lr.jpg", 7);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ud.jpg", 8);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/rd.jpg", 9);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ld.jpg", 10);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ru.jpg", 11);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lu.jpg", 12);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cd.jpg", 13);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cl.jpg", 14);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cr.jpg", 15);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cu.jpg", 16);
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/с.jpg", 17);
    window.show();
    return app.exec();
}
