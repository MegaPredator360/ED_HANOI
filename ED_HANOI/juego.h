#include "metodoJuego.h"

class juego
{
private:
	metodoInterfaz _mInterfaz;
	metodoJuego _mJuego;

	// Contenedor de la torre
	vector<SDL_Rect2> torres;

	// Contenedor de los discos
	vector<SDL_Rect2> discos;

	// Para verificar si el juego está terminado
	bool juegoTerminado;

	// Puntero / Cursor del juego
	int puntero;

	// Para verificar si hay un disco seleccionado
	bool seleccionado;

	// Posicion del objeto seleccionado
	int posSeleccionado;

	// Contar la cantidad de movimientos
	int movimientos;

public:
	void reiniciarJuego(int _dificultad);
	int iniciarJuego(int _dificultad, SDL_Renderer* _renderer);
};

