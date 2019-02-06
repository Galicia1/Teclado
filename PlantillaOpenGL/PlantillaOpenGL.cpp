// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

float xTriangulo = 0.0f;
float yTriangulo = 0.0f;
float velocidad = 0.05f;

void dibujarTriangulo() {
	glPushMatrix();

	//Transformaciones
	glTranslatef(xTriangulo, yTriangulo, 0.0f);


	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(-0.2f, -0.2f, 1.0f);
	glVertex3f(0.2f, -0.2f, 1.0f);
	glEnd();
	glPopMatrix();
}


void dibujar() {
	dibujarTriangulo();
}

void actualizar() {

}

void teclado_Callback(GLFWwindow*window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		xTriangulo += velocidad;
	}

	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		xTriangulo -= velocidad;
	}

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		yTriangulo -= velocidad;
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		yTriangulo += velocidad;
	}



}


int main()
{
	//Declaramos apuntador de ventana
	//TErminar ejecucion
	GLFWwindow *window;

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//si se pudo iniciar el GLFW
	//entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768,"Ventana", NULL, NULL);
	//si no podemos iniciar la ventana 
	//entonces erminamos la ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}
	const GLubyte * versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	glfwSetKeyCallback(window, teclado_Callback);

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//establecer el color de borrado
		glClearColor(.2, .5, 1, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();
		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

