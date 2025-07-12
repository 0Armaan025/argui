#include <iostream>
#include <SDL2/SDL.h>
#include "./utils/textRenderer.h"
#include "./components/button.h"
#include "gui.h"
using namespace std;

ARGui::ARGui(SDL_Renderer* ren, SDL_Window* win) : renderer(ren), window(win) {
  cout<<"constructor successfully initalized"<<endl;
}

/* void ARGui::drawButton(Button& button) { */
/**/
/* } */
