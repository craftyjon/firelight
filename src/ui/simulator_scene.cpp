// Firelight
// Copyright (c) 2013 Jon Evans
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QDebug>

#include "simulator_scene.h"

SimulatorScene::SimulatorScene() : QGraphicsScene()
{
    // Set Defaults
    _showGrid = true;
    _gridScale = 50;

    this->setSceneRect(-500, -500, 1000, 1000);
}


void SimulatorScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    static QPen thinPen = QPen(QBrush(QColor(150, 150, 150, 255)), 1.0);
    static QPen thickPen = QPen(QBrush(QColor(150, 150, 200, 255)), 3.0);
    float gridpos = 0.0;

    // Grid drawn as part of background if enabled
    if (_showGrid)
    {
        painter->fillRect(rect, QColor(10, 10, 10, 255));
        painter->setPen(thinPen);

        gridpos = (float)((int)rect.left() / _gridScale) * _gridScale;

        while (gridpos < rect.left() + rect.width())
        {
            if (gridpos == 0.0)
                painter->setPen(thickPen);

            painter->drawLine(gridpos, rect.bottom(), gridpos, rect.top());

            if (gridpos == 0.0)
                painter->setPen(thinPen);

            gridpos += _gridScale;
        }

        gridpos = (float)((int)rect.top() / _gridScale) * _gridScale;

        while (gridpos < rect.top() + rect.height())
        {
            if (gridpos == 0.0)
                painter->setPen(thickPen);

            painter->drawLine(rect.left(), gridpos, rect.right(), gridpos);

            if (gridpos == 0.0)
                painter->setPen(thinPen);

            gridpos += _gridScale;
        }
    }
    else
    {
        painter->setBrush(QColor(10, 10, 10, 255));
        painter->drawRect(rect);
    }
}


void SimulatorScene::ShowGrid(bool show)
{
    _showGrid = show;
    update();
}


void SimulatorScene::IncreaseGridScale()
{
    if (_gridScale < MAX_GRID_SCALE) _gridScale += GRID_SCALE_DELTA;
    update();
}


void SimulatorScene::DecreaseGridScale()
{
    if (_gridScale > MIN_GRID_SCALE) _gridScale -= GRID_SCALE_DELTA;
    update();
}
