Nº Cuenta: 115004931

Nombre: Bautista Neyra Andrés David

Utilizando distribución de Linux

# Dependencias requeridas.

- libglew-dev
- libglfw3-dev
- libglm-dev
- libassimp-dev

Revisar el nombre exacto en su gestor de paquetes.

# Notas

Si se utiliza un DE que utiliza Wayland es posible que se reporte un problema relacionado con GLEW asi que se recomienda optar por alguna de estas dos opciones:

- Cambiar en su DE el uso del gestor Wayland por X11.
- Utilizar alguna especie de contenedor de X11.
- Realizar un downgrade a la libreria GLEW a la 2.2.0 (Recomiendo utilizar [distrobox](https://distrobox.it/) para crear un contenedor de Debian 12.)
