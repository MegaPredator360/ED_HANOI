#include "interfaz.h"

int interfaz::menuPrincipal(SDL_Renderer* _renderer)
{
    bool menu_done = false;
    SDL_Event e;
    int n_disks = 3;

    while (!menu_done)
    {
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        _mInterfaz.mostrarTexto(_renderer, "Torres de Hanoi", 220, 120, "ArialNovaCond", 30, { 255, 215, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Usa las feclas direccionales", 150, 190, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, "para cambiar de dificultad:", 160, 220, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, to_string(n_disks), 315, 260, "ArialNovaCond", 30, { 0, 0, 255 });
        _mInterfaz.mostrarTexto(_renderer, "Pulsa ENTER para continuar", 160, 320, "ArialNovaCond", 30, { 0, 0, 0 });

        SDL_RenderPresent(_renderer);

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                menu_done = true;
                n_disks = 8;
            }
            else if (e.type == SDL_KEYDOWN) 
            {
                if (e.key.keysym.sym == SDLK_q) 
                {
                    menu_done = true;
                }
                else if (e.key.keysym.sym == SDLK_RETURN) 
                {
                    menu_done = true;
                }
                else if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_UP) 
                {
                    n_disks++;
                    if (n_disks > 6) 
                    {
                        n_disks = 6;
                    }
                }
                else if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_DOWN) 
                {
                    n_disks--;
                    if (n_disks < 1) 
                    {
                        n_disks = 1;
                    }
                }
            }
        }

        SDL_Delay(1000 / 60); // Cap frame rate to 60 FPS
    }

    return n_disks;
}

void interfaz::juegoTerminado(SDL_Renderer* _renderer, int _dificultad, int _movimientos)
{
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);

    int minMoviminetos = (1 << _dificultad) - 1;
    _mInterfaz.mostrarTexto(_renderer, "¡La partida ha terminado!", 75, 100, "ArialNovaCond", 50, { 255, 215, 0 });
    _mInterfaz.mostrarTexto(_renderer, "Tus movimientos: " + to_string(_movimientos), 210, 270, "ArialNovaCond", 30, { 0, 0, 0 });
    _mInterfaz.mostrarTexto(_renderer, "Movimientos minimos: " + to_string(minMoviminetos), 180, 310, "ArialNovaCond", 30, { 255, 0, 0 });

    if (minMoviminetos == _movimientos) {
        _mInterfaz.mostrarTexto(_renderer, "¡Haz terminado con los movimientos!", 130, 170, "ArialNovaCond", 26, { 0, 128, 0 });
    }

    SDL_RenderPresent(_renderer);
    SDL_Delay(5000);
}
