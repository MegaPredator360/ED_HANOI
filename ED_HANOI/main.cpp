#include "juego.h"

int main(int argc, char* argv[])
{
    // Llamados a las clases
    interfaz _interfaz;
    juego _juego;
    int dificultad;
    int movimientos;

    // Se inicializan los datos para cargar la ventana
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* ventana = SDL_CreateWindow("Towers of Hanoi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderizador = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();

    while (1)
    {
        dificultad = _interfaz.menuPrincipal(renderizador);

        if (dificultad != 8)
        {
            movimientos = _juego.iniciarJuego(dificultad, renderizador);
            _interfaz.juegoTerminado(renderizador, dificultad, movimientos);
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
    std::exit(0);

    return 0;
}