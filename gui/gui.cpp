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
#include <QFileDialog>
#include <QLabel>
#include <QProgressBar>
#include <QColor>
#include <vector>
#include <iostream>

#include <QWidget>
#include <QPainter>
#include <string>

#include "../optimizer/optimize.h"
#include "gui.h"

GUI::GUI(QWidget* parent)
    : QWidget(parent)
{
    // QT constructor
    // Create import button
    button = new QPushButton("Import CSV", this);
    button->setGeometry(50, 50, 150, 40);

    // Connect button to file dialogue function
    connect(button, &QPushButton::clicked, this, &GUI::findCSV);

    setupProgressBar();
}

GUI::~GUI()
{
    delete optimizer;
    delete button;

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
    /* TODO uncomment once finished to allow dialogue
    filename = QFileDialog::getOpenFileName(
        this,
        "Select File",
        QDir::homePath(),
        "All Files (*.csv)"
    );
    // Save and initialize optimizer with this file.
    setupOptimizer(filename);
    */

    button->hide();
    progressBar->show();
    progressLabel->show();

    setupOptimizer("../test.csv");
    update();
}

void GUI::setupOptimizer(const QString& filePath)
{

    // Read and process csv data
    // Try to create the optimizer with the filename
    // TODO handle error if the csv is incorrect for some reason
    try
    {
        optimizer = new Optimize(filePath.toStdString());
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

void GUI::setupProgressBar()
{
    progressLabel = new QLabel("Optimizing...", this);
    progressLabel->setGeometry(50, 30, 300, 20);

    // Create progress bar
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(50, 50, 300, 25);

    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    // Hide both initially
    progressLabel->hide();
    progressBar->hide();
}

void GUI::setProgress() const
{
    progressBar->setValue(optimizer->getProgress());
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
