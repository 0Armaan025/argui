#include <iostream>
#include "topbar.h"
#include <SDL2/SDL.h>
#include "../../utils/text/textRenderer.h"
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

Topbar::Topbar (std::vector<std::string> myItems, string windowName, SDL_Color bgColor, SDL_Color textColor): items(myItems), WINDOW_NAME(windowName), BG_COLOR (bgColor), TEXT_COLOR(textColor){
  cout<<"topbar constructor called"<<endl;
  
  BAR_RECT = {0,0,890,40};
}

void Topbar::draw(SDL_Renderer* renderer) {
   

  /* cout<<BG_COLOR.a<<BG_COLOR.r<<BG_COLOR.g<<BG_COLOR.b<<endl; */
  SDL_SetRenderDrawColor(renderer, BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
  SDL_RenderFillRect(renderer, &BAR_RECT);
  
  int xOffset = 10;
  int OFFSET_THRASHOLD = 70;
  int yCenter = BAR_RECT.y + (BAR_RECT.h/2);
TextRenderer text(renderer);
  text.initializeFont("assets/Roboto-Regular.ttf", 24);


    int textH = 0;
    int textW = 0;
  int y = yCenter - (textH/2);
  for(const auto& item: items) {
    /* TTF_SizeText(textRenderer->) */


  SDL_Rect dummyBox = {xOffset, y, textW, textH};
  if(item == "" || item == " ") {
    cout<<"[FATAL] item is null"<<endl;
    return;
  } 
  text.drawText(item,TEXT_COLOR, xOffset, y, dummyBox, Alignment::Left);
  xOffset  += textW + OFFSET_THRASHOLD;

  }
 if(WINDOW_NAME == "" || WINDOW_NAME == " ") {
    cout<<"[FATAL] WINDOW_NAME item is null"<<endl;
    return;
  } 
  text.drawText(WINDOW_NAME, TEXT_COLOR,445 , y, BAR_RECT, Alignment::Center);
}

void Topbar::handle(SDL_Event& event) {
  /* if(event.type == SDL_MOUSEMOTION) { */
  /*   int mx = event.motion.x; // returns x; */
  /*   int my = event.motion.y; // and ofc this will return the y pos of the cursor; */
  /**/
  /*   isHovered = (mx >= xPos && mx <= xPos - width && my >= yPos && my<=yPos + height); // basically checking if xPos is greater or equal to xPos of button, and it is not at start too, same for vertical thing :D */
  /* } */
}
