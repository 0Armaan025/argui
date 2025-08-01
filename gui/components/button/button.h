#pragma once
#include <string>
#include "../../utils/text/textRenderer.h"
#include "../../utils/component/Component.h"
using namespace std;

#include <SDL2/SDL.h>



class Button: public Component {
  private:
    SDL_Renderer* renderer;
  public:
    SDL_Cursor* handCursor = nullptr;
    SDL_Cursor* normalCursor = nullptr;
    int xPos, yPos, width, height;
    SDL_Rect rect;
float hoverProgress = 0.0f;  // Between 0.0 and 1.0
float hoverSpeed = 0.05f;     // Adjust this for faster/slower fade
    std::string label;
    bool isHovered = false;
    string font = "assets/Roboto-Regular.ttf";
    Alignment textAlign = Alignment::Center;
    SDL_Color bgColor;
    // some random comment to show im kinda tired or something - well, it's not that im tired i HAVE TO GO AND __ STUDY 
    Button(int x, int y, int w, int h, const std::string& text, Alignment align = Alignment::Center, string myFont = "assets/Roboto-Regular.ttf");

    SDL_Renderer* getRenderer() {
      return renderer;
    }

    void draw(SDL_Renderer* renderer) override;
    void handle(SDL_Event& e, SDL_Renderer* renderer, SDL_Window* window) override;
};
