#pragma once

#include "../Utils/Vec3.h"
#include "../Utils/Ray.h"

#define M_PI 3.1416

class OrthogonalCamera {
public:
    Vec3 eye; // 视点
    Vec3 forward, up; // 相机方向
    Vec3 vx, vy, vz; // 视线方向
    double width, height; // 视窗大小

public:
    OrthogonalCamera();
    OrthogonalCamera(Vec3 e, Vec3 f, Vec3 u, double w, double h);
    void initCameraArgs(); // 初始化相机参数

    Ray generateRay(double x, double y); // 生成视点到视窗坐标(x,y)处光线, x和y取值[0,1]
};
