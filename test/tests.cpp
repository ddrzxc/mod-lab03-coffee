// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
    // включение
    Automata automata;
    automata.on();
    EXPECT_EQ(WAIT, automata.getState());
}

TEST(automata, test2) {
    // выключение
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(OFF, automata.getState());
}

TEST(automata, test3) {
    // прием денег
    Automata automata;
    automata.on();
    automata.off();
    automata.coin(100);
    EXPECT_EQ(ACCEPT, automata.getState());
    EXPECT_EQ(100, automata.getMoney());
}

TEST(automata, test4) {
    // прием денег 2
    Automata automata;
    automata.on();
    automata.off();
    automata.coin(100);
    automata.coin(30);
    EXPECT_EQ(ACCEPT, automata.getState());
    EXPECT_EQ(130, automata.getMoney());
}

TEST(automata, test5) {
    // правильный выбор
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    EXPECT_EQ(CHECK, automata.getState());
    EXPECT_EQ("Latte 200.000000", automata.getSelected());
}

TEST(automata, test6) {
    // неправильный выбор
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(10);
    EXPECT_EQ(ACCEPT, automata.getState());
    EXPECT_EQ("none", automata.getSelected());
}

TEST(automata, test7) {
    // отмена
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.cancel();
    EXPECT_EQ(WAIT, automata.getState());
    EXPECT_EQ(0, automata.getMoney());
}

TEST(automata, test8) {
    // отмена 2
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    automata.cancel();
    EXPECT_EQ(WAIT, automata.getState());
    EXPECT_EQ(0, automata.getMoney());
    EXPECT_EQ("none", automata.getSelected());
}

TEST(automata, test9) {
    // проверка
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    EXPECT_EQ(CHECK, automata.getState());
    EXPECT_EQ(true, automata.check());
}

TEST(automata, test10) {
    // проверка 2
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(130);
    automata.choice(0);
    EXPECT_EQ(CHECK, automata.getState());
    EXPECT_EQ(false, automata.check());
}

TEST(automata, test11) {
    // готовка
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    automata.cook();
    EXPECT_EQ(COOK, automata.getState());
    EXPECT_EQ(30, automata.getMoney());
}

TEST(automata, test12) {
    // отмена в неподходящее время
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    automata.cook();
    automata.cancel();
    EXPECT_EQ(COOK, automata.getState());
}

TEST(automata, test13) {
    // завершение
    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(230);
    automata.choice(0);
    automata.cook();
    automata.finish();
    EXPECT_EQ(WAIT, automata.getState());
    EXPECT_EQ(0, automata.getMoney());
}
