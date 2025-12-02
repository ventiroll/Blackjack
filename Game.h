// -------------------------------------------------------------
// File: Game.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the Game class, which manages an entire round of
//  Blackjack between the Player and the House.
// -------------------------------------------------------------
#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <string>

class Game {
    public:
    // constructor
    Game(const std::string& playerName);

    // destructor
    ~Game();

    // runs one round of game
    void play();

    private:
    // deck
    Deck deck;

    // dealer
    House house;

    // user player
    Player player;
};

#endif