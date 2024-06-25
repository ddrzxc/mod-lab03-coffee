// Copyright 2024 Darya Rybakova
#include "../include/Automata.h"

int main() {
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    std::cout << automata.getMoney() << "\n";
    automata.choice(0);
    std::cout << automata.getSelected() << '\n';
    automata.check();
    automata.cook();
    std::cout << automata.getMoney() << '\n';
    automata.finish();
    std::cout << automata.getState() << '\n';
    automata.off();
}
