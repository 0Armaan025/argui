#include "../../utils/text/textRenderer.h"
#include "topbar.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Topbar::Topbar(std::vector<std::string> myItems, string windowName,
               SDL_Color bgColor, SDL_Color textColor, string myFont,
               int myOffsetThrashold)
    : items(myItems), WINDOW_NAME(windowName), BG_COLOR(bgColor),
      TEXT_COLOR(textColor), font(myFont), OFFSET_THRASHOLD(myOffsetThrashold) {
  cout << "topbar constructor called" << endl;

  OFFSET_THRASHOLD = myOffsetThrashold;
  BAR_RECT = {0, 0, 890, 40};
  crossBtn = {0, 0, 0, 0};
  currentCrossColor = {0,0,0,255};

  
}

// lerpColor helper function
//

SDL_Color lerpColor(SDL_Color a, SDL_Color b, float t) {
  SDL_Color result;
  result.r = static_cast<Uint8>(a.r + (b.r - a.r) * t);
  result.g = static_cast<Uint8>(a.g + (b.g - a.g) * t);
  result.b = static_cast<Uint8>(a.b + (b.b - a.b) * t);
  result.a = static_cast<Uint8>(a.a + (b.a - a.a) * t);
  return result;
}

// we will draw a cross button now
//

void Topbar::draw(SDL_Renderer *renderer) {

  /* cout<<BG_COLOR.a<<BG_COLOR.r<<BG_COLOR.g<<BG_COLOR.b<<endl; */
  SDL_SetRenderDrawColor(renderer, BG_COLOR.r, BG_COLOR.g, BG_COLOR.b,
                         BG_COLOR.a);
  SDL_RenderFillRect(renderer, &BAR_RECT);

  int xOffset = 10;
  int yCenter = BAR_RECT.y + (BAR_RECT.h / 2);
  TextRenderer text(renderer);
  if (font.c_str() == "" || font.c_str() == " ") {
    cerr << "font is not defined, [FATAL]" << endl;
    return;
  }
  text.initializeFont(font.c_str(), 24);

  int textH = 0;
  int textW = 0;
  int y = yCenter - (textH / 2);
  for (const auto &item : items) {
    /* TTF_SizeText(textRenderer->) */

    SDL_Rect dummyBox = {xOffset, y, textW, textH};
    if (item == "" || item == " ") {
      cout << "[FATAL] item is null" << endl;
      return;
    }
    text.drawText(item, TEXT_COLOR, xOffset, y, dummyBox, Alignment::Left);
    xOffset += textW + OFFSET_THRASHOLD;
  }
  int xTextW = 0, xTextH = 0;

  TTF_SizeText(text.getFont(), "X", &xTextW, &xTextH);

  SDL_Color targetColor = isHoveringOnCrossBtn ? SDL_Color{41,41,41,255} : SDL_Color{0,0,0,255};

  SDL_Rect crossBox = {860, yCenter - xTextH / 2, xTextW + 8, xTextH + 2};
  crossBtn = {860, yCenter - xTextH / 2, xTextW + 8, xTextH + 2};
  /* SDL_RenderDrawRect(renderer, &crossBox); */
  /* if (isHoveringOnCrossBtn) { */
  /**/
  /*   SDL_SetRenderDrawColor(renderer, CROSS_HOVER_BG_COLOR.r, */
  /*                          CROSS_HOVER_BG_COLOR.g, CROSS_HOVER_BG_COLOR.b, */
  /*                          CROSS_HOVER_BG_COLOR.a); */
  /* } else { */
  /**/
  /*   SDL_SetRenderDrawColor(renderer, CROSS_BG_COLOR.r, CROSS_BG_COLOR.g, */
  /*                          CROSS_BG_COLOR.b, CROSS_BG_COLOR.a); */
  /* } */
  currentCrossColor = lerpColor(currentCrossColor, targetColor, HOVER_TRANSITION_SPEED);
  SDL_SetRenderDrawColor(renderer, currentCrossColor.r,currentCrossColor.g, currentCrossColor.b, currentCrossColor.a);
  SDL_RenderFillRect(renderer, &crossBox);


  text.drawText("X", TEXT_COLOR, crossBox.x, yCenter - (xTextH / 2), crossBox,
                Alignment::Center);

  if (WINDOW_NAME == "" || WINDOW_NAME == " ") {
    cout << "[FATAL] WINDOW_NAME item is null" << endl;
    return;
  }
  text.drawText(WINDOW_NAME, TEXT_COLOR, 445, y, BAR_RECT, Alignment::Center);
}

void Topbar::handle(SDL_Event &event) {
  SDL_Cursor* handCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
  // this is a flag, we will create a new file for cursors management later :)

  SDL_Cursor* arrowCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);

  if (event.type == SDL_MOUSEMOTION) {

    int mx = event.motion.x; // returns x;
    int my =
        event.motion.y; // and ofc this will return the y pos of the cursor;

    isHoveringOnCrossBtn = (mx >= crossBtn.x && mx <= crossBtn.x + crossBtn.w &&
                            my >= crossBtn.y && my <= crossBtn.y + crossBtn.h);
    if (isHoveringOnCrossBtn) {
      SDL_SetCursor(handCursor);
      cout << "cursor hovered" << endl;
    }
    else {
      SDL_SetCursor(arrowCursor);
    }


  }


}

bool Topbar::isCrossedClicked(SDL_Event& e, int mouseX, int mouseY) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        if (mouseX >= crossBtn.x && mouseX <= crossBtn.x + crossBtn.w &&
            mouseY >= crossBtn.y && mouseY <= crossBtn.y + crossBtn.h) {
            return true;
        }
    }
    return false;
}
