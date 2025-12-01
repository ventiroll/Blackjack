#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class Card {
public:
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

    Card(Suit s, Rank r);

    // Getters
    std::string getSuit() const;
    std::string getRank() const;
    int getValue() const;

    // Static helper to create a full deck of 52 cards
    static std::vector<Card> createDeck();

private:
    Suit suit;
    Rank rank;
};

#endif
