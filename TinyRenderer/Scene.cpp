#include "Scene.h"

Scene::Scene() {

}

void Scene::addPlane(Plane p) {
    planes.push_back(p);
	plane_flag.push_back(true);
}

void Scene::addSphere(Sphere s) {
    spheres.push_back(s);
	sphere_flag.push_back(true);
}

void Scene::addObj(ObjLoader o) {
    objs.push_back(o);
	obj_flag.push_back(true);
}

IntersectResult Scene::intersect(Ray r) {
    double minT = -1;
    IntersectResult minRes = IntersectResult();
    for (int i = 0; i < planes.size(); ++i) {
		if (!plane_flag[i]) continue;
        IntersectResult tmpRes = planes[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    for (int i = 0; i < spheres.size(); ++i) {
		if (!sphere_flag[i]) continue;
        IntersectResult tmpRes = spheres[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    for (int i = 0; i < objs.size(); ++i) {
		if (!obj_flag[i]) continue;
        IntersectResult tmpRes = objs[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    return minRes;
}
