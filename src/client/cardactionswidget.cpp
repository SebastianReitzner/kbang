#include "cardactionswidget.h"
#include "cardwidget.h"

#include <QPainter>

using namespace client;


CardActionsWidget::CardActionsWidget(QWidget* parent, CardWidget* cardWidget):
        QWidget(parent),
        mp_cardWidget(cardWidget) {
    this->resize(100, 100);
    this->move(500,500);
}

void CardActionsWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(QBrush(QColor(0,0,0,64)));
    painter.drawEllipse(0, 0, 100, 100);
}

