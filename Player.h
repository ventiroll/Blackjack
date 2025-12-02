// -------------------------------------------------------------
// File: Player.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the Player class, representing the human player
//  and implementing interactive hit decisions and result messages.
// -------------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
    Player(const std::string& name);

    // Ask user if they want to hit
    virtual bool isHitting() const override;

    // These print outcome messages
    void win() const;
    void lose() const;
    void push() const;
};

#endif // PLAYER_H
