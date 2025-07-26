#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <vector> // from stl
#include "./gui/utils/gui/gui.h"
#include "./gui/components/topbar/topbar.h"
#include "./gui/utils/text/textRenderer.h"
#include "./gui/utils/component/Component.h"
#include "./utils/setup/setup.h"
#include "./gui/components/button/button.h"
#include "./gui/components/slider/slider.h"
using namespace std;

/* struct Slider { */
/*   SDL_Rect bar; */
/*   SDL_Rect knob; */
/*   int* value; */
/*   SDL_Color color; */
/* }; */


int main() {

  constexpr int WINDOW_WIDTH=890, WINDOW_HEIGHT=520;

  cout<<"Initalizing SDL2..."<<endl;
  
  SDL_Color MY_WINDOW_COLOR = {41,41,41,255};

  Setup setup( WINDOW_HEIGHT, WINDOW_WIDTH, MY_WINDOW_COLOR);

  // waiting when we close the window, event loop:w

  /* TextRenderer text(renderer); */
  /* text.initializeFont("Roboto-Regular.ttf", 32); */

  /* text.xPos = 100; */
  /* text.yPos =100; */


  /* gui.drawButton(); */

  Alignment textAlign = Alignment::Center;
  Button* btn = new Button(100,100,200,50, "Click me!", textAlign, "assets/JetBrainsMono-Regular.ttf");
  std::vector<std::string> items = {"File", "Edit", "Help"};
  SDL_Color TOPBAR_BG_COLOR = {59,0,16,255};
  SDL_Color TOPBAR_TEXT_COLOR = {255,255,255,255};
  Topbar* topBar = new Topbar(items, "ARGUI V1.0",TOPBAR_BG_COLOR,TOPBAR_TEXT_COLOR , "assets/JetBrainsMono-Regular.ttf" ,75);
  Slider* mySlider = new Slider(100,200,200,0,100,50);
  int r = 0, g = 0, b = 0;
    
  setup.gui->addComponent(btn);
  setup.gui->addComponent(topBar);
  setup.gui->addComponent(mySlider);
  setup.runEventLoop();
  setup.cleanSDL();

  return 0;
}
