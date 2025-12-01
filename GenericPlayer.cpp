#include "GenericPlayer.h"
#include "Card.h"
#include <iostream>

GenericPlayer::GenericPlayer(const std::string& name)
    : name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::isBusted() const {
    return getTotal() > 21;
}

void GenericPlayer::bust() const {
    std::cout << name << " busts!" << std::endl;
}

std::string GenericPlayer::getName() const {
    return name;
}

void GenericPlayer::setName(const std::string& newName) {
    name = newName;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.getName() << ":\t";

    const auto& cardList = aGenericPlayer.getCards();

    if (cardList.empty()) {
        os << "<empty>";
    } else {
        // Print each card
        for (const Card& c : cardList) {
            os << c.getRank() << " of " << c.getSuit() << "\t";
        }
        os << "(" << aGenericPlayer.getTotal() << ")";
    }

    return os;
}
