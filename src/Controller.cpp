//
// Created by dylan on 29/7/20.
//

#include "Controller.h"

void Controller::ChangeDirection(Player &player, Player::Direction input) const {

    if(player.prevDirection != input){
        player.direction = input;
        player.Update();
    }else{
        player.frenar();
        printf("Posiciones iguales.");
    }
}

void Controller::HandleInput(bool &running, Player &player) const {
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            running = false;
        }
        player.setPrevDirection(player.direction);
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym) {

                case SDLK_UP:
                    ChangeDirection(player, Player::Direction::kUp);
                    break;

                case SDLK_DOWN:
                    ChangeDirection(player, Player::Direction::kDown);
                    break;

                case SDLK_LEFT:
                    ChangeDirection(player, Player::Direction::kLeft);
                    break;

                case SDLK_RIGHT:
                    ChangeDirection(player, Player::Direction::kRight);
                    break;
                default:
                    ChangeDirection(player, Player::Direction::kNull);
            }
        }
    }
}