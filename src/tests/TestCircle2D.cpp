#include "TestCircle2D.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp> // For glm::pi
#include <cmath>
#include "objects/OCircle.h"

namespace test
{

    TestCircle2D::TestCircle2D()
        : m_ScreenWidth(960.0f), m_ScreenHeight(540.0f), m_Color{1.0f, 1.0f, 1.0f, 1.0f},
          m_Resolution(50), m_Radius(50.0f)
    {
        m_VecView = glm::vec3(0.0f, 0.0f, 0.0f);
        m_Proj = glm::ortho(0.0f, m_ScreenWidth, 0.0f, m_ScreenHeight, -1.0f, 1.0f);

        m_Circle = std::make_unique<OCircle>(m_ScreenWidth / 2.0f, m_ScreenHeight / 2.0f, 50.0f, 100);
        m_Circle2 = std::make_unique<OCircle>(m_ScreenWidth / 1.5f, m_ScreenHeight / 2.0f, 50.0f, 4);
    }
    void TestCircle2D::OnUpdate(float deltatime)
    {
        m_View = glm::translate(glm::mat4(1.0f), m_VecView);
    }
    TestCircle2D::~TestCircle2D()
    {
        Renderer::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void TestCircle2D::OnRender()
    {
        Renderer::SetClearColor(1.0f, 0.0f, 0.0f, 1.0f);

        m_Circle->Render(m_Proj, m_View);
        m_Circle2->Render(m_Proj, m_View);
    }

    void TestCircle2D::OnImGuiRender()
    {
    }

}
