#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <string>
#include <vector>
#include <iostream>

#include "optimizer/optimize.h"
#include "display.cpp"


int main(int argc, char* argv[])
{
    //QApplication app(argc, argv);

    // Read and process csv data
    try
    {
        Optimize Optimize("../test.csv");

        // Continue using optimizer
        Optimize.print();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    /*
    DrawWidget window(&optimize);
    window.setWindowTitle("Cut List Optimizer");
    window.resize(1900, 1000);
    window.show();

    return app.exec();
    */
}

/*
void drawStocks(QPainter& painter, Optimize* o) {
    std::vector<Dimension> stocks = loadStocks(o);

    int x = 50;
    int y = 50;

    for (const auto& stock : stocks) {
        painter.setPen(Qt::black);
        painter.setBrush(Qt::green);

        painter.drawRect(
            QRectF(x, y, stock.length, stock.width)
        );

        // Move down for the next rectangle
        y += static_cast<int>(stock.width) + 20;
    }
}
*/
