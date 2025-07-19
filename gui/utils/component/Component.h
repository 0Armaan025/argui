#pragma once
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

using namespace std;

class Component {
  public:
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void handle(SDL_Event& event, SDL_Renderer* renderer, SDL_Window* window) = 0;
    virtual ~Component() = default;
};
