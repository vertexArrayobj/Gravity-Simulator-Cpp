#pragma once

#include "Test.h"

#include <memory>
#include "../Renderer.h"
#include "../Texture.h"
#include "../Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "objects/objCircle.h"
#include <array>
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
        glm::mat4 m_Proj, m_View;
        glm::vec3 m_TranslationC;
        glm::vec3 m_VecView;
        std::array<float, 4> m_Color;

        float m_ScreenWidth;
        float m_ScreenHeight;
        int m_Resolution;
        float m_Radius;
        std::unique_ptr<objCircle> m_Circle;
        std::unique_ptr<objCircle> m_Circle2;

    public:
        TestCircle2D();
        ~TestCircle2D();

        void OnUpdate(float deltatime) override;
        void OnRender() override;
        void OnImGuiRender() override;
        void GenerateCircle(float centerX, float centerY, float radius, int res);
    };

}
