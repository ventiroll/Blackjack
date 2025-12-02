#include "Game.h"
#include <iostream>
#include <string>

int main() {
    // Welcome message
    std::cout << "Welcome to Blackjack!\n";

    // Ask for player name
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;   // OK for single-word names

    // Create the game object
    Game game(name);
    // loop control
    char again = 'y';

    // Play rounds until user quits
    do {
        game.play();
        std::cout << "Play again? (Y/N): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
