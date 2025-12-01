#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player: public GenericPlayer {
    public:
    // constructor 
    Player(const std::string& name = "");

    // destructor
    virtual ~Player();

    // asks if player wants to hit
    virtual bool isHitting() const;

    // display win
    void win() const;

    // display loss
    void lose() const;

    // display tie
    void push() const;
};

#endif