// -------------------------------------------------------------
// File: Card.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the Card class, including card value logic,
//  flipping behavior, and the overloaded output operator.
// -------------------------------------------------------------
#include "Card.h"
#include <string>
#include <vector>

Card::Card(RANK r, SUIT s, bool isUp) : suit(s), rank(r), isFaceUp(isUp) {}


int Card::getValue() const {
    if(!isFaceUp) {
        return 0;
    }

    int val = rank;

    // face cards = 10
    if (val > 10) {
        val = 10;
    }

    // ace returns a 1
    return val;
}

void Card::flip() {
    isFaceUp = !isFaceUp;
}

// overload operator
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    static const char* RANKS[] = { "0", "A", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "J", "Q", "K" };

    static const char* SUITS[] = { "C", "D", "H", "S" };

    if (aCard.isFaceUp)
        os << RANKS[aCard.rank] << SUITS[aCard.suit];
    else
        os << "XX";

    return os;
}