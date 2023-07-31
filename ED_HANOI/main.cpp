#include "juego.h"

int main(int argc, char* argv[])
{
    // Llamados a las clases
    interfaz _interfaz;
    juego _juego;
    int dificultad;
    int movimientos;
    bool confirmacion = true;

    // Se inicializan los datos para cargar la ventana
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* ventana = SDL_CreateWindow("Torres de Hanoi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderizador = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();

    while (confirmacion)
    {
        dificultad = _interfaz.menuPrincipal(renderizador);

        if (dificultad != 8)
        {
            movimientos = _juego.iniciarJuego(dificultad, renderizador);

            if (movimientos != 0)
            {
                confirmacion = _interfaz.juegoTerminado(renderizador, dificultad, movimientos);
            }
            else
            {
                break;
            }
            
        }
        else
        {
            break;
        }
        
    }
    
    // Liberamos recursos
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(ventana);
    TTF_Quit();
    SDL_Quit();

    // Terminamos el programa
    exit(0);

    return 0;
}