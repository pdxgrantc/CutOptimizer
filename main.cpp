#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <string>
#include <vector>
#include <iostream>

#include "optimizer/optimize.h"
#include "gui/display.cpp"

static void windowSetup(DrawWidget&, const std::string&);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Optimize *optimizer;
    // Read and process csv data
    try
    {
        optimizer = new Optimize("../test.csv");
        // Continue using optimizer
        optimizer->print();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::string csvName = optimizer->getName();
    std::string windowName = "Cut Optimizer";
    if (!csvName.empty())
    {
        windowName = windowName + " - " + csvName;
    }

    DrawWidget window(optimizer);
    windowSetup(window, windowName);

    return app.exec();
}

void windowSetup(DrawWidget& window, const std::string& windowName)
{

    window.setWindowTitle(QString::fromStdString(windowName));
    window.resize(1900, 1000);
    window.show();
}
