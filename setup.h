#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "gui/gui.h"
using namespace std;

class Setup {
  public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    ARGui* gui = nullptr;
    int w,h ;

    Setup( int WINDOW_HEIGHT, int WINDOW_WIDTH);

    void cleanSDL();

    void runEventLoop();
};
