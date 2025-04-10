#include "TestCircle2D.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp> // For glm::pi
#include <cmath>

namespace test
{

    TestCircle2D::TestCircle2D()
        : m_ScreenWidth(960.0f), m_ScreenHeight(540.0f), m_Color(1.0f, 1.0f, 1.0f, 1.0f),
          m_Resolution(50), m_Radius(50.0f)
    {
        m_TranslationC = glm::vec3(0.0f);
        m_VecView = glm::vec3(-200.0f, -200.0f, 0.0f);
        m_Proj = glm::ortho(0.0f, m_ScreenWidth, 0.0f, m_ScreenHeight, -1.0f, 1.0f);

        GenerateCircle();

        m_Shader = std::make_unique<Shader>(RESOURCES_PATH "shaders/Basic.shader");
        m_Shader->Bind();
        m_Shader->SetShaderUniform1i("u_UseTex", 0);
    }

    TestCircle2D::~TestCircle2D()
    {
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void TestCircle2D::GenerateCircle()
    {
        float centerX = m_ScreenWidth / 2.0f;
        float centerY = m_ScreenHeight / 2.0f;

        std::vector<float> positions(2 * (m_Resolution + 1));
        std::vector<unsigned int> indices;

        // Center vertex
        positions[0] = centerX;
        positions[1] = centerY;

        // Perimeter vertices
        for (int i = 1; i <= m_Resolution; ++i)
        {
            float angle = 2.0f * glm::pi<float>() * (float)(i - 1) / m_Resolution;
            float x = centerX + cosf(angle) * m_Radius;
            float y = centerY + sinf(angle) * m_Radius;

            positions[2 * i] = x;
            positions[2 * i + 1] = y;
        }

        // Triangle fan indices
        for (int i = 1; i <= m_Resolution; ++i)
        {
            indices.push_back(0);
            indices.push_back(i);
            indices.push_back((i % m_Resolution) + 1);
        }

        // Upload to GPU
        m_VAO = std::make_unique<VertexArray>();
        m_VB = std::make_unique<VertexBuffer>(positions.data(), positions.size() * sizeof(float));
        m_Layout = std::make_unique<VertexBufferLayout>();
        m_Layout->Push<float>(2);
        m_VAO->AddBuffer(*m_VB, *m_Layout);

        m_IB = std::make_unique<IndexBuffer>(indices.data(), indices.size());
    }

    void TestCircle2D::OnUpdate(float deltatime)
    {
        m_View = glm::translate(glm::mat4(1.0f), m_VecView);
    }

    void TestCircle2D::OnRender()
    {
        Renderer renderer;
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        m_VAO->Bind();
        m_Shader->Bind();

        m_Shader->SetShaderUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], m_Color[3]);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationC);
        glm::mat4 mvp = m_Proj * m_View * model;

        m_Shader->SetShaderUniformMat4f("u_MVP", mvp);

        renderer.Draw(*m_VAO, *m_IB, *m_Shader);
    }

    void TestCircle2D::OnImGuiRender()
    {
        ImGui::ColorEdit4("Color", m_Color);
        ImGui::SliderFloat3("Translation", &m_TranslationC.x, -200.0f, 1000.0f);
        ImGui::SliderFloat3("View Offset", &m_VecView.x, -200.0f, 1000.0f);

        static int lastRes = m_Resolution;
        ImGui::SliderInt("Resolution", &m_Resolution, 3, 200);

        if (lastRes != m_Resolution)
        {
            GenerateCircle(); // Re-generate geometry on resolution change
            lastRes = m_Resolution;
        }

        ImGui::SliderFloat("Radius", &m_Radius, 10.0f, 300.0f);
        if (ImGui::IsItemDeactivatedAfterEdit())
        {
            GenerateCircle(); // Update radius only after sliding stops
        }
    }

}
