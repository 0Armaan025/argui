#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <vector>
#include "../../utils/component/Component.h"
using namespace std;

class Topbar : public Component {
 
  public:
    std::vector<std::string> items;
    SDL_Rect BAR_RECT;
    bool isHovered = false;
    SDL_Color BG_COLOR;
    SDL_Color TEXT_COLOR;
    std::string WINDOW_NAME = "ARGUI V1.0";
    
    Topbar (std::vector<std::string> myItems, string windowName, SDL_Color bgColor, SDL_Color textColor);

    void draw(SDL_Renderer* renderer) override;
    void handle(SDL_Event& e) override;

};
