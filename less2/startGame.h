#pragma once
#include "stdafx.h"
#include "EnumCard.h"
#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Card {
	CardRank rank;
	CardSuit suit;
};


void printCard(const Card &card);
void printDeck(const array<Card, 52> deck);
void swapCard(Card &a, Card &b);
void shuffleDeck(array<Card, 52> &deck);
int getCardValue(const Card &card);

