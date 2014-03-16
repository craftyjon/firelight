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

#include "firelight_main.h"

FirelightMain::FirelightMain(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    _pmgr = new PresetManager();
    _tickTimer = new QTimer(this);

    connectUi();

    _toolsVisible = true;

    _tickTimer->start(33);

}


void FirelightMain::quit()
{
}


void FirelightMain::connectUi()
{
    // Main UI
    connect(btnShowHideControls, SIGNAL(clicked()), this, SLOT(btnShowHideControlsClicked()));

    // Simulator Controls
    connect(btnShowHideGrid, SIGNAL(clicked(bool)), this->graphicsView->scene(), SLOT(ShowGrid(bool)));
    connect(btnGridEnlarge, SIGNAL(clicked()), this->graphicsView->scene(), SLOT(IncreaseGridScale()));
    connect(btnGridReduce, SIGNAL(clicked()), this->graphicsView->scene(), SLOT(DecreaseGridScale()));
    connect(btnCenterView, SIGNAL(clicked()), this->graphicsView, SLOT(centerView()));

    // Preset tick timer
    connect(_tickTimer, SIGNAL(timeout()), this->_pmgr, SLOT(tick()));
    connect(_pmgr, SIGNAL(frameReady(np::ndarray)), this->graphicsView->scene(), SLOT(DrawPresetFrame(np::ndarray)));
}


void FirelightMain::btnShowHideControlsClicked()
{
    if (_toolsVisible) {
        framePresetParams->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        framePresetParams->setMaximumWidth(0);
        btnShowHideControls->setText("\u25C0");
        btnShowHideControls->setToolTip("Show Controls");
        _toolsVisible = false;
    } else {
        framePresetParams->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        framePresetParams->setMaximumWidth(16777215);
        btnShowHideControls->setText("\u25B6");
        btnShowHideControls->setToolTip("Hide Controls");
        _toolsVisible = true;
    }
    btnShowHideControls->clearFocus();
    update();
}
