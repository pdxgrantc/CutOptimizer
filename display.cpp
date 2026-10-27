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

#include "optimizer/optimize.h"

struct Dimension {
    float length;
    float width;
};

void drawStocks(QPainter& painter, Optimize* o);
std::vector<Dimension> loadStocks(Optimize* o);

class DrawWidget : public QWidget {
public:
    explicit DrawWidget(Optimize* optimize, QWidget* parent = nullptr)
        : QWidget(parent), optimize(optimize) {
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);

        drawStocks(painter, optimize);
    }

private:
    Optimize* optimize;
};