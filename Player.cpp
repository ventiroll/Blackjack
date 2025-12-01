#include "Player.h"
#include <iostream>

// constructor: initializes player with the given name
Player::Player(const std::string& name) : GenericPlayer(name) {
    // GenericPlayer handles initialization, nothing needed here
}

// destructor
Player::~Player() {}

// asks/checks if player wants to hit
bool Player::isHitting() const {
    std::cout<< name << ", do you want to hit? (y or n ONLY):";
    char response;
    std::cin>>response;
    if (response == 'y' || response == 'Y') {
        return true;
    } else {
        return false;
    }
}

// declares that player has won
void Player::win() const {
    std::cout << name << " wins!" << std::endl;
}

// declares player has lost
void Player::lose() const {
    std::cout << name << "loses." << std::endl;
}

// announces a push
void Player::push() const {
    std::cout << name << "pushes." << std::endl;
}