#include "metodoInterfaz.h"

void metodoInterfaz::mostrarTexto(SDL_Renderer* _renderer, string _texto, int _xPos, int _yPos, string _fuenteLetra, int _tamañoLetra, SDL_Color _color)
{
    // Configurar la ruta de la fuente de letra
    string rutaFuente = "./fonts/" + _fuenteLetra + ".ttf";

    // Configuramos la fuente de letra
    TTF_Font* fuenteLetra = TTF_OpenFont(rutaFuente.c_str(), _tamañoLetra);

    // Verificar que se haya cargado la fuente de letra
    if (!fuenteLetra) 
    {
        cout << "Ocurrio un error al cargar la fuente de letra" << endl;
    }

    // Configuramos la superficie del texto
    SDL_Surface* surfaceTexto = TTF_RenderText_Solid(fuenteLetra, _texto.c_str(), _color);

    // Configuramos la textura
    SDL_Texture* texturaTexto = SDL_CreateTextureFromSurface(_renderer, surfaceTexto);

    // Averiguamos el ancho y largo de la textura
    SDL_QueryTexture(texturaTexto, NULL, NULL, &textoWidth, &textoHeight);

    // Configuracion la posicion y el ancho y largo del texto
    SDL_Rect posicionTexto = { _xPos, _yPos, textoWidth, textoHeight };

    // Liberar recursos
    SDL_FreeSurface(surfaceTexto);

    // Renderizar el texto de la ventana
    SDL_RenderCopy(_renderer, texturaTexto, NULL, &posicionTexto);

    // Terminamos de liberar recursos
    SDL_DestroyTexture(texturaTexto);
}
