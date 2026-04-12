/***************************************************************** 

    File: lab6main.c

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

int main(void)
{


    struct Currency usd = { "USD", 0.7353, "United States Dollar" };

    int choice;
    double amount;

    printf("IPC Currency Exchange Machine\n=============================\n");

    // Menu input with validation
    do {
        printf("1) exchange from %s to CAD\n2) exchange from CAD to %s\nYour choice (1 or 2): ",
            usd.iso, usd.fullName);
        scanf("%d", &choice);
        if (choice != 1 && choice != 2)
            printf("That was not a valid option\n");
    } while (choice != 1 && choice != 2);

    printf("Enter Amount: ");
    scanf("%lf", &amount);

    if (choice == 1) { // Foreign to CAD
        double cadAmount = toCAD(&usd, amount);
        int dollars, cents;
        int hundreds, fifties, twenties, tens, fives, toonies, loonies, quarters, dimes, nickels;

        getDollarsAndCents(cadAmount, &dollars, &cents);
        getBills(dollars, &hundreds, &fifties, &twenties, &tens, &fives, &toonies, &loonies);
        makeChange(cents, &quarters, &dimes, &nickels);

        printf("Converting %s to Canadian Dollars\n%.2lf %s is %.2lf CAD\n", usd.fullName, amount, usd.iso, cadAmount);
        printf("* %d hundreds\n* %d fifties\n* %d twenties\n* %d tens\n* %d fives\n* %d toonies\n* %d loonies\n* %d quarters\n* %d dimes\n* %d nickels\n",
            hundreds, fifties, twenties, tens, fives, toonies, loonies, quarters, dimes, nickels);

    }
    else { // CAD to Foreign
        double foreignAmount = fromCAD(&usd, amount);
        printf("Converting Canadian Dollars to %s\n%.2lf CAD is %.2lf %s\n", usd.fullName, amount, foreignAmount, usd.iso);
    }

    return 0;




}