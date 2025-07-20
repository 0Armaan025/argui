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

void Button::handle(SDL_Event &event, SDL_Renderer *renderer,
                    SDL_Window *window) {
  if (event.type == SDL_MOUSEMOTION) {
    int mx = event.motion.x;
    int my = event.motion.y;

    /* cout << "[IMPORTANT] X POSITION: " << xPos << " Y POSITION: " << yPos <<
     * endl; */
    /* cout << "[IMPORTANT] CX POSITION: " << mx << " CY POSITION: " << my <<
     * endl; */
    /**/
    isHovered = (mx >= rect.x && mx <= rect.x + rect.w && my >= rect.y &&
                 my <= rect.y + rect.h);

    SDL_Cursor *currentCursor = SDL_GetCursor();
    if (isHovered && currentCursor != handCursor) {
      SDL_SetCursor(normalCursor);
      /* cout << "im inside you dude" << endl; */
    } else if (!isHovered && currentCursor != normalCursor) {
      SDL_SetCursor(handCursor);
    }
  }
}

void Button::draw(SDL_Renderer *renderer) {
  cout << "button has been drawn :)" << endl;

  SDL_Color hoverColor = {41, 41, 41, 25};

  if (isHovered) {

    SDL_SetRenderDrawColor(renderer, hoverColor.r, hoverColor.g, hoverColor.b,
                           hoverColor.a);
  } else {

    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b,
                           bgColor.a);
  }
  SDL_RenderFillRect(renderer, &rect);
  TextRenderer text(renderer);
  /* text.initializeFont(font.c_str(), 32); */
  text.initializeFont(font.c_str(), 24);
  SDL_Color textColor = {255, 255, 255, 255};

  text.drawText("Hi, im good", textColor, xPos, yPos, rect, textAlign);
}
