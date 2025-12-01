#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();
    virtual ~Hand();

    // Add a card to the hand
    void add(const Card& card);

    // Clear the hand
    void clear();

    // Calculate total using Blackjack rules (Ace = 1 or 11)
    int getTotal() const;

    const std::vector<Card>& getCards() const;

    // const std::vector<Card>& getCards() const { return cards; }

protected:
    std::vector<Card> cards;
};

#endif
