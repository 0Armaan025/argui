#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <vector> // from stl
#include "gui/gui.h"
#include "gui/utils/textRenderer.h"
#include "./gui/components/button.h"
using namespace std;

/* struct Slider { */
/*   SDL_Rect bar; */
/*   SDL_Rect knob; */
/*   int* value; */
/*   SDL_Color color; */
/* }; */



int main() {

  constexpr int WINDOW_WIDTH=640, WINDOW_HEIGHT=480;

  cout<<"Initalizing SDL2..."<<endl;

  if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) <0)) {
    cout<<"init failed, error: "<<SDL_GetError()<<endl;
    return -1;
  }


  SDL_Window* window = SDL_CreateWindow("SDL TEST WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

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

  /* TextRenderer text(renderer); */
  /* text.initializeFont("Roboto-Regular.ttf", 32); */

  /* text.xPos = 100; */
  /* text.yPos =100; */


  bool running = true;
  SDL_Event event;

  ARGui gui(renderer, window);
  /* gui.drawButton(); */
  Button btn(100,100,200,50, "Click me!");
  int r = 255, g = 255, b = 255;
  SDL_Color textColor = SDL_Color{static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b)}; 

/* vector<Slider> sliders = { */
/*     {{100, 400, 300, 10}, {100 + r, 395, 10, 20}, &r, {255, 0, 0}}, */
/*     {{100, 430, 300, 10}, {100 + g, 425, 10, 20}, &g, {0, 255, 0}}, */
/*     {{100, 460, 300, 10}, {100 + b, 455, 10, 20}, &b, {0, 0, 255}}, */
/* }; */
      //this will not work :v  /* SDL_Rect outline = { rect.x+1, rect.y+1, rect.w +1, rect.h + 1 }; */
  /* if(event.type == window) */
 bool dragging = false;
    /* int selectedSlider = -1; */
  while(running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = false;
      }

/*       if(event.type == SDL_MOUSEBUTTONDOWN) { */
/*         int mx = event.button.x; */
/*         int my = event.button.y; */
/**/
/*         SDL_Point point = {mx, my}; */
/**/
/*         for(size_t i =0;i<sliders.size();++i) { */
/*           if(SDL_PointInRect(&point, &sliders[i].knob)) { */
/*             dragging = true; */
/*             selectedSlider = i; */
/*             break; */
/*           } */
/*         } */
/*       } */
/**/
/*       if(event.type == SDL_MOUSEBUTTONUP) { */
/*         dragging = false; */
/*         selectedSlider = -1; */
/*       } */
/**/
/*       if(event.type == SDL_MOUSEMOTION && dragging) { */
/*         int mx = event.motion.x; */
/**/
/*         int baseX = sliders[selectedSlider].bar.x; */
/*         int newValue = clamp(mx-baseX,0,255); */
/*         *sliders[selectedSlider].value = newValue; */
/*         sliders[selectedSlider].knob.x = baseX + newValue; */
/* textColor = SDL_Color{ */
/*             static_cast<Uint8>(r), */
/*             static_cast<Uint8>(g), */
/*             static_cast<Uint8>(b) */
/*         }; */
/*       } */
/*     } */
/**/
    
  } 
    SDL_SetRenderDrawColor(renderer, 40, 40, 40 , 255); // dark color
    SDL_RenderClear(renderer);
    gui.drawButton(btn);
    // Render_Fill_Rect = inside color, Render_Draw_Rect = border hehe
/* for (auto& s : sliders) { */
/*     SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); */
/*     SDL_RenderFillRect(renderer, &s.bar); */
/**/
/*     SDL_SetRenderDrawColor(renderer, s.color.r, s.color.g, s.color.b, 255); */
/*     SDL_RenderFillRect(renderer, &s.knob); */
/* } */
    /* text.drawText("KONISEGG JESKO ABSOLUT....", textColor); */

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  TTF_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
    
  return 0;
}
