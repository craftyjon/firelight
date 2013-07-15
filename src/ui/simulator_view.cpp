#include <QDebug>

#include "simulator_view.h"

SimulatorView::SimulatorView(QWidget *parent) : QGraphicsView(parent)
{
	scene = new SimulatorScene();
	this->setScene(scene);
	setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}


void SimulatorView::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->setBrush(QColor(10, 10, 10, 255));
	painter->drawRect(rect);
}