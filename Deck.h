#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"
#include <vector>

class Deck : public Hand {
public:
    Deck();

    // Create a full 52-card deck
    void populate();

    // Shuffle the deck
    void shuffle();

    // Deal one card to a player or house
    void deal(GenericPlayer& aGenericPlayer);

    // Give additional cards while player wants more
    void additionalCards(GenericPlayer& aGenericPlayer);
};

#endif // DECK_H
