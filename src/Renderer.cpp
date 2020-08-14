//
// Created by dylan on 29/7/20.
//

#include <string>
#include "Renderer.h"



Renderer::Renderer(const std::size_t screenWidth, const std::size_t screenHeight, const std::size_t gridWidth, const std::size_t gridHeight)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          gridWidth(gridWidth),
          gridHeight(gridHeight){


    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error al iniciar el renderer.");
    }
    this->window = SDL_CreateWindow("Nisut", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    if(this->window == nullptr || this->renderer == nullptr){
        printf("Error en la creacion del renderer.");
    }
}

Renderer::~Renderer(){
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Renderer::Render(Player player) {

    SDL_Rect block;
    block.w = screenWidth/gridWidth;
    block.h = screenHeight/gridHeight;

    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    //cabeza
    block.x = static_cast<int>(player.headX) * block.w;
    block.y = static_cast<int>(player.headY) * block.h;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x7A, 0xCC, 0xFF);
    SDL_RenderFillRect(renderer, &block);

    SDL_RenderPresent(renderer);
}

void Renderer::UpdateWindowTitle(int nivel, int fps) {
    std::string title{"NIVEL: " + std::to_string(nivel) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(window, title.c_str());
}