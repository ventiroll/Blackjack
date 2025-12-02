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
