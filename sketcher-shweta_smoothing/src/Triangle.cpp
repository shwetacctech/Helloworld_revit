#include "../headers/Triangle.h"
#include "../headers/Point3D.h"

Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3)
    : mP1(0, 0, 0),
      mP2(0, 0, 0),
      mP3(0, 0, 0),
      mNormal(0, 0, 0)
{
    mP1 = p1;
    mP2 = p2;
    mP3 = p3;
}

Triangle::~Triangle()
{
}

Point3D Triangle::p1()
{
    return mP1;
}

Point3D Triangle::p2()
{
    return mP2;
}

Point3D Triangle::p3()
{
    return mP3;
}

Point3D Triangle::getNormal()
{
    return mNormal;
}

void Triangle::setNormal(Point3D inNormal)
{
    mNormal = inNormal;
}
