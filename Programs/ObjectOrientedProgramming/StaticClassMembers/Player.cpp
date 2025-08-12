//
// Created by ajays on 06-07-2025.
//
#include "Player.h"

int Player::numPlayers {0};

Player::Player(string nameVal, int healthVal, int xpVal)
    :name{nameVal}, health{healthVal}, xp{xpVal} {
    ++numPlayers;
}
Player::Player(const Player &source)
    :Player(source.name, source.health, source.xp) {
    // : name{source.name}, health{source.health}, xp{source.xp} {
}
Player::~Player() {
    --numPlayers;
}

int Player::getNumPlayers() {
    return numPlayers;
}