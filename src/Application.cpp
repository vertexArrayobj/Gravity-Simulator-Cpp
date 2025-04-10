#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GLErrorManager.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "tests/TestClearColor.h"
#include "tests/TestMenu.h"
#include "tests/TestTexture2D.h"
#include "tests/TestCircle2D.h"

int main()
{
	if (!glfwInit())
		return -1;

	GLFWwindow *window = glfwCreateWindow(960, 540, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	ImGui::StyleColorsDark();

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR" << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	glEnable(GL_FRAMEBUFFER_SRGB);

	Renderer renderer;
	test::Test *currentTest = nullptr;
	test::TestMenu *menu = new test::TestMenu(currentTest);
	menu->RegisterTest<test::TestClearColor>("Clear Color");
	menu->RegisterTest<test::TestTexture2D>("2D Texture");
	menu->RegisterTest<test::TestCircle2D>("2D Circle");
	currentTest = menu;

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (currentTest)
		{
			currentTest->OnUpdate(0.0f);
			currentTest->OnRender();
			ImGui::Begin("Test");
			if (currentTest != menu && ImGui::Button("<-"))
			{
				delete currentTest;
				currentTest = menu;
			}
			currentTest->OnImGuiRender();
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	if (currentTest != menu)
		delete menu;
	delete currentTest;

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}