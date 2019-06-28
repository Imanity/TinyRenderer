#pragma once

#include <QColor>

#include <../Utils/Vec3.h>

class PointLight {
public:
    QColor color; // 光颜色
    Vec3 pos; // 点光源位置

public:
    PointLight();
    PointLight(QColor c, Vec3 p);

    Vec3 getL(Vec3 p); // 生成光源至p的光路
};
