/***************************************************************** 

    File: lab6.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab6.c lab6main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "lab6.h"

//put the function definition for every function except the main
//here.  Tip: add every function and make them empty functions.
//which create function stubs.

// Calculate coin change (quarters, dimes, nickels)



void makeChange(int cents, int* quarters, int* dimes, int* nickels)
{
    int remainder = cents % 5;

    if (remainder == 1 || remainder == 2)
        cents -= remainder;
    else if (remainder == 3 || remainder == 4)
        cents += (5 - remainder);

    *quarters = cents / 25;
    cents %= 25;

    *dimes = cents / 10;
    cents %= 10;

    *nickels = cents / 5;
}
// Calculate bills and coins for a given amount of dollars
void getBills(int money, int* hundreds, int* fifties, int* twenties,
    int* tens, int* fives, int* toonies, int* loonies)
{
    *hundreds = money / 100;
    money %= 100;

    *fifties = money / 50;
    money %= 50;

    *twenties = money / 20;
    money %= 20;

    *tens = money / 10;
    money %= 10;

    *fives = money / 5;
    money %= 5;

    *toonies = money / 2;
    money %= 2;

    *loonies = money;
}
// Convert from CAD to foreign currency
double fromCAD(const struct Currency* currency, double money) {
    return money * currency->rate;
}

// Convert from foreign currency to CAD
double toCAD(const struct Currency* currency, double money) {
    return money / currency->rate;
}

// Split money into dollars and cents
void getDollarsAndCents(double money, int* dollarPart, int* centPart) {
    int totalCents = (int)(money * 100 + 0.5);
    *dollarPart = totalCents / 100;
    *centPart = totalCents % 100;
}