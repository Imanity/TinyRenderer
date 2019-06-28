#pragma once

#include <QWidget>
#include <QPaintEvent>
#include "ui_RenderWidget.h"

#include "Raytracer.h"
#include "Cameras/Perspectivecamera.h"
#include "Cameras/Orthogonalcamera.h"
#include "Lights/Pointlight.h"

enum CAMERA_TYPE {
	PERSPECTIVE_CAMERA, ORTHOGONAL_CAMERA
};

class RenderWidget : public QWidget {
	Q_OBJECT

public:
	RenderWidget(QWidget *parent = Q_NULLPTR);
	~RenderWidget();

public:
	void setWindowSize(int w, int h);
	void setCameraType(CAMERA_TYPE type);

	void render();
	void paintEvent(QPaintEvent *e);

	void setSceneType1();

	void updateScene1Layer(bool leftBall, bool rightBall, bool obj1, bool obj2);

	void moveCamera(Vec3 v);
	void rotateCamera(Vec3 v);

private:
	Ui::RenderWidget ui;

	int w = 200, h = 150;
	CAMERA_TYPE camera_type = PERSPECTIVE_CAMERA;

	QColor **img = NULL; // 视窗
	RayTracer rt; // 光线追踪计算
	Scene scene; // 场景
	PerspectiveCamera p_camera; // 透视投影相机
	OrthogonalCamera o_camera; // 正交投影相机
};
