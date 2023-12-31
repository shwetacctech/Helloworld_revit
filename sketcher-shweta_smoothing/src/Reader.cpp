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
    while (std::getline(dataFile, line))
    {
        if (line.find("facet normal") != std::string::npos)
        {
            std::istringstream issNormal(line);
            std::string token;
            double x, y, z;

            issNormal >> token >> token >> x >> y >> z;
            Point3D normal(-1 * x, -1 * y, -1 * z);

            std::getline(dataFile, line);
            std::getline(dataFile, line);
            std::istringstream issP1(line);

            issP1 >> token >> x >> y >> z;
            Point3D point1(x, y, z);

            std::getline(dataFile, line);
            std::istringstream issP2(line);

            issP2 >> token >> x >> y >> z;
            Point3D point2(x, y, z);

            std::getline(dataFile, line);
            std::istringstream issP3(line);

            issP3 >> token >> x >> y >> z;
            Point3D point3(x, y, z);

            Triangle triangle(point1, point2, point3);
            triangle.setNormal(normal);
            triangles.push_back(triangle);
        }
    }
    dataFile.close();
}
