
#include "textRenderer.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

TextRenderer::TextRenderer(SDL_Renderer* ren) : renderer(ren) {
    cout << "constructor called" << endl;
}

void TextRenderer::initializeFont(const string& path, int size) {
    if (TTF_Init() < 0) {
        cerr << "TTF_Init error: " << TTF_GetError() << endl;
        return;
    }

    font = TTF_OpenFont(path.c_str(), size);
    if (!font) {
        cerr << "Error loading font: " << TTF_GetError() << endl;
    }
}

void TextRenderer::drawText(const string& text, SDL_Color& color, int x, int y, SDL_Rect box, Alignment align) {
    // Step 1: Measure text size
    int textW = 0, textH = 0;
    if (TTF_SizeText(font, text.c_str(), &textW, &textH) != 0) {
        cerr << "TTF_SizeText failed: " << TTF_GetError() << endl;
        return;
    }

    // Step 2: Compute destination rect
    SDL_Rect dstRect;
    dstRect.w = textW;
    dstRect.h = textH;
    dstRect.y = box.y + (box.h - textH) / 2;  // vertical center

    switch (align) {
        case Alignment::Left:
            dstRect.x = box.x + 8;
            break;
        case Alignment::Center:
            dstRect.x = box.x + (box.w - textW) / 2;
            break;
        case Alignment::Right:
            dstRect.x = box.x + box.w - textW - 8;
            break;
    }

    // Step 3: Render text
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    if (!surface) {
        cerr << "Surface creation failed: " << TTF_GetError() << endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        cerr << "Texture creation failed: " << SDL_GetError() << endl;
        return;
    }

    // Step 4: Draw the button box for debug
    SDL_RenderDrawRect(renderer, &box);

    // Step 5: Draw the text
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
}
