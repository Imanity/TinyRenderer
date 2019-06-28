#pragma once

#include <QColor>

#include "Scene.h"
#include "Geometries/Plane.h"
#include "Utils/Ray.h"

// Phong模型颜色计算
QColor phong(double kd, double ks, Vec3 l, Vec3 n, Vec3 v, QColor c, int shininess);
// 颜色合成c1+ks*c2
QColor modulate(QColor &c1, QColor &c2, double ks);

class RayTracer {
public:
    RayTracer();

public:
    double eps = 0.01;
    QColor rayTrace(Scene &s, Ray r, int depth);

private:
    bool shadowTest(Scene &s, Ray r, Vec3 pos);
};
