#include "Perspectivecamera.h"

PerspectiveCamera::PerspectiveCamera() {
    eye = Vec3(0, 0, 0);
    up = Vec3(0, 0, 1);
    forward = Vec3(1, 0, 0);
	fovX = 60;
	fovY = 45;
	initCameraArgs();
}

PerspectiveCamera::PerspectiveCamera(Vec3 e, Vec3 f, Vec3 u, double fovx, double fovy) {
    eye = e;
    forward = f;
    up = u;
	fovX = fovx;
	fovY = fovy;
	initCameraArgs();
}

void PerspectiveCamera::initCameraArgs() {
    up = up.normalize();
    forward = forward.normalize();
    vy = up.negate();
    vz = forward;
    vx = vy.cross(vz);
	fovScaleX = tan(fovX * 0.5 * M_PI / 180.0) * 2;
	fovScaleY = tan(fovY * 0.5 * M_PI / 180.0) * 2;
}

Ray PerspectiveCamera::generateRay(double x, double y) {
    Vec3 x_ = vx.multiply((x - 0.5) * fovScaleX);
    Vec3 y_ = vy.multiply((y - 0.5) * fovScaleY);
    return Ray(eye, forward.add(x_).add(y_).normalize());
}
