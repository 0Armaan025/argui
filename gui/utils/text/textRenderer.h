#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
using namespace std;

enum class Alignment {
  Left,
  Center,
  Right
};

class TextRenderer {
  private:
    SDL_Renderer* renderer;
  public:
    TTF_Font* font = nullptr;
    int fontSize = 24;
    int xPos = 0, yPos = 0;
    TextRenderer(SDL_Renderer* ren);
    ~TextRenderer();
    void initializeFont(const string& path, int size);
    void drawText(const string& text, SDL_Color& color, int x, int y, SDL_Rect box, Alignment align = Alignment::Center);
};
