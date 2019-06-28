#pragma once

#include <cmath>

class Vec3 {
public:
	double x, y, z; // 坐标

public:
	Vec3();
	Vec3(double x_, double y_, double z_);

	double length(); // 向量模长
	Vec3 normalize(); // 向量归一化
	Vec3 negate(); // 向量取反

	Vec3 add(Vec3 v); // 向量加法
	Vec3 subtract(Vec3 v); // 向量减法
	Vec3 multiply(double r); // 向量数乘
	Vec3 divide(double r); // 向量数除

	double dot(Vec3 v); // 向量点积
	Vec3 cross(Vec3 v); // 向量叉积
};
