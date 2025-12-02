// -------------------------------------------------------------
// File: main.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Prompts the user for a name, creates a Game object, and 
// continues gameplay until tthe user chooses to stop.
// -------------------------------------------------------------
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
