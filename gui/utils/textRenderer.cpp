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

void TextRenderer::drawText(const string& text, SDL_Color& color, int x, int y ,SDL_Rect box, Alignment align)  {
  /* SDL_Color color = {255,255,255}; */
  SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
  int textW = surface->w;
  int textH = surface->h; 
  if(!surface) {
    cerr<<"Surface creation failed, man: "<<SDL_GetError()<<endl;
    return;
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  if(!texture) {
    cerr<<"Unable to create a texture, error: "<<SDL_GetError()<<endl;
  }
  

  SDL_Rect dstRect;
  dstRect.w = surface->w;
  dstRect.h = surface->h;
  /* dstRect.x = box.x + (box.w - dstRect.w) /2; // i have no clue what im doing */
  dstRect.y = box.y + (box.h - dstRect.h) /2;                                            
  
  switch(align) {
    case Alignment::Left:
      dstRect.x = box.x + 8;
      break;
    case Alignment::Center:
      /* dstRect.x = box.x + 5 ; */
      dstRect.x = box.w + (box.w - dstRect.w) / 2;
      break;
    case Alignment::Right:
      dstRect.x = box.x+box.w -dstRect.w - 8;
      break;
  }

  SDL_FreeSurface(surface);
  
  SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
  SDL_DestroyTexture(texture);
} 


