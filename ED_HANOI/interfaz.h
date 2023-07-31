#include "metodoInterfaz.h"

class interfaz
{
private:
	metodoInterfaz _mInterfaz;

public:
	int menuPrincipal(SDL_Renderer* _renderer);
	void juegoTerminado(SDL_Renderer* _renderer, int _dificultad, int _movimientos);
};

