#pragma once

#include "glm/glm.hpp"
#include <vector>
#include <memory>
#include "../../Renderer.h"
#include "../../Texture.h"
#include "../../Shader.h"

class Object
{
private:
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<VertexBufferLayout> m_Layout;
    std::unique_ptr<VertexBuffer> m_VB;
    std::unique_ptr<IndexBuffer> m_IB;
    std::unique_ptr<Shader> m_Shader;

public:
    void Initialize();
    void Render(glm::mat4 projMat4, glm::mat4 viewMat4);

    glm::vec3 m_Position;
    std::vector<float> m_VertexPositions;
    std::vector<unsigned int> m_Indices;
};