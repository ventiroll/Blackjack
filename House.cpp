// -------------------------------------------------------------
// File: House.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the House class, including dealer behavior for
//  hitting on totals of 16 or less and flipping the first card.
// -------------------------------------------------------------
#include "House.h"
#include <iostream>

House::House() : GenericPlayer("House") {}

bool House::isHitting() const {
    // Standard casino rule: dealer hits 16 or less, stands 17+
    return getTotal() <= 16;
}

// Flip the first card in the hand (if any exist)
void House::flipFirstCard() {
    if (!getCards().empty()) {
        getCards()[0]->flip();   // Flip first card
    }
    else {
        std::cout << "No cards to flip for the House." << std::endl;
    }
}
