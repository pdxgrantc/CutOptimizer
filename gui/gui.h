//
// Created by pdxgr on 11/2/2026.
//

#ifndef CUTOPTIMIZER_DISPLAY_H
#define CUTOPTIMIZER_DISPLAY_H

#include <QPushButton>
#include <QStyleOptionButton>
#include "../optimizer/optimize.h"

class GUI : public QWidget {
public:
    explicit GUI(QWidget* parent = nullptr);
    ~GUI() override;

protected:
    void paintEvent(QPaintEvent* event);

private:
    Optimize *optimizer{};
    QString filename;
    void findCSV();
    void setupOptimizer(const QString& filename);
    void drawStocks(QPainter& painter) const;
};

#endif //CUTOPTIMIZER_DISPLAY_H
