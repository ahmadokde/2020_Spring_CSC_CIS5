/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameOfWar.cpp
 * Author: Ahmad.Okde
 *
 * Created on june 6, 2020, 6:36 AM
 */




#include "Card.h"
#include <cstdlib>
#include<ctime>
#include <vector>
void generateDeck(Card deck[]);
void createPiles(Card deck[], vector<Card>  &player1, vector<Card>  &player2);
void playGame(vector<Card> &player1, vector<Card> &player2, vector<Card> &mix);


int main()
{
	//create deck of cards
	Card deck[52];
	//generate cards
	generateDeck(deck);

	//create 2 piles of card
	vector<Card> player1;
	vector<Card> player2;
	createPiles(deck, player1, player2);
	
	//play game
	
	while (player1.size() > 0 && player2.size() > 0)
	{
		cout << "Player1 has " << player1.size() << " cards" << endl;
		cout << "Player2 has " << player2.size() << " cards" << endl;
		vector<Card> mix;
		playGame(player1, player2, mix);
	}

	cout << endl << endl;
	cout << "Player1 has " << player1.size() << " cards" << endl;
	cout << "Player2 has " << player2.size() << " cards" << endl;

	if (player1.size() == 0)
	{
		cout << "Player 2 win the match\n\n";
	}
	else
	{
		cout << "Player 1 win the match\n\n";
	}
	return 0;
}

void generateDeck(Card deck[])
{
	
	int index = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Card c(j, i);
			deck[index] = c;
			index++;
		}
	}
	//shuffle cards
	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		int r = rand() % 52;

		Card c = deck[i];
		deck[i] = deck[r];
		deck[r] = c;
	}
}

void createPiles(Card deck[], vector<Card>  &player1, vector<Card>  &player2)
{
	//assign cards to player1
	int i;
	for (i = 0; i < 26; i++)
	{
		player1.push_back(deck[i]);
	}

	//assign cards to player2
	for (i = 26; i < 52; i++)
	{
		player2.push_back(deck[i]);
	}
}

void playGame(vector<Card> &player1, vector<Card> &player2, vector<Card> &mix)
{
	
	Card c1 = player1.at(0);
	Card c2 = player2.at(0);
	cout << "Player 1 has " << c1.printCard() << endl;
	cout << "Player 2 has " << c2.printCard() << endl;
	//remove first card of both players
	player1.erase(player1.begin());
	player2.erase(player2.begin());

	//if player 1 card is greater than player2 card
	if (c1.getCardValue() > c2.getCardValue())
	{
		//add both cards to player 1 pile
		cout << "Player 1 card is greater than Player 2" << endl;
		player1.push_back(c1);
		player1.push_back(c2);
	}
	//if player 1 card is greater than player2 card
	else if (c1.getCardValue() < c2.getCardValue())
	{
		cout << "Player 2 card is greater than Player 1" << endl;
		//add both cards to player 2 pile
		player2.push_back(c1);
		player2.push_back(c2);
	}
	//if same card value
	else
	{
		cout << "\n****** WAR" << endl;
		mix.push_back(c1);
		mix.push_back(c2);
		//if both has 6 cards
		if (player1.size() > 5 && player2.size() > 5)
		{
			//get 5-5 cards from both players
			for (int i = 0; i < 5; i++)
			{
				mix.push_back(player1[0]);
				mix.push_back(player2[0]);

				player1.erase(player1.begin());
				player2.erase(player2.begin());
			}
		}
		Card c3 = player1.at(0);
		Card c4 = player2.at(0);
		cout << "Player 1 has " << c3.printCard() << endl;
		cout << "Player 2 has " << c4.printCard() << endl;
		//remove first card of both players
		player1.erase(player1.begin());
		player2.erase(player2.begin());

		//if player 1 card is greater than player2 card
		if (c3.getCardValue() > c4.getCardValue())
		{
			//add both cards to player 1 pile
			cout << "Player 1 card is greater than Player 2" << endl;
			player1.push_back(c3);
			player1.push_back(c4);

			//add all cards to player1
			for (int i = 0; i < mix.size(); i++)
			{
				player1.push_back(mix[i]);
			}
		}
		//if player 1 card is greater than player2 card
		else if (c3.getCardValue() < c4.getCardValue())
		{
			cout << "Player 2 card is greater than Player 1" << endl;
			//add both cards to player 2 pile
			player2.push_back(c3);
			player2.push_back(c4);
			//add all cards to player2
			for (int i = 0; i < mix.size(); i++)
			{
				player2.push_back(mix[i]);
			}
		}
		else
		{
			//repeat the process again
			mix.push_back(c3);
			mix.push_back(c4);
			playGame(player1, player2, mix);
		}
	}
	
}
