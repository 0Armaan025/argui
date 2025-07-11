#pragma
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

class Setup {
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int w,h ;
  public:
    Setup(SDL_Window* window, SDL_Renderer* renderer, int WINDOW_HEIGHT, int WINDOW_WIDTH);

    void cleanSDL(SDL_Window* window, SDL_Renderer* renderer);

    /* void runEventLoop(SDL_Window* window, SDL_Renderer* renderer); */
};
