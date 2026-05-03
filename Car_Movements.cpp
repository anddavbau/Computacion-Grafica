#include "Car_Movements.h"

glm::vec3 Puntos_Pista[]={//Lista de puntos de interes para la pista
    glm::vec3(0.0f,-0.4f,4.0f),
    glm::vec3(-35.0f,-0.4f,4.0f),
    glm::vec3(-52.0f,0.0f,12.0f),
    glm::vec3(-75.0f,4.5f,-5.0f),
    glm::vec3(-110,20.0f,-2.0f),
    glm::vec3(-150,28.0f,-10.0f),
    glm::vec3(-180,26.0f,-20.0f)
};
int puntos_disponibles=sizeof(Puntos_Pista)/sizeof(Puntos_Pista[0]);
int actual_punto=0;
glm::vec3 actual_position = Puntos_Pista[0];
bool X_goingUp = false;
bool Y_goingUp = false;
bool Z_goingUp = false;
bool first_check = false;
GLfloat actual_Y_rotation=0.0f;
GLfloat actual_X_rotation=0.0f;

GLfloat Y_rotate_Carro(GLfloat deltatime,GLfloat offset){
    switch (actual_punto){
        case 1:
            if(actual_Y_rotation<20.0)
                actual_Y_rotation+=deltatime*offset*2.4;
            break;
        case 2:
            if(actual_Y_rotation>-45.0)
                actual_Y_rotation-=deltatime*offset*8.0;
            break;
        case 3:
            if(actual_Y_rotation<10.0)
                actual_Y_rotation+=deltatime*offset*8.0;
            break;
        case 4:
            if(actual_Y_rotation>-20.0)
                actual_Y_rotation-=deltatime*offset*8.0;
        default:
            break;
    }
    return actual_Y_rotation;
}

GLfloat X_rotate_Carro(GLfloat deltatime,GLfloat offset){
    switch (actual_punto){
    case 1:
        if(actual_X_rotation>-5.0)
            actual_X_rotation-=deltatime*offset*0.7;
        break;
    case 2:
        if(actual_X_rotation>-15.0)
            actual_X_rotation-=deltatime*offset*0.5;
        break;
    case 3:
        if(actual_X_rotation>-20.0)
            actual_X_rotation-=deltatime*offset;
        break;
    case 4:
        if(actual_X_rotation<0.0)
            actual_X_rotation+=deltatime*offset;
        break;
    case 5:
        if(actual_X_rotation<5.0)
            actual_X_rotation+=deltatime*offset*0.5;
        break;
    default:
        break;
    }
    return actual_X_rotation;
}

glm::vec3 mover_Carro(GLfloat deltatime,GLfloat offset){
    bool validate[3];
    glm::vec3 next_position;
    if((actual_punto+1)<puntos_disponibles)
        next_position=Puntos_Pista[actual_punto+1];
    else
        return actual_position;
    if(first_check==false){
        first_check=true;
        X_goingUp = (actual_position.x<next_position.x)?true:false;
        Y_goingUp = (actual_position.y<next_position.y)?true:false;
        Z_goingUp = (actual_position.z<next_position.z)?true:false;
    }
    if(X_goingUp){
        if(actual_position.x<next_position.x)
            actual_position.x+=deltatime*offset;
        else
            validate[0]=true;
    }else{
        if(actual_position.x>next_position.x)
            actual_position.x-=deltatime*offset;
        else
            validate[0]=true;
    }
    if(Y_goingUp){
        if(actual_position.y<next_position.y)
            actual_position.y+=deltatime*offset*0.5;
        else
            validate[1]=true;
    }else{
        if(actual_position.y>next_position.y)
            actual_position.y-=deltatime*offset*0.5;
        else
            validate[1]=true;
    }
    if(Z_goingUp){
        if(actual_position.z<next_position.z)
            actual_position.z+=deltatime*offset;
        else
            validate[2]=true;
    }else{
        if(actual_position.z>next_position.z)
            actual_position.z-=deltatime*offset;
        else
            validate[2]=true;
    }
    if(validate[0]==validate[1]==validate[2]==true){
        validate[0]=validate[1]=validate[2]=false;
        actual_punto++;
        first_check = false;
    }
    return actual_position;
}

void reset_mover_Carro(){
    actual_punto = 0;
    first_check = false;
    actual_position = Puntos_Pista[0];
    actual_Y_rotation = actual_X_rotation = 0.0f;
}