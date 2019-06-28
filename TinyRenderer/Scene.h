#pragma once

#include <vector>

#include "Utils/Ray.h"
#include "Geometries/Plane.h"
#include "Geometries/Sphere.h"
#include "Geometries/Objloader.h"
#include "Lights/pointlight.h"

class Scene {
public:
    std::vector<Plane> planes;
    std::vector<Sphere> spheres;
    std::vector<ObjLoader> objs;

	std::vector<bool> plane_flag;
	std::vector<bool> sphere_flag;
	std::vector<bool> obj_flag;

    PointLight light;

public:
    Scene();

    void addPlane(Plane p);
    void addSphere(Sphere s);
    void addObj(ObjLoader o);
    IntersectResult intersect(Ray r);
};
