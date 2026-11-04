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

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <string>
#include <iostream>
#include <regex>

#include "../optimizer/optimize.h"
#include "gui.h"

GUI::GUI(QWidget* parent)
    : QWidget(parent)
{
    // QT constructor
    // Create import button
    auto* button = new QPushButton("Import CSV", this);
    button->setGeometry(50, 50, 150, 40);

    // Connect button to file dialogue function
    connect(button, &QPushButton::clicked, this, &GUI::findCSV);
}

GUI::~GUI()
{
    delete optimizer;
}

void GUI::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    //drawStocks(painter, optimize);
}

/*
 * @brief Function to draw basic ux to allow the use to import a csv
 */
void GUI::findCSV()
{
    // 1. Open the file dialog
    filename = QFileDialog::getOpenFileName(
        this,
        "Select File",
        QDir::homePath(),
        "All Files (*.csv)"
    );

    // Save and initialize optimizer with this file.
    setupOptimizer(filename);

    update();
}

void GUI::setupOptimizer(const QString& filename)
{

    // Read and process csv data
    // Try to create the optimizer with the filename
    // TODO handle error if the csv is incorrect for some reason
    try
    {
        optimizer = new Optimize("../test.csv");
        // TODO remove once done
        //optimizer = new Optimize(filename.toStdString());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Pull project name from the csv if it exists
    const std::string csvName = optimizer->getName();
    std::string windowName = "Cut Optimizer";
    if (!csvName.empty())
    {
        windowName = windowName + " - " + csvName;
    }

    // Window setup
    setWindowTitle(QString::fromStdString(windowName));
}

void GUI::drawStocks(QPainter& painter) const
{
    const std::vector<panel> stocks = optimizer->getStocks();

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
