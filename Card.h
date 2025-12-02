// -------------------------------------------------------------
// File: Card.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the Card class, representing a single playing card 
//  with rank, suit, and face-up/face-down status.
// -------------------------------------------------------------

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <iostream>

class Card {
public:
    // suit enumerator
    enum SUIT { CLUBS, DIAMONDS, HEARTS, SPADES };

    // rank enumerator (RANK are ACE = 1, TWO, ..... , QUEEN, KING.)
    enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    // constructor 
    //Card(in rank : RANK = ACE, in suit : RANK = SPADES, in isUp : bool = true)
    Card(RANK r = ACE, SUIT s = SPADES, bool isUp = true);

    // Getters
    int getValue() const;

    // flips card orientation
    void flip();

    // Friend operator<< for printing
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
    SUIT suit;
    RANK rank;
    bool isFaceUp;
};

#endif
