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

#ifndef COLORSPACE_H
#define COLORSPACE_H

void HLSToRGB(float h, float l, float s, float *r, float *g, float *b);
void HueToRGB(float p, float q, float t, float *out);



void HLSToRGB(float h, float l, float s, float *r, float *g, float *b)
{
    if (s == 0.0)
    {
        *r = l;
        *g = l;
        *b = l;
    }
    else
    {
        float q = (l < 0.5) ? (l * (1.0 + s)) : (l + s - (l * s));
        float p = 2.0 * l - q;
        HueToRGB(p, q, (h + 1.0 / 3.0), r);
        HueToRGB(p, q, h, g);
        HueToRGB(p, q, (h - 1.0 / 3.0), b);
    }
}


void HueToRGB(float p, float q, float t, float *out)
{
    float th;

    if (t < 0.0)
        th = t + 1.0;

    if (t > 1.0)
        th = t - 1.0;

    if (t < (1. / 6.))
    {
        *out = p + (q - p) * 6.0 * t;
        return;
    }

    if (t < 0.5)
    {
        *out = q;
        return;
    }

    if (t < (2. / 3.))
    {
        *out = p + (q - p) * ((2. / 3.) - t) * 6.;
        return;
    }

    *out = p;
}

#endif // COLORSPACE_H
