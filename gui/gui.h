//
// Created by Grant on 11/2/2026.
//

#ifndef CUTOPTIMIZER_DISPLAY_H
#define CUTOPTIMIZER_DISPLAY_H

#include <QPushButton>
#include <QProgressBar>
#include <QStyleOptionButton>
#include "../optimizer/optimize.h"

class GUI : public QWidget {
public:
    explicit GUI(QWidget* parent = nullptr);
    ~GUI() override;

protected:
    void paintEvent(QPaintEvent* event);

private:
    Optimize *optimizer = nullptr;
    QString filename; // used to save the csv filepath upon import
    QLabel* progressLabel = nullptr;

    // Visible elements
    QPushButton* button = nullptr;
    QProgressBar* progressBar = nullptr;

    void findCSV();
    void setupOptimizer(const QString&);
    void drawStocks(QPainter& painter) const;
    void setProgress() const;
    void setupProgressBar();
};

#endif //CUTOPTIMIZER_DISPLAY_H
