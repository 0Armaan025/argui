#include <iostream>
#include "button.h"
#include "../utils/textRenderer.h"
#include <SDL2/SDL.h>
using namespace std;

Button::Button(int x, int y, int w, int h, const std::string& text, Alignment align) : width{w}, height{h}, xPos{x}, yPos{y}, label{text}, bgColor{80,80,80,255}, rect{x,y,w,h}{
  // the rect is just initalized, but shown in the draw function in the gui.cpp
         cout<<"Button constructor initalized";
      textAlign = align; 

       } 

void Button::handleEvent(SDL_Event& event) {
  if(event.type == SDL_MOUSEMOTION) {
    int mx = event.motion.x; // returns x;
    int my = event.motion.y; // and ofc this will return the y pos of the cursor;

    isHovered = (mx >= xPos && mx <= xPos - width && my >= yPos && my<=yPos + height); // basically checking if xPos is greater or equal to xPos of button, and it is not at start too, same for vertical thing :D
  }
}
