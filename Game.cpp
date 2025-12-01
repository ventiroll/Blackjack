// keeps track of the player involved and runs the BlackJack game + MAIN? 

#include "Game.h"
#include <iostream>

Game::Game(const std::string& playerName)
    : deck(), house(), player(playerName)
{
    // Shuffle once at the start
    deck.shuffle();
}

Game::~Game() {}

void Game::play() {
    // Start a new round: clear previous hands
    player.clear();
    house.clear();

    // If the deck is running low, repopulate and reshuffle
    if (deck.getCards().size() < 10) {
        deck.populate();
        deck.shuffle();
        std::cout << "New deck is populated and shuffled.\n";
    }

    // Initial deal: player, house, player, house
    deck.deal(player);
    deck.deal(house);
    deck.deal(player);
    deck.deal(house);

    std::cout << "\n--- New Round ---\n";
    std::cout << player << std::endl;
    std::cout << house << std::endl;

    // Player's turn
    deck.additionalCards(player);

    // If player busts, house automatically wins
    if (player.isBusted()) {
        player.lose();
    } else {
        // House's turn
        deck.additionalCards(house);

        if (house.isBusted()) {
            player.win();
        } else {
            int playerTotal = player.getTotal();
            int houseTotal  = house.getTotal();

            std::cout << "\nFinal totals: "
                      << player.getName() << " = " << playerTotal
                      << ", House = " << houseTotal << "\n";

            if (playerTotal > houseTotal) {
                player.win();
            } else if (playerTotal < houseTotal) {
                player.lose();
            } else {
                player.push();
            }
        }
    }

    std::cout << "\nFinal hands:\n";
    std::cout << player << std::endl;
    std::cout << house << std::endl;
    std::cout << "-----------------\n";
}
