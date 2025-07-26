#include "./slider.h"
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;

Slider::Slider(int x, int y, int width, int min, int max, int initial) : x(x), y(y), width(width), min(min), max(max), value(initial) {
  cout<<"slider initalized"<<endl;
}

void Slider::draw(SDL_Renderer* renderer) {
  // draw a track
  SDL_Color trackColor = {180,180,180,255};
  SDL_SetRenderDrawColor(renderer, trackColor.r, trackColor.g, trackColor.b, trackColor.a);
  // setting up color
  SDL_RenderDrawLine(renderer, x, y, x+width, y);
  // renderer, x1, y1, x2, y2

  int handleX = x + ((value - min) * width) / (max-min);
  SDL_SetRenderDrawColor(renderer, 60,60,255,255);
  SDL_Rect handle = {handleX - handleRadius, y  - handleRadius, handleRadius *2, handleRadius *2};
  SDL_RenderFillRect(renderer, &handle);
  
}

void Slider::handle(SDL_Event& e, SDL_Renderer* renderer, SDL_Window* window) {
  int mx, my;
  SDL_GetMouseState(&mx, &my);

  int handleX = x + ((value - min) * width) / (max-min);

if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            if (mx >= handleX - handleRadius && mx <= handleX + handleRadius &&
                my >= y - handleRadius && my <= y + handleRadius) {
                dragging = true;
            }
        } else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
            dragging = false;
        } else if (e.type == SDL_MOUSEMOTION && dragging) {
            int clampedX = std::max(x, std::min(x + width, mx));
            value = min + ((clampedX - x) * (max - min)) / width;
        }


}
