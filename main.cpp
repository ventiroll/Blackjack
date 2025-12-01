#include "Game.h"
#include <iostream>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    Game game(name);
    char again = 'y';

    do {
        game.play();
        std::cout << "Play again? (Y/N): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
