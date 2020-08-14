//
// Created by dylan on 29/7/20.
//

#ifndef NISUT_PLAYER_H
#define NISUT_PLAYER_H


#include <SDL.h>
#include <vector>

class Player {

private:

    void UpdateHead();

    int gridWidth;
    int gridHeight;


public:


    enum class Direction { kUp, kDown, kLeft, kRight,kNull };
    float tile;
    int size;
    bool alive;
    float headX;
    float headY;

    Player(int gridWidth, int gridHeight);
    void Update();
    void setPrevDirection(Direction direction);
    void frenar();

    Direction direction = Direction::kNull;
    Direction prevDirection = Direction::kNull;

};


#endif //NISUT_PLAYER_H
