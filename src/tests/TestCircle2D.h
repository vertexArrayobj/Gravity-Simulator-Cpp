#pragma once

#include "Test.h"

#include <memory>
#include "../Renderer.h"
#include "../Texture.h"
#include "../Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "objects/OCircle.h"
#include <array>
namespace test
{
    class TestCircle2D : public Test
    {
    private:
        float m_ScreenWidth;
        float m_ScreenHeight;
        
        glm::mat4 m_Proj, m_View;
        glm::vec3 m_VecView;

        std::unique_ptr<OCircle> m_Circle;

    public:
        TestCircle2D();
        ~TestCircle2D();

        void OnUpdate(float deltatime) override;
        void OnRender() override;
        void OnImGuiRender() override;
    };

}
