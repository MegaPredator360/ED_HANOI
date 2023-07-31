#include "std.h"

class metodoInterfaz
{
private:
	int textoHeight;
	int textoWidth;

public:
	void mostrarTexto(SDL_Renderer* _renderer, string _texto, int _xPos, int _yPos, string _fuenteLetra, int _tamañoLetra, SDL_Color _color);
};

