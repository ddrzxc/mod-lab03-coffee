// Copyright 2024 Darya Rybakova
#include <vector>
#include <string>
#include <iostream>

enum State
{
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata
{
    private:
    std::vector<std::string> drinks;
    std::vector<float> prices;
    float money;
    State state;
    int selected;

    public:
    Automata();
    void on();
    void off();
    void coin(float num);
    void getMenu();
    int getState();
    void choice(int num);
    bool check();
    void cancel();
    void cook();
    void finish();
    std::string getSelected();
};
