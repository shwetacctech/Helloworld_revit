#include "../headers/Point3D.h"
#include "../headers/Reader.h"
#include <iostream>
#include <sstream>
#include <fstream>

Reader::Reader(std::string filePath)
{
    mFilePath = filePath;
}

Reader::~Reader()
{
}

void Reader::getTriangles(std::vector<Triangle> &triangles)
{
    std::ifstream dataFile;
    dataFile.open(mFilePath);
    if (!dataFile.is_open())
    {
        std::cout << "File not exist" << std::endl;
        return;
    }

    std::string line;
    Point3D normal(0, 0, 0);
    while (std::getline(dataFile, line))
    {
        if (line.find("facet normal") != std::string::npos)
        {
            std::string token;
            std::string toke;
            std::istringstream iss4(line);
            double x, y, z;
            iss4 >> token >> toke >> x >> y >> z;
            normal = Point3D(x, y, z);
        }

        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;

            iss >> token >> x >> y >> z;

            Point3D point1(x, y, z);

            std::getline(dataFile, line);
            std::istringstream iss1(line);
            iss1 >> token >> x >> y >> z;
            Point3D point2(x, y, z);

            std::getline(dataFile, line);
            std::istringstream iss2(line);
            iss2 >> token >> x >> y >> z;
            Point3D point3(x, y, z);

            Triangle triangle(point1, point2, point3);
            triangle.setNormal(normal);
            triangles.push_back(triangle);
        }
    }
    dataFile.close();
}

void Reader::getPoints(std::vector<Point3D> &points)
{
    std::ifstream dataFile;
    dataFile.open(mFilePath);
 
    if (!dataFile.is_open())
    {
        std::cout << "File not exist" << std::endl;
    }
 
    std::string line;
 
    while (std::getline(dataFile, line))
    {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
            iss >> x >> y >> z;
            points.push_back(Point3D(x, y, z));
    }
    dataFile.close();
}
