// less2.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include "startGame.h"
#include "playBlackJack.h"
#include <iostream>


using namespace std;

void printDeck(const array<Card, 52> deck);
void shuffleDeck(array<Card, 52> &deck);
int getCardValue(const Card &card);

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	array<Card, 52> deck;
	int card = 0;

	for(int i=0;i<MAX_RANKS;i++)
		for (int y = 0; y < MAX_SUITS; y++)
		{
			deck[card].suit = static_cast<CardSuit>(y);
			deck[card].rank = static_cast<CardRank>(i);
			++card;
		}
	for (int i = 0; i < 52; i++)
		shuffleDeck(deck);
	//printDeck(deck);
	int game = playGame(deck);

	if (game==1)
		cout << "You win\n";
	else if (game == 0)
		cout << "You loose\n";
	else if (game == 2)
		cout << "Draw\n";


    return 0;
}

