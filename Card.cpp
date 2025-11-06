// keeps track of all the cards in the deck 

#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

Card::Card() {
    populate();
    shuffle();
}