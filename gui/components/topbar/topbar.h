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
    SDL_Rect crossBtn;
    SDL_Cursor* handCursor = nullptr;
    SDL_Cursor* arrowCursor = nullptr;
    bool isHovered = false;
    SDL_Color BG_COLOR;
    string font = "assets/Roboto-Regular.ttf"; 
    SDL_Color TEXT_COLOR;
    // IMPORTANT: IT WILL OVERLAP, change overlap = false to disable it
    int OFFSET_THRASHOLD;
    std::string WINDOW_NAME = "ARGUI V1.0";
    bool overlap = true;
    bool isHoveringOnCrossBtn = false;
    // storesthe current color
    SDL_Color currentCrossColor; 
    // speed for lerp (linear interpolation)
    float HOVER_TRANSITION_SPEED = 0.1f;
    
    Topbar (std::vector<std::string> myItems,string windowName, SDL_Color bgColor, SDL_Color textColor, string myFont = "assets/Roboto-Regular.ttf", int  myOffsetThrashold= 75 );
    Topbar(); // the const we want <=

    void draw(SDL_Renderer* renderer) override;
    void handle(SDL_Event& e, SDL_Renderer* renderer, SDL_Window* window) override;
    bool isCrossedClicked(SDL_Event& event);
};
