/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.cpp
 * Author: Ahmad.Okde
 *
 * Created on june 6, 2020, 6:36 AM
 */




// Card class implementation

// Header files section
#include "Card.h"

// default constructor implementation
Card::Card()
{

}

// parameterized constructor implementation
Card::Card(int cv, int cs)
{
    setCardValue(cv);
    setCardSuit(cs);
}

// getCardValue function implementation
int Card::getCardValue()
{
    return cardValue;
}

// getCardSuit function implementation
int Card::getCardSuit()
{
    return cardSuit;
}

// setCardValue function implementation
void Card::setCardValue(int cv)
{
    cardValue = cv;
}

// setCardSuit function implementation
void Card::setCardSuit(int cs)
{
    cardSuit = cs;
}

// printCard function implementation
string Card::printCard()
{
    string values[13] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    string suits[4] = { "Club", "Diamond", "Heart", "Spade" };
    return values[cardValue] + " of " + suits[cardSuit];
} // end of printCard function

