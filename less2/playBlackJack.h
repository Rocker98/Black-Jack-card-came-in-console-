#pragma once
#include "EnumCard.h"
#include "BlackJackResult.h"
#include <array>
#include <iostream>

Results playGame(const std::array<Card, 52> &deck);

int getCardValue(const Card &card);

bool ownAce(const Card &card);