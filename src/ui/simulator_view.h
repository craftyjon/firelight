#ifndef _SIMULATOR_VIEW_H
#define _SIMULATOR_VIEW_H

#include <QGraphicsView>

#include "simulator_scene.h"

class SimulatorView : public QGraphicsView
{
	Q_OBJECT

public:
	SimulatorView(QWidget *parent = 0);

protected:
	void drawBackground(QPainter *painter, const QRectF &rect);

private:
	SimulatorScene *scene;
};

#endif
