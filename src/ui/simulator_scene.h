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

#ifndef _SIMULATOR_SCENE_H
#define _SIMULATOR_SCENE_H

#define DEFAULT_GRID_SCALE 20
#define MAX_GRID_SCALE 100
#define MIN_GRID_SCALE 10
#define GRID_SCALE_DELTA 10

#include <QGraphicsScene>
#include <QImage>
#include <QGraphicsPixmapItem>

#include <boost/python.hpp>
#include <boost/numpy.hpp>

#include "ndarray_wrapper.h"

namespace bp = boost::python;
namespace np = boost::numpy;

class SimulatorScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SimulatorScene();

public slots:
    void ShowGrid(bool show);
    void IncreaseGridScale(void);
    void DecreaseGridScale(void);
    void DrawPresetFrame(np::ndarray frame);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    void BlitHLS(NDArrayWrapper<float> frame);

    QImage _img;
    QGraphicsPixmapItem *_pixmap;

    bool _showGrid;
    int _gridScale;

};

#endif
