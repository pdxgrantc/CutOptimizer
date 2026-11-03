//
// Created by pdxgr on 11/2/2026.
//

#ifndef CUTOPTIMIZER_DISPLAY_H
#define CUTOPTIMIZER_DISPLAY_H

#include <QPushButton>
#include <QStyleOptionButton>

class DrawWidget : public QWidget {
public:
    explicit DrawWidget(Optimize* optimize, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

private:
    Optimize* optimize;
    QString filename;
    void importCSV();
};;

void drawStocks(QPainter& painter, const Optimize* o);

#endif //CUTOPTIMIZER_DISPLAY_H
