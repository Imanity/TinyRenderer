#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_TinyRenderer.h"

#include "Widgets/RenderWidget.h"

const int RESOLUTION_RATE_W = 4;
const int RESOLUTION_RATE_H = 3;

class TinyRenderer : public QMainWindow {
	Q_OBJECT

public:
	TinyRenderer(QWidget *parent = Q_NULLPTR);

	void keyReleaseEvent(QKeyEvent * event);

public slots:
	void resizeRenderer();
	void switchCameraType();
	void updateSceneLayer();

private:
	Ui::TinyRendererClass ui;

	RenderWidget *renderer;

	QButtonGroup *cameraRadioGroup;
};
