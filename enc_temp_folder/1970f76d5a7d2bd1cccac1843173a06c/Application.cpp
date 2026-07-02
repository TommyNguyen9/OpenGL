#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "indexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include <filesystem>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "tests/TestClearColor.h"



int main(void)
{
	GLFWwindow* window;

	/* Initialize library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	/* Create windowed mode window & its OpenGL context */
	window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make window's context current*/
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	{

		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCall(glEnable(GL_BLEND));

		//VertexArray va;
		//VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		//VertexBufferLayout layout;
		//layout.Push<float>(2);
		//layout.Push<float>(2);
		//va.AddBuffer(vb, layout);

		//IndexBuffer ib(indices, 6);

		//glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		//glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		//Shader shader("res/shaders/Basic.shader");
		//shader.Bind();
		//shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	

		//std::cout << "Current path: " << std::filesystem::current_path() << std::endl;

		//Texture texture("../res/textures/Cherno.png");
		//texture.Bind();
		//shader.SetUniform1i("u_Texture", 0);

		//va.Unbind();
		//vb.Unbind();
		//ib.Unbind();
		//shader.Unbind();

		Renderer renderer;

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		test::TestClearColor test;

	
		/* Loop until user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			/* Render here */
			renderer.Clear();

			test.OnUpdate(0.0f);
			test.OnRender();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
		
			ImGui::NewFrame();
			test.OnImGuiRender();
			

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front & back buffers */
			glfwSwapBuffers(window);

			/* Poll for & process events */
			glfwPollEvents();
		}

	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;

}
