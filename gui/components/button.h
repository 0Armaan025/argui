#pragma once
#include <string>
using namespace std;
#include <SDL2/SDL.h>

class Button {
  private:
    SDL_Renderer* renderer;
  public:
    int xPos, yPos, width, height;
    std::string label;
    bool isHovered = false;

    Button(int x, int y, int w, int h, const std::string& text);

    void handleEvent(SDL_Event& e);
};
