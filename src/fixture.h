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

#ifndef _FIXTURE_H
#define _FIXTURE_H

#include <QVector>
#include <QColor>
#include <QPoint>

class Fixture
{
public:
    Fixture();
    Fixture(unsigned char strand, unsigned char address, unsigned short numPixels);
    ~Fixture();

    void setStart(QPoint start);
    void setEnd(QPoint end);
    void setColors(const QVector<QColor> &colors);
    void getColors(QVector<QColor> *colors);
    double getLength(void);
    double getHeading(void);

private:
    QPoint _start;
    QPoint _end;
    unsigned char _strand;
    unsigned char _address;
    unsigned short _numPixels;

    QVector<QColor> *_pixels;
};

#endif
