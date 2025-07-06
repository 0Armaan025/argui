#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
using namespace std;

class Setup {
  // this class will set up window and renderer
  //
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
  public:
    Setup(SDL_Window& win, SDL_Renderer& ren);
    bool isError = false;
    string errorMessage = ""; 
};
