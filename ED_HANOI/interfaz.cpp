#include "interfaz.h"

int interfaz::menuPrincipal(SDL_Renderer* _renderer)
{
    menuTerminado = false;
    dificultad = 3;

    while (!menuTerminado)
    {
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        _mInterfaz.mostrarTexto(_renderer, "Torres de Hanoi", 157, 122, "ArialNovaCond", 50, { 175, 175, 175 });
        _mInterfaz.mostrarTexto(_renderer, "Torres de Hanoi", 155, 120, "ArialNovaCond", 50, { 255, 215, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Usa las feclas direccionales", 150, 190, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, "para cambiar de dificultad:", 160, 220, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, to_string(dificultad), 315, 260, "ArialNovaCond", 30, { 0, 0, 255 });
        _mInterfaz.mostrarTexto(_renderer, "Pulsa ENTER para continuar", 150, 320, "ArialNovaCond", 30, { 0, 0, 0 });

        SDL_RenderPresent(_renderer);

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                dificultad = 8;
                menuTerminado = true;
            }
            else if (e.type == SDL_KEYDOWN) 
            {
                if (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    dificultad = 8;
                    menuTerminado = true;
                }
                else if (e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_KP_ENTER)
                {
                    menuTerminado = true;
                }
                else if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_UP) 
                {
                    dificultad++;

                    if (dificultad >= 7) 
                    {
                        dificultad = 1;
                    }
                }
                else if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_DOWN) 
                {
                    dificultad--;

                    if (dificultad <= 0)
                    {
                        dificultad = 6;
                    }
                }
            }
        }

        SDL_Delay(1000 / 60); // Cap frame rate to 60 FPS
    }

    return dificultad;
}

bool interfaz::juegoTerminado(SDL_Renderer* _renderer, int _dificultad, int _movimientos)
{
    menuTerminado = false;

    while (!menuTerminado)
    {
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        minMovimientos = (1 << _dificultad) - 1;
        _mInterfaz.mostrarTexto(_renderer, "¡La partida ha terminado!", 77, 52, "ArialNovaCond", 50, { 175, 175, 175 });
        _mInterfaz.mostrarTexto(_renderer, "¡La partida ha terminado!", 75, 50, "ArialNovaCond", 50, { 255, 215, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Tus movimientos: " + to_string(_movimientos), 210, 220, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Movimientos minimos: " + to_string(minMovimientos), 180, 260, "ArialNovaCond", 30, { 255, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Pulsa ENTER para jugar otra partida", 115, 340, "ArialNovaCond", 30, { 0, 0, 0 });
        _mInterfaz.mostrarTexto(_renderer, "Pulsa ESC para salir", 200, 380, "ArialNovaCond", 30, { 0, 0, 0 });

        if (minMovimientos == _movimientos)
        {
            _mInterfaz.mostrarTexto(_renderer, "¡Haz terminado con los movimientos minimos!", 88, 120, "ArialNovaCond", 26, { 0, 128, 0 });
        }

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                seguirJugando = false;
                menuTerminado = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    seguirJugando = false;
                    menuTerminado = true;
                }
                else if (e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_KP_ENTER)
                {
                    seguirJugando = true;
                    menuTerminado = true;;
                }
            }
        }

        SDL_Delay(1000 / 60); // Cap frame rate to 60 FPS
        SDL_RenderPresent(_renderer);
    }

    return seguirJugando;
}
