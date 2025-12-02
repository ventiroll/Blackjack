// -------------------------------------------------------------
// File: Deck.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the Deck class, which inherits Hand and is used to
//  populate, shuffle, deal cards, and provide additional cards
//  to GenericPlayer objects.
// -------------------------------------------------------------
#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"
class Deck : public Hand {
public:
    Deck();
    virtual ~Deck() {}

    // Create a full 52-card deck
    void populate();

    // Shuffle the deck
    void shuffle();

    // Deal one card to a player or house
    void deal(Hand& aHand);

    // Give additional cards while player wants more
    void additionalCards(GenericPlayer& aGenericPlayer);
};

#endif // DECK_H
