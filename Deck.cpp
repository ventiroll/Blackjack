// inherits the Hand Class and takes care of shuffling, populating and dealing the cards

#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

Deck::Deck() {
    populate();
}

void Deck::populate() {
    clear(); // clear inherited Hand::cards

    // Use the static helper to create all 52 cards
    std::vector<Card> freshDeck = Card::createDeck();

    // Add all cards to the deck's Hand vector
    for (const Card& c : freshDeck) {
        cards.push_back(c);
    }
}

void Deck::shuffle() {
    // Use a modern shuffle
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), rng);
}

void Deck::deal(GenericPlayer& aGenericPlayer) {
    if (!cards.empty()) {
        // Give top card to player
        aGenericPlayer.add(cards.back());
        cards.pop_back();
    } else {
        std::cout << "Out of cards! Unable to deal." << std::endl;
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer) {
    // Deal cards while the player wants to hit AND is not busted
    while (!aGenericPlayer.isBusted() && aGenericPlayer.isHitting()) {
        deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.isBusted()) {
            aGenericPlayer.bust();
        }
    }
}
