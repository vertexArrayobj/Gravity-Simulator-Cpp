#include "TestCircle2D.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp> // For glm::pi
#include <cmath>
#include "objects/OCircle.h"

namespace test
{
    std::array<float, 4> color = {0.0f, 0.0f, 0.0f, 1.0f};
    glm::vec3 velocity = {0.0f, 0.0f, 0.0f};
    float speed = 0.05f;
    float gravity = -9.81f;

    TestCircle2D::TestCircle2D()
        : m_ScreenWidth(960.0f), m_ScreenHeight(540.0f)
    {
        velocity = {0.0f, 0.0f, 0.0f};
        m_VecView = glm::vec3(0.0f, 0.0f, 0.0f);
        m_Proj = glm::ortho(0.0f, m_ScreenWidth, 0.0f, m_ScreenHeight, -1.0f, 1.0f);
        m_View = glm::translate(glm::mat4(1.0f), m_VecView);
        m_Circle = std::make_unique<OCircle>(m_ScreenWidth / 2.0f, m_ScreenHeight / 2.0f, 50.0f, 100);
    }
    void TestCircle2D::OnUpdate(float deltatime)
    {
        m_Circle->m_Position += velocity * speed;
        velocity.y += gravity;
    }
    TestCircle2D::~TestCircle2D()
    {
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void TestCircle2D::OnRender()
    {
        Renderer::SetClearColor(color[0], color[1], color[2], color[3]);

        m_Circle->Render(m_Proj, m_View);
    }

    void TestCircle2D::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", color.data());
        ImGui::ColorEdit4("Circle Color", m_Circle->m_Color.data());
        ImGui::Text("Circle Position: (%.1f, %.1f)", m_Circle->m_Position.x, m_Circle->m_Position.y);
        ImGui::InputFloat("Move Speed", &speed);

        ImGui::SliderFloat("Circle X", &m_Circle->m_Position.x, 0.0f, m_ScreenWidth);
        ImGui::SliderFloat("Circle Y", &m_Circle->m_Position.y, 0.0f, m_ScreenHeight);

        if (ImGui::SliderFloat("Circle Radius", &m_Circle->m_radius, 0.0f, 100.0f))
        {
            m_Circle->GenerateCircle(m_Circle->m_radius, m_Circle->m_resolution);
        }
        if (ImGui::SliderInt("Circle Resolution", &m_Circle->m_resolution, 3, 100))
        {
            m_Circle->GenerateCircle(m_Circle->m_radius, m_Circle->m_resolution);
        }
    }
}
