#pragma once

#include <QColor>

#include "../Utils/Ray.h"

const int NO_HIT = 0;
const int HIT = 1;

struct IntersectResult {
	int type; // 是否有交(NO_HIT, HIT)
	double t; // 交点到光路起点距离
	Vec3 pos; // 交点坐标
	Vec3 normal; // 交点平面法向

	// For Phong Model
	QColor color; // 交点颜色
	int n;
	double kd, ks;

	IntersectResult() { type = NO_HIT; }
};

class Geometry {
public:
    // For Phong Model
    QColor c;
    int n;
    double kd, ks;

public:
    Geometry();

    void setColor(int r, int g, int b);
    virtual IntersectResult intersect(Ray /*r*/);
};
