#include "interfaz.h"

class metodoJuego
{
private:
	metodoInterfaz _mInterfaz;
	vector<SDL_Rect2> discos;
	vector<SDL_Rect2> torres;
	int height;
	int yPos;
	int width;

public:
	// Se crearán los discos basado en la dificultad del juego
	vector<SDL_Rect2> hacerDiscos(int _dificultad);

	// Se verificará si la torre está vacia
	bool revisarTorreVacia(vector<SDL_Rect2> _discos, int _puntero, int _posSeleccionado);

	// Se verificará si el juego ha terminado
	bool revisarJuegoTerminado(vector<SDL_Rect2> _discos);

	// Se dibujarán las torres
	vector<SDL_Rect2> dibujarTorres(SDL_Renderer* _renderer);

	// Se dibujarán los discos
	void dibujarDiscos(SDL_Renderer* _renderer, vector<SDL_Rect2> _discos);

	// Se dibujará el puntero
	void dibujarPuntero(SDL_Renderer* _renderer, vector<SDL_Rect2> _torres, int _puntero);
};

