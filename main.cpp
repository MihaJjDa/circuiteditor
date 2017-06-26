#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(pieces);

    QApplication app(argc, argv);
    MainWindow window;
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/uds.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/dus.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lrs.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/rls.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/udr.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lrr.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lr.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ud.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/rd.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ld.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/ru.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/lu.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cd.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cl.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cu.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/cr.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/bin/с.jpg");
    window.show();
    return app.exec();
}
