#include "objCircle.h"
#include <glm/gtc/constants.hpp> // For glm::pi
#include <glm/gtc/type_ptr.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

objCircle::objCircle(float centerX, float centerY, float radius, int res)
{
    position = glm::vec3(0.0f);

    // Center vertex
    vertexPos.push_back(centerX);
    vertexPos.push_back(centerY);

    // Perimeter vertices
    for (int i = 0; i < res; ++i) // Loop from 0 to res-1
    {
        float angle = 2.0f * glm::pi<float>() * (float)i / res;
        float x = centerX + cosf(angle) * radius;
        float y = centerY + sinf(angle) * radius;

        vertexPos.push_back(x); // Add x to the vertex list
        vertexPos.push_back(y); // Add y to the vertex list
    }

    // Triangle fan indices
    for (int i = 1; i <= res; ++i)
    {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back((i % res) + 1);
    }

    std::cout << "circle called" << std::endl;

    Initialize();
}
