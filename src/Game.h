//
// Created by dylan on 29/7/20.
//

#ifndef NISUT_GAME_H
#define NISUT_GAME_H


#include <cstddef>
#include <random>
#include "Controller.h"
#include "Renderer.h"

class Game {

public:
    Game(std::size_t gridWidth, std::size_t gridHeight);
    void Run(Controller const &controller, Renderer &renderer,std::size_t target_frame_duration);
    int GetSize() const;
    int GetEjecuciones() const;
    int GetLevel() const;
    Player* getPlayer(int id);
    int ejecuciones;

private:
    Player *player;
    int nivel;
    void Update();
};


#endif //NISUT_GAME_H
