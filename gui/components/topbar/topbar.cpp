#include <iostream>
#include "topbar.h"
#include <SDL2/SDL.h>
#include "../../utils/text/textRenderer.h"
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

Topbar::Topbar (std::vector<std::string> myItems, string windowName): items(myItems), WINDOW_NAME(windowName) {
  cout<<"topbar constructor called"<<endl;
  
  BG_COLOR = {20,20,20,255};
  TEXT_COLOR = {255,255,255,255};
  BAR_RECT = {0,0,890,40};
}

void Topbar::draw(SDL_Renderer* renderer) {
   
  SDL_SetRenderDrawColor(renderer, BG_COLOR.r, BG_COLOR.g, BG_COLOR.a, BG_COLOR.a);
  SDL_RenderFillRect(renderer, &BAR_RECT);
  
  int xOffset = 10;
  int yCenter = BAR_RECT.y + (BAR_RECT.h/2);
TextRenderer text(renderer);
  text.initializeFont("assets/Roboto-Regular.ttf", 32);

  for(const auto& item: items) {
    int textW = 0;
    int textH = 0;
    /* TTF_SizeText(textRenderer->) */

  int y = yCenter - (textH/2);

  SDL_Rect dummyBox = {xOffset, y, textW, textH};
  text.drawText(item,textColor, xOffset, y, dummyBox, Alignment::Left);
  xOffset = xOffset + textW + 20;

  }
}

void Topbar::handle(SDL_Event& event) {
  if(event.type == SDL_MOUSEMOTION) {
    int mx = event.motion.x; // returns x;
    int my = event.motion.y; // and ofc this will return the y pos of the cursor;

    isHovered = (mx >= xPos && mx <= xPos - width && my >= yPos && my<=yPos + height); // basically checking if xPos is greater or equal to xPos of button, and it is not at start too, same for vertical thing :D
  }
}
