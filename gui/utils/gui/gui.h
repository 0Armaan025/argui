#include <SDL2/SDL.h>
#include "../component/Component.h"
#include <vector>
#include "../../components/button/button.h"
#pragma once


class ARGui {
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;

  public:
    std::vector<Component*> components;

    void addComponent(Component* c) {
      components.push_back(c);
    }

    void draw(SDL_Renderer* renderer) {
      for(auto* c: components) {
        c->draw(renderer);
      }
    }

    void handle(SDL_Event& e) {
      for(auto* c: components) {
        c->handle(e);
      }
    }

    ARGui(SDL_Renderer* ren, SDL_Window* win);

    /* void drawButton(Button& button); */

};
