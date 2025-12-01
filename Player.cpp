// inherit the class GenericPlayer and displays the status (Hitting, win, lose etc) of each player

#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : GenericPlayer(name) {}

bool Player::isHitting() const {
    char response;
    std::cout << getName() << ", do you want a hit? (Y/N): ";
    std::cin >> response;

    return (response == 'y' || response == 'Y');
}

void Player::win() const {
    std::cout << getName() << " wins!" << std::endl;
}

void Player::lose() const {
    std::cout << getName() << " loses." << std::endl;
}

void Player::push() const {
    std::cout << getName() << " pushes (tie)." << std::endl;
}
