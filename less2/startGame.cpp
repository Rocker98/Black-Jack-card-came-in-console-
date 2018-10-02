#include "stdafx.h"
#include "startGame.h"




using namespace std;

void printCard(const Card & card)
{
	switch (card.rank)
	{
	case RANK_2:		std::cout << "2"; break;
	case RANK_3:		std::cout << "3"; break;
	case RANK_4:		std::cout << "4"; break;
	case RANK_5:		std::cout << "5"; break;
	case RANK_6:		std::cout << "6"; break;
	case RANK_7:		std::cout << "7"; break;
	case RANK_8:		std::cout << "8"; break;
	case RANK_9:		std::cout << "9"; break;
	case RANK_10:		std::cout << "TEN"; break;
	case RANK_VALET:	std::cout << "V"; break;
	case RANK_DAMA:	    std::cout << "D"; break;
	case RANK_KOROL:	std::cout << "K"; break;
	case RANK_TYZ:		std::cout << "T"; break;
	}

	switch (card.suit)
	{
	case SUIT_TREFU:	std::cout << "TR"; break;
	case SUIT_BYBNU:	std::cout << "B"; break;
	case SUIT_CHERVU:	std::cout << "CH"; break;
	case SUIT_PIKI:	    std::cout << "P"; break;
	}

}

void printDeck(const array<Card, 52> deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		cout << " ";
	}
	cout << endl;
}

void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;

}

void shuffleDeck(array<Card, 52> &deck)
{
	int a, b;
	do
	{
		a = rand() % 51;
		b = rand() % 51;
	} while (a == b);
	swapCard(deck[a], deck[b]);
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_VALET:	return 10;
	case RANK_DAMA:	    return 10;
	case RANK_KOROL:	return 10;
	case RANK_TYZ:		return 11;
	}

	return 0;
}