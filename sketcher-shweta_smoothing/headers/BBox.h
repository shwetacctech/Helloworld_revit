#pragma once
#include <vector>
#include "Triangle.h"

class BBox
{
public:
    BBox(std::vector<Triangle> triangles);
    ~BBox();

    Point3D getCenter();
    double getRadius();

private:
    void calculateBBox(std::vector<Triangle> triangles);
    void compareAndUpdate(Point3D refP, Point3D& min, Point3D& max);

private:
    Point3D mMin;
    Point3D mMax;
    Point3D mCenter;
    double mRadius;
};
