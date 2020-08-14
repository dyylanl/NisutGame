//
// Created by dylan on 29/7/20.
//

#include "Game.h"


Game::Game(std::size_t gridWidth, std::size_t gridHeight) {

    this->ejecuciones = 0;
    this->nivel = 1;
    this->player = new Player(gridWidth,gridHeight);
}


void Game::Run(const Controller &controller, Renderer &renderer, std::size_t target_frame_duration) {

    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frameStart;
    Uint32 frameEnd;
    Uint32 frameDuration;
    int frameCount = 0;
    bool runing = true;

    while(runing){

        ejecuciones++;
        frameStart = SDL_GetTicks();
        controller.HandleInput(runing,*player);
        Update();
        renderer.Render(*player);
        frameEnd = SDL_GetTicks();
        frameCount++;
        frameDuration = frameEnd - frameStart;
        if(frameEnd - title_timestamp >= 1000){
            renderer.UpdateWindowTitle(nivel,frameCount);
            frameCount = 0;
            title_timestamp = frameEnd;
        }
        if(frameDuration < target_frame_duration){
            SDL_Delay(target_frame_duration - frameDuration);
        }
    }
}


void Game::Update() {

    if (!player->alive) return;
    player->Update();

}

int Game::GetLevel() const { return nivel; }
int Game::GetSize() const { return player->size; }
int Game::GetEjecuciones() const { return this->ejecuciones; }