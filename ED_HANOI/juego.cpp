#include "juego.h"

// Para reiniciar el juego
void juego::reiniciarJuego(int _dificultad)
{
    movimientos = 0;
    puntero = 0;
    seleccionado = false;
    posSeleccionado = 0;
    discos = _mJuego.hacerDiscos(_dificultad);
}

int juego::iniciarJuego(int _dificultad, SDL_Renderer* _renderer)
{
    // Inicializamos los valores del juego
    juegoTerminado = false;
    puntero = 0;
    seleccionado = false;
    posSeleccionado = 0;
    movimientos = 0;

    // Limpiamos el vector en caso de ser usado anteriormente
    discos.clear();

    // Llenamos el vector con los discos basado en la dificultad
    discos = _mJuego.hacerDiscos(_dificultad);

    // Bucle principal del juego
    while (!juegoTerminado) 
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) 
        {
            if (e.type == SDL_QUIT) 
            {
                movimientos = 0;
                juegoTerminado = true;
            }
            else if (e.type == SDL_KEYDOWN) 
            {
                // Si el usuario pulsa la tecla "r" el juego se reinicia
                if (e.key.keysym.sym == SDLK_r) 
                {
                    reiniciarJuego(_dificultad);
                }
                // Si el usuario pulsa la letra "q" o "ESC" el juego se termina
                else if (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    juegoTerminado = true;
                }
                // Si el usuario pulsa la tecla derecha
                else if (e.key.keysym.sym == SDLK_RIGHT) 
                {
                    // El puntero se moverá
                    puntero = (puntero + 1) % 3;

                    // Si hay una pieza seleccionada
                    if (seleccionado) 
                    {
                        // Se le dará la posicion del puntero si el disco está seleccionado
                        discos[posSeleccionado].torre = puntero;

                        // Se movera la posicion en X, basado en la posicion del puntero y el ancho de la torre y el disco, esto para ayudar a que el mismo se mantenga centrado
                        discos[posSeleccionado].sdlRect.x = torres[puntero].sdlRect.x + (torres[puntero].sdlRect.w / 2 - discos[posSeleccionado].sdlRect.w / 2);
                    }
                }
                // Si el usuario pulsa la tecla izquierda
                else if (e.key.keysym.sym == SDLK_LEFT) 
                {
                    puntero = (puntero - 1 + 3) % 3;

                    if (seleccionado) 
                    {
                        discos[posSeleccionado].torre = puntero;
                        discos[posSeleccionado].sdlRect.x = torres[puntero].sdlRect.x + (torres[puntero].sdlRect.w / 2 - discos[posSeleccionado].sdlRect.w / 2);
                    }
                }
                // Si el usuario pulsa la tecla arriba y no hay una pieza seleccionada
                else if (e.key.keysym.sym == SDLK_UP && !seleccionado) 
                {
                    // Se ira por cada uno de los discos del vector
                    for (int i = discos.size() - 1; i >= 0; i--) 
                    {
                        // Si el disco a seleccionar esta en la misma posicion del puntero, se seleccionará ese disco
                        if (discos[i].torre == puntero) 
                        {
                            seleccionado = true;

                            // Se le dará la posicion del puntero a posSeleccionado
                            posSeleccionado = i;

                            // Se moverá el disco en posicion Y
                            discos[posSeleccionado].sdlRect.y = 100;

                            // Se terminará el for
                            break;
                        }
                    }
                }
                // Si el usuario pulsa la tecla abajo y hay una pieza seleccionada
                else if (e.key.keysym.sym == SDLK_DOWN && seleccionado) 
                {
                    // Se ira por cada uno de los discos del vector
                    for (int i = discos.size() - 1; i >= 0; i--) 
                    {
                        // Si la torre donde está el disco coincide con el del puntero y coincide con la posicion de posSeleccionado
                        if (discos[i].torre == puntero && i != posSeleccionado) 
                        {
                            // Si el disco que esta en la torre es mayor que el disco que está seleccionado
                            if (discos[i].valor > discos[posSeleccionado].valor) 
                            {
                                seleccionado = false;

                                // Se moverá el disco en y en la torre seleccionada
                                discos[posSeleccionado].sdlRect.y = discos[i].sdlRect.y - discos[posSeleccionado].sdlRect.h - 3;

                                // Se sumará la cantidad de movimientos
                                movimientos++;
                            }
                            // Se termina el for
                            break;
                        }
                    }

                    // Si hay una pieza seleccionada, pero no hay ninguna pieza en la torre seleccionara
                    if (seleccionado && !_mJuego.revisarTorreVacia(discos, puntero, posSeleccionado))
                    {
                        seleccionado = false;
                        discos[posSeleccionado].sdlRect.y = 400 - discos[posSeleccionado].sdlRect.h - 3;
                        movimientos++;
                    }
                }
            }
        }

        // Se le da color a la pantalla
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

        // Se limpia la pantalla
        SDL_RenderClear(_renderer);

        // Se dibujan las torres
        torres = _mJuego.dibujarTorres(_renderer);

        // Se dibujan los discos
        _mJuego.dibujarDiscos(_renderer, discos);

        // Se dibuja el puntero
        _mJuego.dibujarPuntero(_renderer, torres, puntero);

        // Se muestra el texto con los movimientos
        _mInterfaz.mostrarTexto(_renderer, "Movimientos: " + to_string(movimientos), 230, 20, "ArialNovaCond", 30, { 0, 0, 0 });

        // Se renderiza la pantalla
        SDL_RenderPresent(_renderer);

        // Si no hay una opción seleccionada, se revisará si el juego se completó
        if (!seleccionado) 
        {
            // Se revisará si el juego ha terminado
            if (_mJuego.revisarJuegoTerminado(discos))
            {
                juegoTerminado = true;
            }
        }

        // Mantener cuadros por segundo a 60FPS
        SDL_Delay(1000 / 60);
    }

    return movimientos;
}