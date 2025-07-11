#include <iostream>
#include <SDL2/SDL.h>
#include "./utils/textRenderer.h"
#include "./components/button.h"
#include "gui.h"
using namespace std;

ARGui::ARGui(SDL_Renderer* ren, SDL_Window* win) : renderer(ren), window(win) {
  cout<<"constructor successfully initalized"<<endl;
}

void ARGui::drawButton(Button& button) {
  cout<<"button has been drawn :)"<<endl;
  SDL_SetRenderDrawColor(renderer, button.bgColor.r,button.bgColor.g, button.bgColor.b, button.bgColor.a);
  SDL_RenderFillRect(renderer, &button.rect);
 TextRenderer text(renderer);
  text.initializeFont("Roboto-Regular.ttf", 32);
  SDL_Color textColor = {255,255,255,255};
  text.drawText("Hi, im good",textColor);
}
