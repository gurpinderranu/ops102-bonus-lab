/***************************************************************** 

    File: lab6.h

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

	The function prototypes for every function you write go
	into the header file.  You do not need to modify this file
        
***************************************************************/

/*this struct is used by all functions in lab 6.  We typically declare structs in 
.h files so that it can be included in all files that need to use the struct*/


/* Add the function prototypes for the lab6 to this file.  
 below this comment. You can copy these from the lab 
 specifications.  Don't forget to add comments!*/

 // Struct to represent a currency
struct Currency {
    char iso[4];         // 3-letter ISO code, e.g., "USD"
    double rate;         // exchange rate
    char fullName[101];  // full name of currency, e.g., "United States Dollar"
};

 
 
 // Function prototypes
void makeChange(int cents, int* quarters, int* dimes, int* nickels);
void getBills(int money, int* hundreds, int* fifties, int* twenties,
    int* tens, int* fives, int* toonies, int* loonies);
double fromCAD(const struct Currency* currency, double money);
double toCAD(const struct Currency* currency, double money);
void getDollarsAndCents(double money, int* dollarPart, int* centPart);

