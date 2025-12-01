// adds or clears the cards to the hand and also calculates the total value of the hand

#include "Hand.h"

Hand::Hand() {}

Hand::~Hand() {
    clear();
}

void Hand::add(const Card& card) {
    cards.push_back(card);
}

void Hand::clear() {
    cards.clear();
}

int Hand::getTotal() const {
    if (cards.empty())
        return 0;

    int total = 0;
    int aceCount = 0;

    // Sum card values, counting Aces as 11 for now
    for (const Card& c : cards) {
        int value = c.getValue();
        total += value;

        if (value == 11) { // Ace
            aceCount++;
        }
    }

    // Convert Aces from 11 → 1 if needed to avoid busting
    while (total > 21 && aceCount > 0) {
        total -= 10;  // 11 → 1
        aceCount--;
    }

    return total;
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}
