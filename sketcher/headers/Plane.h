#pragma once
#include<vector>
#include"Point3D.h"
#include"Triangle.h"
 
class Plane
{
    public:
        Plane();
        Plane(Point3D normalVector, Point3D planePoint3D);
        ~Plane();
        Point3D getNormalVector();
        std::vector<Point3D> getPlanePoint3D();
        std::vector<Point3D> getPointProjectionOnPlane(std::vector<Point3D> points);
        
    private:
       void  getPlaneParameters();
 
    private:
        Point3D mNormalVector;
        std::vector<Point3D> mPlanePoint3D;

};