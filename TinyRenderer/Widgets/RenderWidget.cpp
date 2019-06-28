#include <QPainter>
#include <QImage>

#include "RenderWidget.h"

RenderWidget::RenderWidget(QWidget *parent)	: QWidget(parent) {
	ui.setupUi(this);

	setSceneType1();

	setWindowSize(w, h);
}

RenderWidget::~RenderWidget() {
	for (int i = 0; i < this->h; ++i) {
		delete img[i];
		img[i] = NULL;
	}
	delete img;
	img = NULL;
}

void RenderWidget::setWindowSize(int w, int h) {
	if (img != NULL) {
		for (int i = 0; i < this->h; ++i) {
			delete img[i];
			img[i] = NULL;
		}
		delete img;
		img = NULL;
	}
	this->w = w;
	this->h = h;
	img = new QColor *[h];
	for (int i = 0; i < h; ++i) {
		img[i] = new QColor[w];
		for (int j = 0; j < w; ++j) {
			img[i][j] = QColor(255, 255, 255);
		}
	}
	render();
}

void RenderWidget::setCameraType(CAMERA_TYPE type) {
	camera_type = type;
	render();
}

void RenderWidget::render() {
#pragma omp parallel for
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			Ray ray;
			if (camera_type == PERSPECTIVE_CAMERA) {
				ray = p_camera.generateRay((double)i / (double)w, (double)j / (double)h);
			} else {
				ray = o_camera.generateRay((double)i / (double)w, (double)j / (double)h);
			}
			img[j][i] = rt.rayTrace(scene, ray, 0);
		}
	}
	update();
}

void RenderWidget::paintEvent(QPaintEvent *e) {
	Q_UNUSED(e);
	QImage image(400, 300, QImage::Format_RGB888);
	QPainter painter(this);
	for (int i = 0; i < 400; ++i) {
		for (int j = 0; j < 300; ++j) {
			int x = i * w / 400;
			int y = j * h / 300;
			if (x >= w) x = w - 1;
			if (y >= h) y = h - 1;
			image.setPixelColor(i, j, img[y][x]);
		}
	}
	painter.drawImage(0, 0, image);
}

void RenderWidget::setSceneType1() {
	// 设置相机
	p_camera = PerspectiveCamera(Vec3(20, 0, 5), Vec3(-1, 0, 0), Vec3(0, 0, 1), 60, 45);
	o_camera = OrthogonalCamera(Vec3(20, 0, 5), Vec3(-1, 0, 0), Vec3(0, 0, 1), 20, 15);

	// 墙壁
	Plane planes[6];
	// 地板
	planes[0] = Plane(Vec3(0, 0, 1), 0);
	planes[0].setColor(100, 100, 100);
	// 天花板
	planes[1] = Plane(Vec3(0, 0, -1), 15);
	planes[1].setColor(230, 230, 250);
	// 左侧墙壁
	planes[2] = Plane(Vec3(0, 1, 0), 10);
	planes[2].setColor(255, 180, 190);
	// 右侧墙壁
	planes[3] = Plane(Vec3(0, -1, 0), 10);
	planes[3].setColor(100, 90, 200);
	// 后侧墙壁
	planes[4] = Plane(Vec3(1, 0, 0), 10);
	planes[4].setColor(200, 200, 200);
	// 前方墙壁
	planes[5] = Plane(Vec3(-1, 0, 0), 10);
	planes[5].setColor(200, 200, 200);

	for (int i = 0; i < 6; ++i) {
		planes[i].n = 16;
		planes[i].kd = 0.9;
		planes[i].ks = 0.1;
		scene.addPlane(planes[i]);
	}

	// 两个球
	Sphere spheres[2];
	// 左侧球
	spheres[0] = Sphere(Vec3(3, -3, 3), 3);
	spheres[0].setColor(0, 200, 0);
	spheres[0].usingTexture = true;
	spheres[0].texture = ChessTexture(6);
	// 右侧球
	spheres[1] = Sphere(Vec3(-3, 5, 3), 3);
	spheres[1].setColor(200, 0, 0);

	spheres[0].n = 10;
	spheres[0].kd = 0.9;
	spheres[0].ks = 0.1;

	spheres[1].n = 10;
	spheres[1].kd = 0.9;
	spheres[1].ks = 0.3;

	for (int i = 0; i < 2; ++i) {
		scene.addSphere(spheres[i]);
	}

	// obj模型1
	ObjLoader obj1("Charizard.obj", Vec3(-3, -1, 2), 0.4);
	obj1.setColor(200, 50, 20);
	obj1.n = 16;
	obj1.kd = 1;
	obj1.ks = 0;
	scene.addObj(obj1);

	// obj模型2
	ObjLoader obj2("Sword.obj", Vec3(5, 5, 3), 0.1);
	obj2.setColor(50, 50, 50);
	obj2.n = 16;
	obj2.kd = 1;
	obj2.ks = 0.5;
	scene.addObj(obj2);

	// 点光源
	scene.light = PointLight(QColor(255, 255, 255), Vec3(3, 0, 10));
}

void RenderWidget::updateScene1Layer(bool leftBall, bool rightBall, bool obj1, bool obj2) {
	scene.sphere_flag[0] = leftBall;
	scene.sphere_flag[1] = rightBall;
	scene.obj_flag[0] = obj1;
	scene.obj_flag[1] = obj2;
	render();
}

void RenderWidget::moveCamera(Vec3 v) {
	p_camera.eye = p_camera.eye.add(p_camera.forward.multiply(v.x)).add(p_camera.forward.cross(p_camera.up).multiply(v.y));
	o_camera.eye = o_camera.eye.add(o_camera.forward.multiply(v.x)).add(o_camera.forward.cross(o_camera.up).multiply(v.y));

	p_camera.initCameraArgs();
	o_camera.initCameraArgs();

	render();
}

void RenderWidget::rotateCamera(Vec3 v) {
	Vec3 f = p_camera.forward, u = p_camera.up, r = f.cross(u);
	p_camera.forward = f.multiply(cos(v.x)).add(u.multiply(sin(v.x)));
	p_camera.up = u.multiply(cos(v.x)).subtract(f.multiply(sin(v.x)));
	p_camera.forward = p_camera.forward.multiply(cos(v.y)).add(r.multiply(sin(v.y)));

	f = o_camera.forward, u = o_camera.up, r = f.cross(u);
	o_camera.forward = f.multiply(cos(v.x)).add(u.multiply(sin(v.x)));
	o_camera.up = u.multiply(cos(v.x)).subtract(f.multiply(sin(v.x)));
	o_camera.forward = o_camera.forward.multiply(cos(v.y)).add(r.multiply(sin(v.y)));

	p_camera.initCameraArgs();
	o_camera.initCameraArgs();

	render();
}
