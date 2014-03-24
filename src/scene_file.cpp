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

#include "scene_file.h"

SceneFile::SceneFile()
{
    _doc = NULL;
    _loaded = false;
}


SceneFile::SceneFile(const QString &fileName)
{
    _doc = NULL;
    _loaded = false;
    load(fileName);

    if (_loaded)
    {
        readData();
    }
}


bool SceneFile::load(const QString &fileName)
{

    if (_loaded)
    {
        qDebug() << "SceneFile load() called but file is already loaded";
        return true;
    }

    QFile sourceFile(fileName);

    if (!sourceFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "Could not open scene file" << fileName;
        return false;
    }

    qDebug() << "Loading scene from" << fileName;

    QByteArray sourceData = sourceFile.readAll();

    _doc = new QJsonDocument(QJsonDocument::fromJson(sourceData));

    //qDebug() << _doc->toJson();

    _loaded = true;
    return true;
}


bool SceneFile::readData()
{
    QJsonArray fixtures = _doc->object()["fixtures"].toArray();

    //() << fixtures;
    return true;
}
