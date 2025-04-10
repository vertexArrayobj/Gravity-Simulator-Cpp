#pragma once

#include "glm/glm.hpp"
#include <vector>
#include <memory>
#include "../../Renderer.h"
#include "../../Texture.h"
#include "../../Shader.h"

class obj
{
private:
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<VertexBufferLayout> m_Layout;
    std::unique_ptr<VertexBuffer> m_VB;
    std::unique_ptr<IndexBuffer> m_IB;
    std::unique_ptr<Shader> m_Shader;

public:
    void Initialize();
    void Render(glm::mat4 projMat4, glm::mat4 viewjMat4);

    glm::vec3 position;
    std::vector<float> vertexPos;
    std::vector<unsigned int> indices;
};