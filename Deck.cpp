// -------------------------------------------------------------
// File: Deck.cpp
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Implements the Deck class, including creation of a standard
//  52-card deck, shuffling, dealing cards, and providing extra
//  cards to players during the game.
// -------------------------------------------------------------
#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck() {
    cardVector.reserve(52);
    populate();
}

void Deck::populate() {
    clearHand(); // clear inherited Hand::cards

    // Create a full deck: loop through suits and ranks
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            // call function add(new Card(static_cast<Card::RANK>(r), static_cast<Card::SUIT>(s)))
            add(new Card(static_cast<Card::RANK>(r),
                          static_cast<Card::SUIT>(s)));
        }
    }
}

void Deck::shuffle() {
    static std::mt19937 rng{ std::random_device{}() };
    std::shuffle(cardVector.begin(), cardVector.end(), rng);
}

void Deck::deal(Hand& aHand) {
    // Deal one card if the deck is not empty
    if (!cardVector.empty()) {
        aHand.add(cardVector.back());   // give the last card
        cardVector.pop_back();          // remove it from the deck
    }
    else {
        std::cout << "Out of cards! Unable to deal.\n";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer) {
    // Keep dealing cards while the player wants to hit and hasn't busted
    while (!aGenericPlayer.isBusted() && aGenericPlayer.isHitting()) {
        deal(aGenericPlayer);  // deal a card to the player

        std::cout << aGenericPlayer << std::endl;

        // If the player goes over 21, they bust
        if (aGenericPlayer.isBusted()) {
            aGenericPlayer.bust();
        }
    }
}
