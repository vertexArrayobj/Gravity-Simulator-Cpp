#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	GLFWwindow *window;

	/* Initialize GLFW */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(960, 540, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	if (glewInit() != GLEW_OK)
		std::cout << "ERROR" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();
}