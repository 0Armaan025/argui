#pragma once
#include <string>
#include "../utils/textRenderer.h"
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
    Alignment textAlign = Alignment::Center;
    SDL_Color bgColor;

    Button(int x, int y, int w, int h, const std::string& text, Alignment align = Alignment::Center);

    SDL_Renderer* getRenderer() {
      return renderer;
    }
    void handleEvent(SDL_Event& e);
};
