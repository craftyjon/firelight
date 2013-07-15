#ifndef _FIRELIGHT_MAIN_H
#define _FIRELIGHT_MAIN_H

#include <QtCore>
#include <QtGui>
#include <QtGui/QMainWindow>

#include "ui_firelight_main.h"

class FirelightMain : public QMainWindow, private Ui_FirelightMainWindow
{
	Q_OBJECT

public:
	FirelightMain(QWidget *parent = 0);

public slots:
	void quit();

};

#endif
