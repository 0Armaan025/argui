#include <iostream>
#include <SDL2/SDL.h>
#include "setup.h"
using namespace std;

Setup::Setup(SDL_Window* win, SDL_Renderer* ren) : window(win), renderer(ren) {
  cout<<"setup constructor called"<<endl;
  
}


