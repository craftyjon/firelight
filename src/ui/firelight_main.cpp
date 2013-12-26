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

    // Connect UI
    connect(btnShowHideControls, SIGNAL(clicked()), this, SLOT(btnShowHideControlsClicked()));
    connect(btnShowHideGrid, SIGNAL(clicked(bool)), this->graphicsView->scene(), SLOT(ShowGrid(bool)));
    connect(btnGridEnlarge, SIGNAL(clicked()), this->graphicsView->scene(), SLOT(IncreaseGridScale()));
    connect(btnGridReduce, SIGNAL(clicked()), this->graphicsView->scene(), SLOT(DecreaseGridScale()));

    _toolsVisible = true;
}


void FirelightMain::quit()
{
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
