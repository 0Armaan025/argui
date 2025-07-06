#include "textRenderer.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


using namespace std;

TextRenderer::TextRenderer (SDL_Renderer* ren) : renderer(ren) {
  cout<<"constructor called"<<endl;
}

void TextRenderer::initializeFont(const string& path, int size) {
  if(TTF_Init() < 0) {
    cerr<<"error: "<<TTF_GetError()<<endl;
    return;
  }

  font = TTF_OpenFont(path.c_str(), size);

  if(!font) {
    cerr<<"Error loading font: "<<TTF_GetError()<<endl;
    return;
  }

}

void TextRenderer::drawText(const string& text, SDL_Color& color) {
  /* SDL_Color color = {255,255,255}; */
  SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
  if(!surface) {
    cerr<<"Surface creation failed, man: "<<SDL_GetError()<<endl;
    return;
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  if(!texture) {
    cerr<<"Unable to create a texture, error: "<<SDL_GetError()<<endl;
  }
  

  SDL_Rect destRect = {xPos,yPos, surface->w, surface->h};
  SDL_FreeSurface(surface);
  
  SDL_RenderCopy(renderer, texture, nullptr, &destRect);
  SDL_DestroyTexture(texture);
} 


