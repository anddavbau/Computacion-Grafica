#Dependencias requeridas, g++, GLEW y glfw
#Recomendación de utilizar X11 o en su defecto Wayland con GLEW versión 2.2.0 o inferior y glfw versión 3.3.8 o inferior.

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
FILE_NAME=segundo_main

g++ "$SCRIPT_DIR/$FILE_NAME.cpp" -lGLEW -lGL -lglfw -o "$SCRIPT_DIR/$FILE_NAME.out"
