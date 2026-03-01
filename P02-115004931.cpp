//Pr�ctica 2: �ndices, mesh, proyecciones, transformaciones geom�tricas
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//clases para dar orden y limpieza al c�digo
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";

static const char* vShaderrojo = "shaders/shaderrojo.vert";
static const char* vShaderzul = "shaders/shaderazul.vert";
static const char* vShaderlima = "shaders/shaderlima.vert";
static const char* vShadermarron = "shaders/shadermarron.vert";
static const char* vShaderverde = "shaders/shaderverde.vert";
//shaders nuevos se crear�an ac�


//Pir�mide triangular regular
void CreaPiramide()
{
	unsigned int indices[] = { 
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3
		
	};
	GLfloat vertices[] = {
		-0.5f, -0.5f,0.0f,	//0
		0.5f,-0.5f,0.0f,	//1
		0.0f,0.5f, -0.25f,	//2
		0.0f,-0.5f,-0.5f,	//3

	};
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);
}

//V�rtices de un cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	// back
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);
}

void CrearLetrasyFiguras()
{
	GLfloat vertices_letra_B[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-1.0f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-1.0f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.9f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.9f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.9f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.9f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.9f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-1.0f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.4f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.4f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.6f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.8f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.7f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.6f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.7f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.5f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.7f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.7f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.5f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.5f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.6f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.5f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.6f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.5f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.5f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.6f,	-0.4f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.3f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.3f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.3f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.9f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.3f,		0.0f,			0.0f,	0.0f,	1.0f,
		-0.7f,	-0.2f,		0.0f,			0.0f,	0.0f,	1.0f
	};
	MeshColor* letra_B = new MeshColor();
	letra_B->CreateMeshColor(vertices_letra_B, 6*51);
	meshColorList.push_back(letra_B);

	GLfloat vertices_letra_N[] = {
		//X			Y			Z			R		G		B
		-0.3f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.3f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.3f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	0.1f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		-0.2f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	-0.1f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.3f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.3f,	-0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.2f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f,
		0.3f,	0.3f,		0.0f,			1.0f,	1.0f,	1.0f
	};
	MeshColor* letra_N = new MeshColor();
	letra_N->CreateMeshColor(vertices_letra_N, 6*18);
	meshColorList.push_back(letra_N);

	GLfloat vertices_letra_A[] = {
		//X			Y			Z			R		G		B
		0.4f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.6f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.55f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.85f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.5f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.9f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.85f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.55f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.6f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	1.0f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.6f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	0.9f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	1.0f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	1.0f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	0.9f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.8f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.7f,	1.0f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.8f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.85f,	0.7f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.8f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.9f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.9f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.9f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		1.0f,	0.4f,		0.0f,			1.0f,	0.0f,	1.0f,
		0.9f,	0.6f,		0.0f,			1.0f,	0.0f,	1.0f
	};
	MeshColor* letra_A = new MeshColor();
	letra_A->CreateMeshColor(vertices_letra_A, 6*30);
	meshColorList.push_back(letra_A);
}


void CreateShaders()
{

	Shader *shader1 = new Shader(); //shader para usar �ndices: objetos: cubo y  pir�mide
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader *shader2 = new Shader();//shader para usar color como parte del VAO: letras 
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);

	Shader* shader3 = new Shader();//shader para usar color rojo 
	shader3->CreateFromFiles(vShaderrojo, fShaderColor);
	shaderList.push_back(*shader3);

	Shader* shader4 = new Shader();//shader para usar color azul
	shader4->CreateFromFiles(vShaderzul, fShaderColor);
	shaderList.push_back(*shader4);

	Shader* shader5 = new Shader();//shader para usar color lima
	shader5->CreateFromFiles(vShaderlima, fShaderColor);
	shaderList.push_back(*shader5);

	Shader* shader6 = new Shader();//shader para usar color marron
	shader6->CreateFromFiles(vShadermarron, fShaderColor);
	shaderList.push_back(*shader6);

	Shader* shader7 = new Shader();//shader para usar color verde
	shader7->CreateFromFiles(vShaderverde, fShaderColor);
	shaderList.push_back(*shader7);
}


int main()
{
	mainWindow = Window(800, 800);
	mainWindow.Initialise();
	CrearLetrasyFiguras(); //usa MeshColor, �ndices en MeshColorList
	CreaPiramide();
	CrearCubo();
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensi�n 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	//glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	
	//Model: Matriz de Dimensi�n 4x4 en la cual se almacena la multiplicaci�n de las transformaciones geom�tricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad
	
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		
													
		//Para las letras hay que usar el segundo set de shaders con �ndice 1 en ShaderList 
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();
		
		//Inicializar matriz de dimensi�n 4x4 que servir� como matriz de modelo para almacenar las transformaciones geom�tricas
		
		//Letra B
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.2f, -0.2f, -5.0f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(-0.2f, 0.2f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[0]->RenderMeshColor();

		//Letra N
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 2.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[1]->RenderMeshColor();

		//Letra A
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.2f, 0.2f, -5.0f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.4f, -0.4f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[2]->RenderMeshColor();

		//Inicializar cubo con color rojo
		shaderList[2].useShader(); 
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, -3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Inicializar piramide con color azul
		shaderList[3].useShader(); 
		uniformModel = shaderList[3].getModelLocation();
		uniformProjection = shaderList[3].getProjectLocation();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.3f, -2.5f));
		model = glm::scale(model, glm::vec3(1.0f, 0.4f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();

		//Inicializar cubos con color lima
		shaderList[4].useShader(); 
		uniformModel = shaderList[4].getModelLocation();
		uniformProjection = shaderList[4].getProjectLocation();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.25f, -0.6f, -2.0f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.25f, -0.6f, -2.0f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, -2.0f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Inicializando cubos de color marron
		shaderList[5].useShader(); 
		uniformModel = shaderList[5].getModelLocation();
		uniformProjection = shaderList[5].getProjectLocation();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.8f, -1.02f, -2.0f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.8f, -1.02f, -2.0f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Inicializando triangulos de color verde
		shaderList[6].useShader(); 
		uniformModel = shaderList[6].getModelLocation();
		uniformProjection = shaderList[6].getProjectLocation();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.8f, -0.5f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.8f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();
		//
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.8f, -0.5f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.8f, 0.05f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();

		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}
// inicializar matriz: glm::mat4 model(1.0);
// reestablecer matriz: model = glm::mat4(1.0);
//Traslaci�n
//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
//////////////// ROTACI�N //////////////////
//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
////////////////  ESCALA ////////////////
//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
///////////////////// T+R////////////////
/*model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));
*/
/////////////R+T//////////
/*model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
*/