#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <string>
#include <iostream>
#include <regex>

#include "optimizer/optimize.h"
#include "gui/gui.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GUI window;
    window.resize(1900, 1000);
    window.setWindowTitle("Cut Optimizer");
    window.show();

    // Kick off qt window and return exit code
    return QApplication::exec();
}
