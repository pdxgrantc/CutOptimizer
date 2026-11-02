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
#include <QPainter>
#include <QColor>
#include <string>
#include <vector>
#include <iostream>

#include "../optimizer/optimize.h"
#include "gui.h"



DrawWidget::DrawWidget(Optimize* optimize, QWidget* parent)
    : QWidget(parent), optimize(optimize)
{
}

void DrawWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    drawStocks(painter, optimize);
}

void drawStocks(QPainter& painter, Optimize* o) {
    const std::vector<panel> stocks = o->getStocks();

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

