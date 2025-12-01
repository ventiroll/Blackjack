#include "House.h"
#include <iostream>

// constructor
House::House(const std::string& name) : GenericPlayer(name) {}

// destructor
House::~House() {}

// determines if dealer should get another card
// dealer should hit on 16 or less
// stay given 17 or more
bool House::isHitting() const {
    // get dealer current total
    int total = getTotal();

    if (total <= 16) {
        return true; // if dealer <= 16, get another card
    } else {
        return false; // if dealer >= 17, stay
    }
}

// flip dealer first card
// check that there is at least one card first
void House::flipFirstCard() const {
    // check if no cards
    if (!cardVector.empty()) { // change to card vector name
        cardVector[0]->flip();
    } else {
        std::cout << "No card to flip!" << std::endl;
    }
}