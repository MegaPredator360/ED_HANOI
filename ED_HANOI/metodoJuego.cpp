#include "metodoJuego.h"

vector<SDL_Rect2> metodoJuego::hacerDiscos(int _dificultad)
{
    // Limpiamos el vector en caso de ser usado anteriormente
    discos.clear();

    // Le damos la altura del disco
    height = 20;

    // Le calculamos la posicion en inicial y
    yPos = 397 - height;

    // Le calculamos el ancho del disco basado en la dificultad
    width = _dificultad * 23;

    // Se le asignarán los datos a cada disco
    for (int i = 0; i < _dificultad; i++) 
    {
        SDL_Rect2 diskRect = { 0, 0, width, height };
        diskRect.sdlRect.x = 120 - width / 2;
        diskRect.sdlRect.y = yPos;
        diskRect.torre = 0;
        diskRect.valor = _dificultad - i;

        // Insertamos los datos en el vector
        discos.push_back(diskRect);

        // Calculamos la posicion en y de cada disco
        yPos -= height + 3;

        // Calculamos el ancho del disco;
        width -= 23;
    }

    return discos;
}

bool metodoJuego::revisarTorreVacia(vector<SDL_Rect2> _discos, int _puntero, int _posSeleccionado)
{
    // Se revisará cada disco en el vector
    for (int i = _discos.size() - 1; i >= 0; i--) 
    {
        // Si se encuentra un disco en la torre
        if (_discos[i].torre == _puntero && i != _posSeleccionado) 
        {
            return true;
        }
    }

    return false;
}

bool metodoJuego::revisarJuegoTerminado(vector<SDL_Rect2> _discos)
{
    // Se revisará
    for (int i = _discos.size() - 1; i >= 0; i--)
    {
        // Si hay un disco que no esta en la torre 2, el juego continua
        if (_discos[i].torre != 2) 
        {
            return false;
        }
    }

    // Se pausará el programa por 0.18 segundos xd
    SDL_Delay(200);
    return true;
}

vector<SDL_Rect2> metodoJuego::dibujarTorres(SDL_Renderer* _renderer)
{

    // Se hará un bucle donde se dibujarán 3 torres
    for (int i = 0; i < 3; i++) 
    {
        // Se dibujará la base
        SDL_Rect2 torreRect = { 40 + i * 200, 400, 160, 30 };
        SDL_SetRenderDrawColor(_renderer, 0, 128, 0, 255);
        SDL_RenderFillRect(_renderer, &torreRect.sdlRect);

        // Se dibujará el poste
        SDL_Rect2 posteRect = { 40 + i * 200 + 75, 200, 10, 200 };
        SDL_SetRenderDrawColor(_renderer, 128, 128, 128, 255);
        SDL_RenderFillRect(_renderer, &posteRect.sdlRect);

        // Se sumará al vector de torres
        torres.push_back(torreRect);
    }

    _mInterfaz.mostrarTexto(_renderer, "Inicio", torres[0].sdlRect.x + torres[0].sdlRect.w / 2 - 20, 403, "ArialNovaCond", 20, { 0, 0, 0 });
    _mInterfaz.mostrarTexto(_renderer, "Final", torres[2].sdlRect.x + torres[2].sdlRect.w / 2 - 20, 403, "ArialNovaCond", 20, { 0, 0, 0 });

    return torres;
}

void metodoJuego::dibujarPuntero(SDL_Renderer* _renderer, vector<SDL_Rect2> _torres, int _puntero)
{
    // Posiciones del puntero
    vector<SDL_Point> puntosPuntero = {
        {_torres[_puntero].sdlRect.x + _torres[_puntero].sdlRect.w / 2 - 7, 450},
        {_torres[_puntero].sdlRect.x + _torres[_puntero].sdlRect.w / 2, 440},
        {_torres[_puntero].sdlRect.x + _torres[_puntero].sdlRect.w / 2 + 7, 450}
    };

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    SDL_RenderDrawLines(_renderer, puntosPuntero.data(), puntosPuntero.size());
}

void metodoJuego::dibujarDiscos(SDL_Renderer* _renderer, vector<SDL_Rect2> _discos)
{
    for (int i = _discos.size() - 1; i >= 0; i--) 
    {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(_renderer, &_discos[i].sdlRect);
    }
}