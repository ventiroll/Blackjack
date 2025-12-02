#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"
#include <string>
#include <iostream>

class GenericPlayer : public Hand {
    public:
    // constructor
    GenericPlayer(const std::string& name = "");

    // destructor
    virtual ~GenericPlayer();

    // pure virtual so can be overriden in Player & House
    virtual bool isHitting() const = 0;

    // checks if the player's hand value is over 21
    bool isBusted() const;
    void bust() const;

    // return player name
    std::string getName() const;

    // set player name
    void setName(const std::string& newName);

    protected:
    // player name
    std::string name;
};

// overloader for GenericPlayer
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

#endif