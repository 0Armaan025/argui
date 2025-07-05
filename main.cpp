#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "gui/gui.h"
using namespace std;

int main() {

  constexpr int WINDOW_WIDTH=640, WINDOW_HEIGHT=480;

  cout<<"Initalizing SDL2..."<<endl;

  if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) <0)) {
    cout<<"init failed, error: "<<SDL_GetError()<<endl;
    return -1;
  }


  SDL_Window* window = SDL_CreateWindow("SDL TEST WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

  if(!window) {
    cerr<<"Window creation failed: "<<SDL_GetError()<<endl;
    SDL_Quit();
    return -1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(!renderer) {
    cerr<<"Renderer creation failed: "<<SDL_GetError()<<endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }

  // waiting when we close the window, event loop:w

  bool running = true;
  SDL_Event event;

  ARGui gui(renderer, window);


  SDL_Rect rect = {150, 150, 450, 450}; 

      //this will not work :v  /* SDL_Rect outline = { rect.x+1, rect.y+1, rect.w +1, rect.h + 1 }; */
  /* if(event.type == window) */

  while(running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = false;
      }
    }

  
    SDL_SetRenderDrawColor(renderer, 40, 40, 40 , 255); // dark color
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    // Render_Fill_Rect = inside color, Render_Draw_Rect = border hehe
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
    
  return 0;
}
