//
// Created by pdxgr on 11/2/2026.
//

#ifndef CUTOPTIMIZER_DISPLAY_H
#define CUTOPTIMIZER_DISPLAY_H

class DrawWidget : public QWidget {
public:
    explicit DrawWidget(Optimize* optimize, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

private:
    Optimize* optimize;
};;

void drawStocks(QPainter& painter, Optimize* o);

#endif //CUTOPTIMIZER_DISPLAY_H
