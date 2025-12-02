// -------------------------------------------------------------
// File: Hand.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the Hand class, which stores a collection of Card
//  pointers and provides Blackjack-style total calculation.
// -------------------------------------------------------------

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();
    virtual ~Hand();

    // Add a card to the hand
    void add(Card* pCard);

    // Clear the hand
    void clearHand();

    // Calculate total using Blackjack rules (Ace = 1 or 11)
    int getTotal() const;

    // Gives read-only access to the underlying vector (for printing etc.)
    const std::vector<Card*>& getCards() const;

protected:
    std::vector<Card*> cardVector;
};

#endif
