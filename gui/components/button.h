#pragma once
#include <string>
using namespace std;
#include <SDL2/SDL.h>

class Button {
  private:
    SDL_Renderer* renderer;
  public:
    int xPos, yPos, width, height;
    SDL_Rect rect;
    std::string label;
    bool isHovered = false;
    SDL_Color bgColor;

    Button(int x, int y, int w, int h, const std::string& text);

    SDL_Renderer* getRenderer() {
      return renderer;
    }
    void handleEvent(SDL_Event& e);
};
