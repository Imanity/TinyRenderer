#pragma once

#include "Geometry.h"
#include "../Utils/Ray.h"

class Plane : public Geometry {
public:
    Vec3 normal; // 平面法向
    double d; // 平面距原点距离
    Vec3 pos; // 原点在平面上投影

public:
    Plane();
    Plane(Vec3 v, double d_);

    IntersectResult intersect(Ray r);
};
