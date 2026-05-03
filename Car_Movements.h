#include <GL/glew.h>

#include <glm/glm.hpp>

glm::vec3 mover_Carro(GLfloat deltatime,GLfloat offset);//Mueve por 1 sola ocación el modelo

GLfloat Y_rotate_Carro(GLfloat deltatime,GLfloat offset);//Retorna un angulo en grados
GLfloat X_rotate_Carro(GLfloat deltatime,GLfloat offset);

void reset_mover_Carro();