#pragma once

/**
 * @file display.cpp
 * @brief Window management for Cut List Optimizer
 *
 * @details
 * Contains functions for arranging panels into stock material
 *
 * @author Grant Conklin
 * @date 2026-10-25
 */

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDir>
#include <QDebug>
#include <QPainter>
#include <QFileDialog>
#include <QColor>
#include <vector>
#include <iostream>

#include "../optimizer/optimize.h"
#include "gui.h"

DrawWidget::DrawWidget(Optimize* optimize, QWidget* parent)
    : QWidget(parent), optimize(optimize)
{
    // QT constructor
    // Create button
    QPushButton* button = new QPushButton("Import CSV", this);
    button->setGeometry(50, 50, 150, 40);

    // Connect button to function
    connect(button, &QPushButton::clicked, this, &DrawWidget::importCSV);

}

void DrawWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    //drawStocks(painter, optimize);
}

/*
 * @brief Function to draw basic ux to allow the use to import a csv
 */
void DrawWidget::importCSV()
{
    // 1. Open the file dialog
    filename = QFileDialog::getOpenFileName(
        this,
        "Select File",
        QDir::homePath(),
        "All Files (*.csv)"
    );

    update();
}

void drawStocks(QPainter& painter, const Optimize* o) {
    const std::vector<panel> stocks = o->getStocks();

    int y = 50;

    for (const auto& stock : stocks) {
        constexpr int x = 50;
        painter.setPen(Qt::black);
        painter.setBrush(Qt::green);

        QString label = QString::fromStdString(stock.label);

        // Normalize height and width to for a 1000 length
        constexpr float normalizedLength = 1000;
        const float normalizedWidth = stock.width * (normalizedLength / stock.length);

        QRectF rect(x, y,normalizedLength, normalizedWidth);
        painter.drawRect(rect);

        Qt::Alignment alignment = Qt::AlignCenter;
        painter.drawText(rect, alignment, label);

        // Move down for the next rectangle
        y += static_cast<int>(normalizedWidth) + 20;
    }
}
