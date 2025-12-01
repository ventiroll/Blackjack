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
