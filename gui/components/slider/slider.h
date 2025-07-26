#pragma once
#include "../../utils/component/Component.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
using namespace std;

class Slider : public Component {
  public: 
    int x, y, width;
    int min,max, value;
    int handleRadius = 8;
    bool dragging = false;

    Slider(int x, int y, int width, int min, int max, int initial);


    void draw(SDL_Renderer* renderer) override;
    void handle(SDL_Event& event, SDL_Renderer* renderer, SDL_Window* window) override;

    
  int getValue() const {
    return value;
  }
};
