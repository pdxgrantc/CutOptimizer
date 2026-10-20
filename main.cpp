#include <QApplication>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <string>
#include <vector>
#include <iostream>

#include "optimize/optimize.h"

struct Dimension {
    float length;
    float width;
};

void drawStocks(QPainter& painter, Optimize* o);
std::vector<Dimension> loadStocks(Optimize* o);

// Progress bar function
QProgressBar* createProgressBar(QWidget* parent = nullptr)
{
    QProgressBar* bar = new QProgressBar(parent);

    bar->setRange(0, 100);
    bar->setValue(0);
    bar->setFormat("%p%");
    bar->setMinimumWidth(300);
    bar->setFixedHeight(25);

    return bar;
}

class DrawWidget : public QWidget {
public:
    explicit DrawWidget(Optimize* optimize, QWidget* parent = nullptr)
        : QWidget(parent), optimize(optimize)
    {
        // Create layout
        QVBoxLayout* layout = new QVBoxLayout(this);

        // Create progress bar
        progressBar = createProgressBar(this);

        // Add progress bar to layout
        layout->addWidget(progressBar);

        // Keep progress bar at the top
        layout->addStretch();

        // Example progress value
        progressBar->setValue(50);
    }

    // Update progress from elsewhere in the program
    void setProgress(int value)
    {
        progressBar->setValue(value);
    }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        QWidget::paintEvent(event);

        QPainter painter(this);

        // Draw stocks
        // drawStocks(painter, optimize);
    }

private:
    Optimize* optimize;
    QProgressBar* progressBar;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Optimize optimize("../test.csv");

    DrawWidget window(&optimize);

    window.setWindowTitle("Cut Optimizer");
    window.resize(1900, 1000);
    window.show();

    return app.exec();
}

void drawStocks(QPainter& painter, Optimize* o)
{
    std::vector<Dimension> stocks = loadStocks(o);

    int x = 50;
    int y = 50;

    for (const auto& stock : stocks) {
        painter.setPen(Qt::black);
        painter.setBrush(Qt::green);

        painter.drawRect(
            QRectF(x, y, stock.length, stock.width)
        );

        y += static_cast<int>(stock.width) + 20;
    }
}

std::vector<Dimension> loadStocks(Optimize* o)
{
    std::vector<Dimension> stockDimensions;

    for (int i = 0; i < o->stocks->getLength(); i++) {
        // Save dimensions for length and width of the current stock
        float l = o->stocks->getStock(i)->length;
        float w = o->stocks->getStock(i)->width;

        // Scale to 1000 as the width
        const float scale = 1000 / l;
        w = w * scale;
        l = l * scale;
        Dimension dim{.length = l, .width = w};

        stockDimensions.push_back(dim);
    }

    return stockDimensions;
}