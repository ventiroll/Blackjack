#include "Card.h"
#include <string>
#include <vector>

Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

std::string Card::getSuit() const {
    switch (suit) {
        case HEARTS:   return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS:    return "Clubs";
        case SPADES:   return "Spades";
        default:       return "Unknown";
    }
}

std::string Card::getRank() const {
    switch (rank) {
        case TWO:   return "2";
        case THREE: return "3";
        case FOUR:  return "4";
        case FIVE:  return "5";
        case SIX:   return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE:  return "9";
        case TEN:   return "10";
        case JACK:  return "Jack";
        case QUEEN: return "Queen";
        case KING:  return "King";
        case ACE:   return "Ace";
        default:    return "Unknown";
    }
}

int Card::getValue() const {
    switch (rank) {
        case ACE:   return 11;
        case JACK:
        case QUEEN:
        case KING:
            return 10;
        default:
            return static_cast<int>(rank);
    }
}

std::vector<Card> Card::createDeck() {
    std::vector<Card> deck;
    for (int s = HEARTS; s <= SPADES; ++s) {
        for (int r = TWO; r <= ACE; ++r) {
            deck.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
        }
    }
    return deck;
}
