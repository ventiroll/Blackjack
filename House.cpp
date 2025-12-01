// inherit the class GenericPlayer and displays the status (Hitting, win, lose etc) of the house 

#include "House.h"
#include <iostream>

House::House()
    : GenericPlayer("House") {}

bool House::isHitting() const {
    // Standard casino rule: dealer hits 16 or less, stands 17+
    return getTotal() <= 16;
}

void House::flipFirstCard() {
    // Only needed if your Card class supports face-down cards.
    // Your current Card implementation does NOT support this.
    // This function can remain empty or be removed if unused.
}
