//
// Created by dylan on 29/7/20.
//

#ifndef NISUT_RENDERER_H
#define NISUT_RENDERER_H


#include <vector>
#include <SDL.h>
#include "Player.h"

class Renderer {


public:
    Renderer(const std::size_t screenWidth, const std::size_t screenHeight, const std::size_t gridWidth, const std::size_t gridHeight);
    ~Renderer();
    void Render(Player player);
    void UpdateWindowTitle(int nivel, int fps);


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const std::size_t screenWidth,screenHeight, gridWidth, gridHeight;


};


#endif //NISUT_RENDERER_H
