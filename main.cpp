#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(pieces);

    QApplication app(argc, argv);
    MainWindow window;
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/dus.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/ld.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/lr.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/lrs.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/lu.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/rd.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/rls.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/ru.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/ud.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/uds.jpg");
    window.openImage("/home/puchkinda/home/CircuitEditor/CircuitEditor/с.jpg");
    window.show();
    return app.exec();
}
