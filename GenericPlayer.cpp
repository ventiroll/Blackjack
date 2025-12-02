// -------------------------------------------------------------
// File: GenericPlayer.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the GenericPlayer class, including name handling,
//  bust detection, and shared output formatting.
// -------------------------------------------------------------
#include "GenericPlayer.h"
#include "Card.h"
#include <iostream>

// Initialize the member variables using the member initializer in the constructor.
GenericPlayer::GenericPlayer(const std::string& name) : name(name) {}

// destructor
GenericPlayer::~GenericPlayer() {}


bool GenericPlayer::isBusted() const {
    // Player is busted if total is over 21
    return getTotal() > 21;
}

void GenericPlayer::bust() const {
    // Print a message when the player busts
    std::cout << name << " busted!" << std::endl;
}

std::string GenericPlayer::getName() const {
    return name;
}

void GenericPlayer::setName(const std::string& newName) {
    // Change the player's name
    name = newName;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer) {
    // Print the player's name
    os << aGenericPlayer.getName() << ":\t";

    const auto& cardList = aGenericPlayer.getCards();

    if (cardList.empty()) {
        os << "<empty>";
    } else {
        // Print each card
        // print each card (this uses Card's << operator)
        for (std::vector<Card*>::const_iterator it = cardList.begin(); it != cardList.end(); ++it) {
            os << *(*it) << "\t";   // dereference twice: iterator → pointer → Card
        }

        // print total unless first card face down
        if (aGenericPlayer.getTotal() != 0) {
            os << "(" << aGenericPlayer.getTotal() << ")";
        }
    }

    return os;
}
