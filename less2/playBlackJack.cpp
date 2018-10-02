#include "stdafx.h"
#include "playBlackJack.h"

Results playGame(const std::array<Card, 52> &deck)
{
	int yourScore = 0, dillerScore = 0;
	char choice;
	int yourAce = 0, dillerAce=0;

	const Card *ptrCard = &deck[0];

	if (ownAce(*ptrCard))
		dillerAce++;
	dillerScore += getCardValue(*ptrCard++);
	if (ownAce(*ptrCard))
		yourAce++;
	yourScore += getCardValue(*ptrCard++);
	while (1)
	{
		while (1)
		{
			if (ownAce(*ptrCard))
				yourAce++;
			yourScore += getCardValue(*ptrCard++);

			do
			{
				std::cout << "You have " << yourScore << " and diller has " << dillerScore << std::endl;
				std::cout << "Do you want more? Yes(y/Y) or no(n/N)\n";
				std::cin >> choice;
				std::cin.ignore();
			} while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y');
			if (choice == 'n' || choice == 'N')
				break;
		};

		if (yourScore > 21)
		{
			if (yourAce > 0)
			{
				yourScore -= 10;
				yourAce--;
				break;
			}

			return Lose;
		}
		if (yourScore > 21)
			break;							//test
		else if (yourScore < 21)
			break;
	}
	

	while (1)
	{
		while (dillerScore < 17)
		{
			if (ownAce(*ptrCard))
				dillerAce++;
			dillerScore += getCardValue(*ptrCard++);
		}

		if (dillerScore > 21)
		{
			if (dillerAce > 0)
			{
				dillerAce--;
				dillerScore -= 10;
				break;
			}
				std::cout << "You have " << yourScore << " and diller has " << dillerScore << std::endl;
				return Win;
		}
		if (dillerScore > 17 && dillerScore < 21)
			break;
	}


	std::cout << "You have " << yourScore << " and diller has " << dillerScore << std::endl;

	if (dillerScore > yourScore)
		return Lose;
	else if (dillerScore < yourScore)
		return Win;
	else 
		return Draw;
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

bool ownAce(const Card &card)
{
	if (card.rank == RANK_TYZ)
	{
		std::cout << "Got Ace\n";
		return true;
	}
	else return false;
}
