#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House: public GenericPlayer {
    public:
    // constructor
    House(const std::string& name = "Dealer");

    // destructor
    virtual ~House();

    // decides if dealer should hit
    virtual bool isHitting() const;

    // flips dealer first card
    void flipFirstCard() const;
};

#endif