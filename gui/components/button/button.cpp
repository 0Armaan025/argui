#include "button.h"
#include "../../utils/text/textRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
using namespace std;

Button::Button(int x, int y, int w, int h, const std::string &text,
               Alignment align, string myFont)
    : width{w}, height{h}, xPos{x}, yPos{y}, label{text},
      bgColor{80, 80, 80, 255}, font{myFont}, rect{x, y, w, h} {
  // the rect is just initalized, but shown in the draw function in the gui.cpp
  cout << "Button constructor initalized";
  textAlign = align;

  handCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

  normalCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
}

SDL_Color lerpColorNew(SDL_Color a, SDL_Color b, float t) {
  SDL_Color result;
  result.r = static_cast<Uint8>(a.r + (b.r - a.r) * t);
  result.g = static_cast<Uint8>(a.g + (b.g - a.g) * t);
  result.b = static_cast<Uint8>(a.b + (b.b - a.b) * t);
  result.a = static_cast<Uint8>(a.a + (b.a - a.a) * t);
  return result;
}


void Button::handle(SDL_Event &event, SDL_Renderer *renderer, SDL_Window *window) {
  if (event.type == SDL_MOUSEMOTION) {
    int mx = event.motion.x;
    int my = event.motion.y;

    bool wasHovered = isHovered;

    isHovered = (mx >= rect.x && mx <= rect.x + rect.w &&
                 my >= rect.y && my <= rect.y + rect.h);

    // Update transition progresss
    if (isHovered) {
      hoverProgress += hoverSpeed;
    } else {
      hoverProgress -= hoverSpeed;
    }

    // Clamp between 0 and 1
    if (hoverProgress > 1.0f) hoverProgress = 1.0f;
    if (hoverProgress < 0.0f) hoverProgress = 0.0f;

    // Handle cursor
    SDL_Cursor *currentCursor = SDL_GetCursor();
    if (isHovered && currentCursor != handCursor) {
      SDL_SetCursor(handCursor);
    } else if (!isHovered && currentCursor != normalCursor) {
      SDL_SetCursor(normalCursor);
    }
  }
}

void Button::draw(SDL_Renderer *renderer) {
  SDL_Color hoverColor = {41, 41, 41, 255};  // solid alpha now
  SDL_Color currentColor = lerpColorNew(bgColor, hoverColor, hoverProgress);

  SDL_SetRenderDrawColor(renderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
  SDL_RenderFillRect(renderer, &rect);

  TextRenderer text(renderer);
  text.initializeFont(font.c_str(), 24);
  SDL_Color textColor = {255, 255, 255, 255};

  text.drawText("Hi, im good", textColor, xPos, yPos, rect, textAlign);
}

