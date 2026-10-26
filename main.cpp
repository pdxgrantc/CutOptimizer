#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <string>
#include <vector>
#include <iostream>

#include "optimize/optimize.h"
#include "display.cpp"




int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Optimize optimize("../test.csv");

    DrawWidget window(&optimize);

    window.setWindowTitle("Cut List Optimizer");
    window.resize(1900, 1000);
    window.show();

    return app.exec();
}

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

std::vector<Dimension> loadStocks(Optimize* o) {
    std::vector<Dimension> stockDimensions;

    for (int i = 0; i < o->stocks->getLength(); i++) {
        // Save values locally
        float l, w;
        l = o->stocks->getStock(i)->length;
        w = o->stocks->getStock(i)->width;

        // Find and apply scale factor such that length is always 100
        float scale = 1000 / l;
        w = w * scale;
        l = l * scale;

        // Add to vector of dimensions
        Dimension dim;
        dim.length = l;
        dim.width = w;
        stockDimensions.push_back(dim);
    }

    return stockDimensions;
}
