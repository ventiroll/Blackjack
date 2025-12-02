// -------------------------------------------------------------
// File: Hand.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the Hand class, including adding cards, clearing
//  cards, and computing the total value of the hand.
// -------------------------------------------------------------
#include "Hand.h"

Hand::Hand() {
    cardVector.reserve(7);
}

Hand::~Hand() {
    clearHand();
}

void Hand::add(Card* pCard) {
    cardVector.push_back(pCard);
}

void Hand::clearHand() {
    // Delete all allocated cards
    for (std::vector<Card*>::iterator iterate = cardVector.begin();
         iterate != cardVector.end(); ++iterate)
    {
        delete *iterate;
        *iterate = NULL;
    }

    cardVector.clear();
}


int Hand::getTotal() const {
    if (cardVector.empty()) {
        return 0;
    }

    // If first card is face down, total is 0
    if (cardVector[0]->getValue() == 0) {
        return 0;
    }

    int total = 0;
    bool containsAce = false;

    // Iterate using const_iterator (required by rubric)
    for (std::vector<Card*>::const_iterator it = cardVector.begin();  it != cardVector.end(); ++ it) {
        total += (*it)->getValue();

        if ((*it)->getValue() == 1) {
            containsAce = true;
        }
    }

    // Convert Aces from 11 → 1 if needed to avoid busting
    if (containsAce && total <= 11) {
        total += 10;
    }

    return total;
}

const std::vector<Card*>& Hand::getCards() const {
    return cardVector;
}