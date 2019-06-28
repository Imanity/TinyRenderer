#pragma once

#include <fstream>
#include <vector>

#include "Geometry.h"

#define M_PI 3.1416

class ObjLoader : public Geometry {
public:
	std::vector<Vec3> vSets; // 顶点集
    std::vector<Vec3> fSets; // 面集

public:
    ObjLoader();
    ObjLoader(std::string filename, Vec3 center/*位置*/, double r/*大小*/);

    IntersectResult intersect(Ray r);

private:
    bool isInPolygon(Vec3 p, Vec3 a, Vec3 b, Vec3 c, Vec3 n); // 判断点p是否在三角形abc内
};
