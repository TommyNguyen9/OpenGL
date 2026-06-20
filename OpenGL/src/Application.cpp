#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow* window;

	/* Initialize library */
	if (!glfwInit())
		return -1;

	/* Create windowed mode window & its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make window's context current*/
	glfwMakeContextCurrent(window);

	/* Loop until user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front & back buffers */
		glfwSwapBuffers(window);

		/* Poll for & process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}
