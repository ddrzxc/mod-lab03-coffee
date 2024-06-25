// Copyright 2024 Darya Rybakova
#include "../include/Automata.h"

Automata::Automata() {
    drinks = {"Latte", "Cappuccino", "Raf", "Espresso", "Cacao"};
    prices = {200, 160, 250, 130, 100};
    money = 0;
    state = OFF;
    selected = -1;
}

void Automata::on() {
    if (state == OFF)
        state == WAIT;
}

void Automata::off() {
    if (state == WAIT)
        state = OFF;
}

void Automata::coin(float num) {
    if (state == WAIT)
        state = ACCEPT;
    if (state == ACCEPT && num > 0)
        money += num;
}

void Automata::getMenu() {
    int count = drinks.size();
    for (int i = 0; i < count; i++) {
        std::cout << i << ". " << drinks[i] << " - " << prices[i] << '\n';
    }
}

int Automata::getState() {
    return state;
}

void Automata::choice(int num) {
    if (state == ACCEPT && num >= 0 && num < drinks.size()) {
        selected = num;
        state = CHECK;
    }
}

bool Automata::check() {
    return (prices[selected] <= money);
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        money = 0;
        selected = -1;
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == CHECK && check()) {
        money -= prices[selected];
        selected = -1;
        state = COOK;
    }
}

void Automata::finish() {
    if (state == COOK) {
        money = 0;
        state = WAIT;
    }
}

std::string Automata::getSelected() {
    if (selected == -1)
        return "none";
    return drinks[selected] + std::to_string(prices[selected]);
}
