//
// Created by dylan on 29/7/20.
//

#ifndef NISUT_CONTROLLER_H
#define NISUT_CONTROLLER_H


#include "Player.h"

class Controller {

public:
    void HandleInput(bool &running, Player &player) const;

private:
    void ChangeDirection(Player &player, Player::Direction input) const;

};


#endif //NISUT_CONTROLLER_H
