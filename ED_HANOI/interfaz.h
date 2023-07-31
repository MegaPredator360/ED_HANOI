#include "metodoInterfaz.h"

class interfaz
{
private:
	metodoInterfaz _mInterfaz;
	bool menuTerminado;
	bool seguirJugando;
	int minMovimientos;
	SDL_Event e;
	int dificultad;

public:
	int menuPrincipal(SDL_Renderer* _renderer);
	bool juegoTerminado(SDL_Renderer* _renderer, int _dificultad, int _movimientos);
};

