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
#include "fixture_item.h"

SimulatorScene::SimulatorScene() : QGraphicsScene()
{
    // Set Defaults
    _showGrid = true;
    _gridScale = DEFAULT_GRID_SCALE;

    setSceneRect(-500, -500, 1000, 1000);

   // FixtureItem *fix = new FixtureItem;
  //  addItem(fix);
}


void SimulatorScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    static QPen thinPen = QPen(QBrush(QColor(150, 150, 150, 255)), 1.0);
    static QPen thickPen = QPen(QBrush(QColor(150, 150, 200, 255)), 3.0);
    float gx = 0.0, gy = 0.0, y = 0.0;

    // Grid drawn as part of background if enabled
    if (_showGrid)
    {
        painter->fillRect(rect, QColor(10, 10, 10, 255));
        painter->setPen(thinPen);

        gx = (float)((int)rect.left() / _gridScale) * _gridScale;
        gy = (float)((int)rect.top() / _gridScale) * _gridScale;

        while (gx < rect.left() + rect.width())
        {
            if (gx == 0.0)
            {
                painter->drawLine(gx, rect.bottom(), gx, rect.top());
            }
            else
            {
                for (y = gy; y <= (rect.top() + rect.height()); y += _gridScale)
                {
                    painter->drawPoint(gx, y);
                }
            }

            gx += _gridScale;
        }

        if ((rect.top() <= 0.0) && ((rect.top() + rect.height()) >= 0.0))
        {
            painter->drawLine(rect.left(), 0.0, rect.right(), 0.0);
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
