#pragma once
#include "Point3D.h"

class Triangle
{
public:
    Triangle(Point3D p1, Point3D p2, Point3D p3);
    ~Triangle();

    Point3D p1();
    Point3D p2();
    Point3D p3();

    void setNormal(Point3D normal);
    Point3D getNormal();

private:
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
    Point3D mNormal;
};
