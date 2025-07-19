#include <iostream>
#include <string>
#include "button.h"
#include "../../utils/text/textRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

Button::Button(int x, int y, int w, int h, const std::string& text, Alignment align, string myFont) : width{w}, height{h}, xPos{x}, yPos{y}, label{text}, bgColor{80,80,80,255}, font{myFont}, rect{x,y,w,h}{
  // the rect is just initalized, but shown in the draw function in the gui.cpp
         cout<<"Button constructor initalized";
      textAlign = align; 

       } 

void Button::handle(SDL_Event& event, SDL_Renderer* renderer, SDL_Window* window) {
  if(event.type == SDL_MOUSEMOTION) {
    int mx = event.motion.x; // returns x;
    int my = event.motion.y; // and ofc this will return the y pos of the cursor;

    isHovered = (mx >= xPos && mx <= xPos - width && my >= yPos && my<=yPos + height); // basically checking if xPos is greater or equal to xPos of button, and it is not at start too, same for vertical thing :D
  }

  
}

void Button::draw(SDL_Renderer* renderer) {
  cout<<"button has been drawn :)"<<endl;

  

  SDL_SetRenderDrawColor(renderer, bgColor.r,bgColor.g, bgColor.b, bgColor.a);
  SDL_RenderFillRect(renderer, &rect);
 TextRenderer text(renderer);
  /* text.initializeFont(font.c_str(), 32); */
 text.initializeFont(font.c_str(), 24);
  SDL_Color textColor = {255,255,255,255};
  
  text.drawText("Hi, im good",textColor, xPos, yPos, rect, textAlign);
}
