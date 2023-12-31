#include <iostream>
#include <vector>
#include "headers/Reader.h"
#include "headers/Triangle.h"
#include "headers/Triangulation.h"
#include "headers/Writer.h"
#include "headers/Smoother.h"

int main()
{
    std::vector<Triangle> triangles;
    Reader reader("resources/cubeModel.stl");
    reader.getTriangles(triangles);

    Triangulation triangulation(triangles);

    int featureId;
    std::cout << "Enter the feature ID: " << std::endl
              << "1. Surface area " << std::endl
              << "2. Mirror " << std::endl
              << "3. Bounding box " << std::endl
              << "4. Translate " << std::endl
              << "5. Rotate " << std::endl
              << "6. Scale " << std::endl
              << "7. Half section " << std::endl
              << "8. Convex Hull " << std::endl
              << "9. Intersection boundary " << std::endl
              << "10. Smoothing " << std::endl
              << "11. Explode " << std::endl
              << "12. Mesh Quality check" << std::endl;

    std::cin >> featureId;
    switch (featureId)
    {
    case 10:
    {        
        Smoother smoother(triangulation);
        smoother.smoothing(triangles);
        break;
    }
    default:
    {
        std::cout << "Default cased." << std::endl;
        break;
    }
    }

    Writer writer;
    writer.write("output/output.txt", triangles);
}
