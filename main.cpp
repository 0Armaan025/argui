#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <vector> // from stl
#include "gui/gui.h"
#include "gui/utils/textRenderer.h"
#include "gui/utils/Component.h"
#include "setup.h"
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
  
  SDL_Color MY_WINDOW_COLOR = {255,255,255,255};

  Setup setup( WINDOW_HEIGHT, WINDOW_WIDTH, MY_WINDOW_COLOR);

  // waiting when we close the window, event loop:w

  /* TextRenderer text(renderer); */
  /* text.initializeFont("Roboto-Regular.ttf", 32); */

  /* text.xPos = 100; */
  /* text.yPos =100; */


  /* gui.drawButton(); */

  Alignment textAlign = Alignment::Center;
  Button* btn = new Button(100,100,200,50, "Click me!", textAlign);
  int r = 255, g = 255, b = 255;
    
  setup.gui->addComponent(btn);
  setup.runEventLoop();
  setup.cleanSDL();

  return 0;
}
