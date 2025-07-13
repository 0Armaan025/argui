#include <iostream>
#include <SDL2/SDL.h>
#include "../../utils/text/textRenderer.h"
#include "../../components/button/button.h"
#include "gui.h"
using namespace std;

ARGui::ARGui(SDL_Renderer* ren, SDL_Window* win) : renderer(ren), window(win) {
  cout<<"constructor successfully initalized"<<endl;
}

/* void ARGui::drawButton(Button& button) { */
/**/
/* } */
