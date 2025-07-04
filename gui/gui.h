#include <SDL2/SDL.h>
#pragma once


class ARGui {
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;

  public:
    ARGui(SDL_Renderer* ren, SDL_Window* win);

    void drawButton( );

};
