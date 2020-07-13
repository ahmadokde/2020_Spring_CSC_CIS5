/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GCARD_H
 * Author: Ahmad.Okde
 *
 * Created on june 6, 2020, 6:36 AM
 */





#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// constant declaration
const int MAXCARDS = 52;

// Card class definition
class Card
{
public:
    
    // constructors
    Card();
    Card(int cv, int cs);

    // member functions
    int getCardValue();
    int getCardSuit();
    void setCardValue(int cv);
    void setCardSuit(int cs);
    string printCard();

private:
    // member variables
    int cardValue;
    int cardSuit;
};
#endif

