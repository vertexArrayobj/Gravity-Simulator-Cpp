#include "TestCircle2D.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
namespace test
{
    TestCircle2D::TestCircle2D()
        : m_ScreenWidth(960.0f), m_ScreenHeight(540.0f)
    {
        float centerX = m_ScreenWidth / 2.0f;
        float centerY = m_ScreenHeight / 2.0f;
        float radius = 50.0f;
        int res = 100;
        std::vector<float> positions(2 * (res + 1)); // Store x and y for each vertex

        // Calculate positions for the circle's perimeter
        for (int i = 0; i < res; i++)
        {
            float angle = 2.0f * 3.14159265f * ((float)i / res);
            float x = centerX + cosf(angle) * radius;
            float y = centerY + sinf(angle) * radius;
            positions[2 * i] = x;
            positions[2 * i + 1] = y;
        }

        std::vector<unsigned int> indices;
        indices.push_back(0); // Center of the circle (the first vertex is always the center)

        for (int i = 1; i <= res; i++)
        {
            indices.push_back(i);             // First vertex of the triangle (on the perimeter)
            indices.push_back((i % res) + 1); // Next vertex (cycling back to the start)
        }
        indices.push_back(res);

        m_VAO = std::make_unique<VertexArray>();
        m_Layout = std::make_unique<VertexBufferLayout>();
        m_VB = std::make_unique<VertexBuffer>(positions, 2 * (res + 1) * sizeof(float));
        m_Layout->Push<float>(2);
        m_VAO->AddBuffer(*m_VB, *m_Layout);

        m_IB = std::make_unique<IndexBuffer>(indices.begin(), indices.size());
        m_Shader = std::make_unique<Shader>(RESOURCES_PATH "shaders/Basic.shader");

        m_translationC = glm::vec3(0, 0, 0.0f);
        m_proj = glm::ortho(0.0f, m_ScreenWidth, 0.0f, m_ScreenHeight, -1.0f, 1.0f);
        m_VIEW = glm::vec3(-200.0, -200.0, 0.0f);
        m_view = glm::translate(glm::mat4(1.0f), m_VIEW);

        m_Shader->SetShaderUniform1i("u_UseTex", 0);
    }

    TestCircle2D::~TestCircle2D()
    {
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void TestCircle2D::OnUpdate(float deltatime)
    {
        m_view = glm::translate(glm::mat4(1.0f), m_VIEW);
    }

    void TestCircle2D::OnRender()
    {
        Renderer renderer;
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        m_VAO->Bind();
        m_Shader->Bind();
        m_Shader->SetShaderUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], m_Color[3]);

        glm::mat4 model;
        glm::mat4 mvp;

        model = glm::translate(glm::mat4(1.0f), m_translationC);
        mvp = m_proj * m_view * model;
        m_Shader->SetShaderUniformMat4f("u_MVP", mvp);

        renderer.Draw(*m_VAO, *m_IB, *m_Shader);
    }

    void TestCircle2D::OnImGuiRender()
    {
        ImGui::ColorPicker4("Color", m_Color);
        ImGui::SliderFloat3("TranslationC", &m_translationC.x, -200.0f, 1000.0f);
        ImGui::SliderFloat3("View", &m_VIEW.x, -200.0f, 1000.0f);
    }
}