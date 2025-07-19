#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../gui/utils/gui/gui.h"
using namespace std;


static constexpr SDL_Color DEFAULT_COLOR = {30,30,30,255};

class Setup {
  public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    ARGui* gui = nullptr;
    SDL_Color WINDOW_COLOR;
    int w,h ;
    bool shouldQuit = false;
      
    Setup( int WINDOW_HEIGHT, int WINDOW_WIDTH, SDL_Color color = DEFAULT_COLOR);

    Setup();
    void cleanSDL();

    void runEventLoop();
};
