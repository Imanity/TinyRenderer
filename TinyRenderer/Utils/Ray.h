#pragma once

#include "Vec3.h"

class Ray {
public:
	Vec3 origin; // 起点
	Vec3 direction; // 方向

public:
	Ray();
	Ray(Vec3 o, Vec3 d);

	Vec3 getPoint(double t); // 获得沿光路距起点t处点
};
