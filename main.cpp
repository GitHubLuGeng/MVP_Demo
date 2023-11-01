#include <QApplication>
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Presenter presenter;
    presenter.showView();

    return a.exec();
}

