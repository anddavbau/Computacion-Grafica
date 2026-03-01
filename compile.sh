export SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
export Programa=P02-115004931

g++ -g "$SCRIPT_DIR/$Programa.cpp" "$SCRIPT_DIR/Mesh.cpp" "$SCRIPT_DIR/Shader.cpp" "$SCRIPT_DIR/Window.cpp" -lGLEW -lGL -lglfw -o "$SCRIPT_DIR/$Programa.out"