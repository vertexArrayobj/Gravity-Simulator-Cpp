#pragma once

#include "Test.h"

#include <memory>
#include "../Renderer.h"
#include "../Texture.h"
#include "../Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test
{
    class TestCircle2D : public Test
    {
    private:
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<VertexBufferLayout> m_Layout;
        std::unique_ptr<VertexBuffer> m_VB;
        std::unique_ptr<IndexBuffer> m_IB;
        std::unique_ptr<Shader> m_Shader;

        glm::mat4 m_proj, m_view;
        glm::vec3 m_translationC;
        float m_Color[4];
        glm::vec3 m_VIEW;

        float m_ScreenWidth;
        float m_ScreenHeight;

    public:
        TestCircle2D();
        ~TestCircle2D();

        void OnUpdate(float deltatime) override;
        void OnRender() override;
        void OnImGuiRender() override;
    };

}
