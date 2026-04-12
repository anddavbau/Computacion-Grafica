export SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
export Programa=P06-115004931

g++ -g "$SCRIPT_DIR/$Programa.cpp" "$SCRIPT_DIR/Camera.cpp" "$SCRIPT_DIR/Mesh_tn.cpp" "$SCRIPT_DIR/Model.cpp" "$SCRIPT_DIR/Shader_m.cpp" "$SCRIPT_DIR/Skybox.cpp" "$SCRIPT_DIR/Sphere.cpp" "$SCRIPT_DIR/Texture.cpp" "$SCRIPT_DIR/Window.cpp" -lGLEW -lGL -lglfw -lassimp -o "$SCRIPT_DIR/$Programa.out"