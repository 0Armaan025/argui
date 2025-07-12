#pragma once
#include <string>
#include "../utils/textRenderer.h"
#include "../utils/Component.h"
using namespace std;

#include <SDL2/SDL.h>

class Button: public Component {
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

    void draw(SDL_Renderer* renderer) override;
    void handle(SDL_Event& e) override;
};
