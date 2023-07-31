#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Para modificar el tipo de dato SDL_Rect
typedef struct {
    SDL_Rect sdlRect;
    int torre;
    int valor;
} SDL_Rect2;