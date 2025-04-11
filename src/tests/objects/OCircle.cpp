#include "OCircle.h"
#include <glm/gtc/constants.hpp> // For glm::pi
#include <glm/gtc/type_ptr.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

OCircle::OCircle(float xpos, float ypos, float radius, int res)
    : m_radius(radius), m_resolution(res)
{
    m_Position = glm::vec3(xpos, ypos, 0.0f);
    GenerateCircle(radius, res);
    std::cout << "circle called" << std::endl;

    Initialize();
}

void OCircle::GenerateCircle(float radius, int res)
{
    m_VertexPositions.clear(); // Clear previous vertex positions
    m_Indices.clear();         // Clear previous indices

    // Center vertex
    m_VertexPositions.push_back(0);
    m_VertexPositions.push_back(0);

    // Perimeter vertices
    for (int i = 0; i < res; ++i) // Loop from 0 to res-1
    {
        float angle = 2.0f * glm::pi<float>() * (float)i / res;
        float x = 0 + cosf(angle) * radius;
        float y = 0 + sinf(angle) * radius;

        m_VertexPositions.push_back(x); // Add x to the vertex list
        m_VertexPositions.push_back(y); // Add y to the vertex list
    }

    // Triangle fan m_Indices
    for (int i = 1; i <= res; ++i)
    {
        m_Indices.push_back(0);
        m_Indices.push_back(i);
        m_Indices.push_back((i % res) + 1);
    }
    Initialize();

    std::cout << "Circle generated with radius: " << radius << " and resolution: " << res << std::endl;
    std::cout << "Vertex count: " << m_VertexPositions.size() / 2 << std::endl;
}