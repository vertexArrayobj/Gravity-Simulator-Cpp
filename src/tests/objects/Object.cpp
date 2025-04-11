#include "Object.h"
#include "../../Renderer.h"
#include "glm/gtc/matrix_transform.hpp"

void Object::Initialize()
{
    m_VAO = std::make_unique<VertexArray>();
    m_VB = std::make_unique<VertexBuffer>(m_VertexPositions.data(), m_VertexPositions.size() * sizeof(float));
    m_Layout = std::make_unique<VertexBufferLayout>();
    m_Layout->Push<float>(2);
    m_VAO->AddBuffer(*m_VB, *m_Layout);

    m_IB = std::make_unique<IndexBuffer>(m_Indices.data(), m_Indices.size());
    m_Shader = std::make_unique<Shader>(RESOURCES_PATH "shaders/Basic.shader");
    m_Shader->Bind();
    m_Shader->SetShaderUniform1i("u_UseTex", 0);
}

void Object::Render(glm::mat4 projMat4, glm::mat4 viewMat4)
{
    Renderer renderer;
    m_VAO->Bind();
    m_Shader->Bind();

    m_Shader->SetShaderUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
    m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Position);
    glm::mat4 mvp = projMat4 * viewMat4 * model;

    m_Shader->SetShaderUniformMat4f("u_MVP", mvp);
    renderer.Draw(*m_VAO, *m_IB, *m_Shader);
}