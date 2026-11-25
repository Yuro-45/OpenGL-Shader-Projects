#include<iostream>
#include<vector>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm/glm.hpp>

#include"ShaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Texture.h"

const int WIDTH = 800;
const int HEIGHT = 800;

bool wireframe = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_PRESS) return;
	if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(window, true);
	// W = see the grid triangles
	if (key == GLFW_KEY_W)
	{
		wireframe = !wireframe;
		glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
	}
}


// ===================== STEP 1 (YOU) =====================
// Fill `vertices` and `indices` with a grid of cols x rows cells.
// The flag is centred on screen, `width` x `height` in NDC.
// Each vertex = 5 floats:  x, y, z,  u, v
// (Explained in chat)
void BuildGrid(int cols, int rows, float width, float height,
	std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{

}
// ========================================================


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Waving Flag", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	gladLoadGL();
	glViewport(0, 0, WIDTH, HEIGHT);

	Shader shaderProgram("Resources/Shaders/flag.vert", "Resources/Shaders/flag.frag");

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
	BuildGrid(40, 25, 1.5f, 1.0f, vertices, indices);

	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices.data(), vertices.size() * sizeof(GLfloat));
	EBO EBO1(indices.data(), indices.size() * sizeof(GLuint));
	// pos
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	// tex
	VAO1.LinkAttrib(VBO1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint flagTex = loadTexture("Resources/Textures/flag.jpg");
	shaderProgram.Activate();
	glUniform1i(glGetUniformLocation(shaderProgram.ID, "tex0"), 0);


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, flagTex);

		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	glDeleteTextures(1, &flagTex);
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
