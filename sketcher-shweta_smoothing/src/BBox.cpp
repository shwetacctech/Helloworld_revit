#include <iostream>
#include <cmath>
#include "../headers/BBox.h"
#include "../headers/Triangle.h"
#include "../headers/Point3D.h"

BBox::BBox(std::vector<Triangle> triangles)
    : mMin(0, 0, 0),
      mMax(0, 0, 0),
      mCenter(0, 0, 0)
{
    calculateBBox(triangles);
    mRadius = sqrt(pow(mCenter.x() - mMax.x(), 2) + pow(mCenter.y() - mMax.y(), 2) + pow(mCenter.z() - mMax.z(), 2));
}

BBox::~BBox()
{
}

void BBox::calculateBBox(std::vector<Triangle> triangles)
{

    mMax = Point3D(__DBL_MIN__, __DBL_MIN__, __DBL_MIN__);
    mMin = Point3D(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);

    for (Triangle triangle : triangles)
    {
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();

        compareAndUpdate(p1, mMin, mMax);
        compareAndUpdate(p2, mMin, mMax);
        compareAndUpdate(p3, mMin, mMax);
    }

    mCenter = Point3D((mMin.x() + mMax.x()) / 2, (mMin.y() + mMax.y()) / 2, (mMin.z() + mMax.z()) / 2);
}

void BBox::compareAndUpdate(Point3D pointToCompare, Point3D &min, Point3D &max)
{
    if (pointToCompare.x() > max.x())
        max.setX(pointToCompare.x());

    if (pointToCompare.y() > max.y())
        max.setY(pointToCompare.y());

    if (pointToCompare.z() > max.z())
        max.setZ(pointToCompare.z());

    if (pointToCompare.x() < min.x())
        min.setX(pointToCompare.x());

    if (pointToCompare.y() < min.y())
        min.setY(pointToCompare.y());

    if (pointToCompare.z() < min.z())
        min.setZ(pointToCompare.z());
}

Point3D BBox::getCenter()
{
    return mCenter;
}

double BBox::getRadius()
{
    return mRadius;
}
