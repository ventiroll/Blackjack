// -------------------------------------------------------------
// File: House.h
// Project: Blackjack
// Authors: Julie Tong, Mandy Liu
// Date: December 1, 2025
//
// Description:
//  Declares the House class (dealer), including automatic hit
//  rules and the ability to flip the first card.
// -------------------------------------------------------------
#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
    House();

    // Dealer hits while total <= 16
    virtual bool isHitting() const override;

    // Turn over first card, if you implement face-down cards later
    void flipFirstCard();
};

#endif // HOUSE_H
