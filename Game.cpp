// -------------------------------------------------------------
// File: Game.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the Game class, including dealing initial cards,
//  running the player and dealer turns, determining results,
//  and clearing hands at the end of each round.
// -------------------------------------------------------------
#include "Game.h"
#include <iostream>

Game::Game(const std::string& playerName) : deck(), house(), player(playerName) {
    // create full deck
    deck.populate();
    // Shuffle once at the start
    deck.shuffle();
}

Game::~Game() {}

void Game::play() {
    // Start a new round: clear previous hands
    player.clearHand();
    house.clearHand();

    // Deal initial 2 cards to each player
    for (int i = 0; i < 2; ++i) {
        deck.deal(player);
        deck.deal(house);
    }

    // Using the house object call function flipFirstCard()
    house.flipFirstCard();

    // Show initial hands
    std::cout << player << std::endl;
    std::cout << house << std::endl;

    // Give additional cards to player
    deck.additionalCards(player);

    // Flip house's first card face up again
    house.flipFirstCard();

    // Display house object using cout
    std::cout << house << std::endl;

    // If player is not busted, dealer takes cards
    if (!player.isBusted()) {
        deck.additionalCards(house);
    }

    // Determine results
    if (house.isBusted()) {
        if (!player.isBusted()) player.win();
    }
    else if (player.isBusted()) {
        player.lose();
    }
    else {
        int playerTotal = player.getTotal();
        int houseTotal = house.getTotal();

        if (playerTotal > houseTotal) {
            player.win();
        } else if (playerTotal < houseTotal) {
            player.lose();
        } else {
            player.push();
        }
    }

    // call the clearHand function for player object
    player.clearHand();
    // call the clearHand() funtion for house object
    house.clearHand();
}
