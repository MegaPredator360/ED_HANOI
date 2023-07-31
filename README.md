# Tarea de "Torre de Hanoi" - en Inteface
Este es una recreacion del juego "Torres de Hanoi" escrito en C++ usando SDL2

## Descripción
Como mencioné al inicio esta es una recreacion del juego "Torres de Hanoi" en C++, donde podrás escojer 6 niveles de dificultas, se controla con el teclado.
Teclas especiales:
- **R**: Reinicia al partida
- **Q** o **ESC**: Cerrará el programa

## Instalación
Para la instalacion de proyecto se necesita:
- Visual Studio 2022: Con la carga de trabajo **"Desarrollo para el escritorio con C++"**.
- [SDL2](https://github.com/libsdl-org/SDL/releases). Favor descargar el archivo con el nombre **SDL2-devel-2.xx.x-VC.zip**, y extraer su contenido en la siguiente ruta **C:\Dev\SDL2**
- [SDL-ttf](https://github.com/libsdl-org/SDL_ttf/releases). Favor descargar el archivo con el nombre **SDL2_ttf-devel-2.xx.x-VC.zip**, y extraer su contenido en la siguiente ruta **C:\Dev\SDL2_ttf**
*Nota:* Si extraes el contenido de los .zip en una ruta distinta, favor cambiar en las propiedades del proyecto la ruta de donde se encuentran ubicados los archivos.
Para cambiar la ruta debes de ir a las propiedades del proyecto: **Propiedades de configuración > C/C++ > General > Directorios de inclusión adicionales**, cambias la ruta de ambas librerias seleccionando la carpeta **include**, y tambien cambiar la siguiente ruta en las propiedades del proyecto: **Propiedades de configuración > Vinculador (o Linker tienes VS en Ingles) > General > Directorios de bibliotecas adicionales**, tambien cambiar la ruta de ambas librerias entrando a la carpeta de **lib** y seleccionando **x64**, con eso, ya podrás ejecutar el programa.
