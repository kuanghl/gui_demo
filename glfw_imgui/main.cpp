#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"
#include <iostream>
#include <string>
 
#include <stdio.h>
#include <GLFW/glfw3.h>
 
using namespace std;
 
int main(int argc, char** argv) 
{
	if (!glfwInit())   //初始化OpenGl
		return 1;
 
	//创建OpenGl窗口
 
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL2 example", NULL, NULL);
	if (window == NULL)
		return 1;
 
	//设置OpenGl山下文
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync
 
	// 设置ImGui舌下文.
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
 
 
	//设置颜色风格
	ImGui::StyleColorsDark();
 
 
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
 
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
 
	string str = "Hello, world!";
 
 
	// Main loop
	while (!glfwWindowShouldClose(window))
	{
 
		glfwPollEvents();
 
		// Start the Dear ImGui frame 启动IMgui Frame框架.
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
 
 
		{
			//开始绘制ImGui
 
			ImGui::Begin("IBinary Windows");                          // Create a window called "Hello, world!" and append into it.
			ImGui::Text("IBinary Blog");
			//ImGui::SameLine();
			ImGui::Indent(); //另起一行制表符开始绘制Button
			ImGui::Button("2222", ImVec2(100, 50));
 
			ImGui::InputText("Input Text", &str, ImGuiInputTextFlags_ElideLeft);
 
			ImGui::End();
		}
 
		// 3. Show another simple window.
 
		// Rendering
		ImGui::Render();
 
 
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
 
 
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); //必须在绘制完Open之后接着绘制Imgui
		//glUseProgram(last_program);
 
		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);
	}
 
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
 
	glfwDestroyWindow(window);
	glfwTerminate();
 
	return 0;
}