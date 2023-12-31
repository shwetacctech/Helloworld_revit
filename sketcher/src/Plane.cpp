#include <cmath>
#include <cstdlib>
#include <iostream>
#include "../headers/Plane.h"

Plane::Plane()
    : mNormalVector(0, 0, 0)
{
   getPlaneParameters();
}



Plane::Plane(Point3D normalVector, Point3D planePoint3D)
    : mNormalVector(normalVector)
{
    this->mPlanePoint3D.push_back(planePoint3D);
}

Plane::~Plane()
{
}

void Plane::getPlaneParameters()
{
    double vX, vY, vZ, pX, pY, pZ;
    std::cout << "Enter Normal Vector :" << std::endl;
    std::cout << "Enter vX :" << std::endl;
    std::cin >> vX;

    std::cout << "Enter vY :" << std::endl;
    std::cin >> vY;

    std::cout << "Enter vZ :" << std::endl;
    std::cin >> vZ;

    mNormalVector = Point3D(vX, vY, vZ);

    std::cout << "Enter Point on the plane :" << std::endl;
    std::cout << "Enter pX :" << std::endl;
    std::cin >> pX;

    std::cout << "Enter pY :" << std::endl;
    std::cin >> pY;

    std::cout << "Enter pZ :" << std::endl;
    std::cin >> pZ;
    mPlanePoint3D.push_back(Point3D(vX, vY, vZ));
}

Point3D Plane::getNormalVector()
{
    return mNormalVector;
}

std::vector<Point3D> Plane::getPlanePoint3D()
{
    return mPlanePoint3D;
}

std::vector<Point3D> Plane::getPointProjectionOnPlane(std::vector<Point3D> points)
{
    std::vector<Point3D> returnPoints;
    const double a = mNormalVector.x();
    const double b = mNormalVector.y();
    const double c = mNormalVector.z();
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));

    Point3D normalised_unit_vector(a / div, b / div, c / div);

    for (auto point : points)
    {
        double tx = point.x();
        double ty = point.y();
        double tz = point.z();

        double x1 = mPlanePoint3D[0].x(), y1 = mPlanePoint3D[0].y(), z1 = mPlanePoint3D[0].z();
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        Point3D pPoint = Point3D((tx + (dist * normalised_unit_vector.x())), (ty + (dist * normalised_unit_vector.y())), (tz + (dist * normalised_unit_vector.z())));
        returnPoints.push_back(pPoint);
    }
    return returnPoints;
}