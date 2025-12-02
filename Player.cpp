// inherit the class GenericPlayer and displays the status (Hitting, win, lose etc) of each player
#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : GenericPlayer(name) {}

// ask user if they want to hit
bool Player::isHitting() const {
    char response;
    std::cout << getName() << ", do you want a hit? (Y/N): ";
    std::cin >> response;

    if(response == 'y' || response == 'Y') {
        return true;
    } else {
        return false;
    }
}

// Print that the player has won
void Player::win() const {
    std::cout << getName() << " wins!" << std::endl;
}

// Print that the player has lost
void Player::lose() const {
    std::cout << getName() << " loses." << std::endl;
}

// Print that the result is a tie
void Player::push() const {
    std::cout << getName() << " pushes (tie)." << std::endl;
}
