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

#include <QDebug>

#include "simulator_view.h"

SimulatorView::SimulatorView(QWidget *parent) : QGraphicsView(parent)
{
    // Init graphics scene
    _scene = new SimulatorScene();
    setScene(_scene);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    setFocusPolicy(Qt::NoFocus);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    _mousePanActive = false;
    _mouseZoomActive = false;
}


void SimulatorView::centerView()
{
    centerOn(0, 0);
}


void SimulatorView::wheelEvent(QWheelEvent *event)
{
    // Trap wheel event to disable scrolling
    Q_UNUSED(event);
}


void SimulatorView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MidButton)
    {
        // Ctrl + middle => Zoom
        if (false)
        {

        }
        // No modifier => Pan
        else
        {
            qDebug() << "Pan start";
            _mousePanActive = true;
            _mousePanStart = event->pos();
        }
    }

    QGraphicsView::mousePressEvent(event);
}


void SimulatorView::mouseReleaseEvent(QMouseEvent *event)
{
    if (_mousePanActive)
    {
        qDebug() << "Pan end";
        _mousePanActive = false;
    }

    QGraphicsView::mouseReleaseEvent(event);
}


void SimulatorView::mouseMoveEvent(QMouseEvent *event)
{
    if (_mousePanActive)
    {
        qDebug() << "Pan";
        QPoint delta = event->pos() - _mousePanStart;
        translate(delta.x(), delta.y());
    }

    QGraphicsView::mouseMoveEvent(event);
}
