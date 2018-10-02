#pragma once
#include "EnumCard.h"
#include <array>
#include <iostream>

bool playGame(const std::array<Card, 52> &deck);

int getCardValue(const Card &card);

bool ownAce(const Card &card);