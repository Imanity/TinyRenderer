#include <QButtonGroup>

#include <iostream>

#include "TinyRenderer.h"

TinyRenderer::TinyRenderer(QWidget *parent)	: QMainWindow(parent) {
	ui.setupUi(this);

	renderer = new RenderWidget(this);

	ui.rendererLayout->addWidget(renderer);

	ui.rendererSettingGroup->setFixedWidth(250);

	cameraRadioGroup = new QButtonGroup(this);
	cameraRadioGroup->addButton(ui.perspectiveRadioButton, 0);
	cameraRadioGroup->addButton(ui.orthogonalRadioButton, 1);

	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	setFixedSize(ui.resolutionValueSlider->maximum() * RESOLUTION_RATE_W  + 250, ui.resolutionValueSlider->maximum() * RESOLUTION_RATE_H);

	connect(ui.resolutionValueSlider, SIGNAL(sliderReleased()), this, SLOT(resizeRenderer()));

	connect(ui.perspectiveRadioButton, SIGNAL(clicked()), this, SLOT(switchCameraType()));
	connect(ui.orthogonalRadioButton, SIGNAL(clicked()), this, SLOT(switchCameraType()));

	connect(ui.LeftBallLayerCheckBox, SIGNAL(clicked()), this, SLOT(updateSceneLayer()));
	connect(ui.RightBallLayerCheckBox, SIGNAL(clicked()), this, SLOT(updateSceneLayer()));
	connect(ui.Obj1LayerCheckBox, SIGNAL(clicked()), this, SLOT(updateSceneLayer()));
	connect(ui.Obj2LayerCheckBox, SIGNAL(clicked()), this, SLOT(updateSceneLayer()));
}

void TinyRenderer::resizeRenderer() {
	int size = ui.resolutionValueSlider->value();
	int w = size * RESOLUTION_RATE_W, h = size * RESOLUTION_RATE_H;
	ui.resolutionValueLabel->setText(QString::number(w) + " * " + QString::number(h));
	renderer->setWindowSize(w, h);
}

void TinyRenderer::switchCameraType() {
	renderer->setCameraType(cameraRadioGroup->checkedId() ? ORTHOGONAL_CAMERA : PERSPECTIVE_CAMERA);
}

void TinyRenderer::updateSceneLayer() {
	renderer->updateScene1Layer(ui.LeftBallLayerCheckBox->isChecked(), ui.RightBallLayerCheckBox->isChecked(), 
		ui.Obj1LayerCheckBox->isChecked(), ui.Obj2LayerCheckBox->isChecked());
}

void TinyRenderer::keyReleaseEvent(QKeyEvent * event) {
	switch (event->key()) {
	case 0x41: // A
		renderer->moveCamera(Vec3(0, -1, 0));
		break;
	case 0x44: // D
		renderer->moveCamera(Vec3(0, 1, 0));
		break;
	case 0x53: // S
		renderer->moveCamera(Vec3(-1, 0, 0));
		break;
	case 0x57: // W
		renderer->moveCamera(Vec3(1, 0, 0));
		break;
	case Qt::Key_Up:
		renderer->rotateCamera(Vec3(0.2, 0, 0));
		break;
	case Qt::Key_Down:
		renderer->rotateCamera(Vec3(-0.2, 0, 0));
		break;
	case Qt::Key_Left:
		renderer->rotateCamera(Vec3(0, -0.2, 0));
		break;
	case Qt::Key_Right:
		renderer->rotateCamera(Vec3(0, 0.2, 0));
		break;
	}
}
