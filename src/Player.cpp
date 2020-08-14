//
// Created by dylan on 29/7/20.
//

#include "Player.h"
#include <iostream>

using namespace std;


Player::Player(int gridWidth, int gridHeight) {

    this->gridHeight=gridHeight;
    this->gridWidth = gridWidth;
    this->headX = gridWidth / 2;
    this->headY = gridHeight / 2;
    this->size = 1;
    this->tile = 0.025f;
    this->alive = true;

}

void Player::Update() {


    //HACE FALTA ESTE ??? R: SI // GUARDA LA POSICION ANTERIOR PARA VER SI SE MOVIO.
    SDL_Point prev_cell{static_cast<int>(headX), static_cast<int>(headY)};
    UpdateHead();
    SDL_Point current_cell{static_cast<int>(headX), static_cast<int>(headY)};

    // SI SE MOVIO ENTONCES ACTUALIZO EL CUERPO
    if(current_cell.x == prev_cell.x || current_cell.y != prev_cell.y){
        UpdateHead();
    }
}

void Player::setPrevDirection(Direction direction){
    this->prevDirection = direction;
}

void Player::frenar(){
    this->direction=Direction::kNull;
}

void Player::UpdateHead() {

    switch (direction) {
        // Lo deja quieto.
        case Direction::kNull:
            break;
        case Direction::kUp:
            headY -= tile;
            break;
        case Direction::kDown:
            headY += tile;
            break;
        case Direction::kLeft:
            headX -= tile;
            break;
        case Direction::kRight:
            headX += tile;
            break;
    }

    // Elimina la posicion antigua.
    headX = fmod(headX + gridWidth, gridWidth);
    headY = fmod(headY + gridHeight, gridHeight);
    cout << "Posicion en x: " << headX << endl;
    cout << "Posicion en y: " << headY << endl;
}








