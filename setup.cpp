#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
#include "setup.h"
using namespace std;



Setup::Setup( int WINDOW_HEIGHT, int WINDOW_WIDTH) :w(WINDOW_WIDTH), h(WINDOW_HEIGHT) {

  const char* WINDOW_TITLE = "ARGUI - THE V1.0";

    
  cout<<WINDOW_TITLE<<endl;
  cout<<"setup constructor called"<<endl;
  
  if(SDL_Init(SDL_INIT_VIDEO)<0) cerr<<"error";
  if(TTF_Init()<0) cerr<<"error";

  window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w,h, SDL_WINDOW_SHOWN);

  if(!window) {
    cerr<<"ERROR CREATING A WINDOW: "<<SDL_GetError()<<endl;
    /* return -1; */
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if(!renderer) {
    cerr<<"ERROR CREATING A RENDERER:"<<SDL_GetError()<<endl;
    /* return -1; */
  }

  gui = new ARGui(renderer, window);
}

void Setup::cleanSDL() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

void Setup::runEventLoop() {
  bool running = true;
  SDL_Event event;

  while(running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = false;
      }
      gui->handle(event);
    }

    SDL_SetRenderDrawColor(renderer, 30,30,30,255);
    SDL_RenderClear(renderer);

    gui->draw(renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }
}
