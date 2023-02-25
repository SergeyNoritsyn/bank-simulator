/******************************************************************************
 * Name: Sergey Noritsyn
 * Teacher: Mr.Naccarato's Period 1 TEJ4M1
 * Date: March 8th, 2021
 * Summary: This program uses the Bank and BankAccount structs to create and
 * store bank account information in an array data structure that is stored 
 * in the Bank struct. It prompts for user input to access an existing account 
 * to either withdraw or deposit money, or to create a new account in the system.
 ******************************************************************************/
#include <stdio.h>
#include "Bank.h"

int main()
{
    /// initialize variables
    Bank bank;
    bank.numAccounts = 0;
    int userChoice = 0;
    
    // Start of program
    printf("Welcome! Would you like to create a new account, or\n" 
           "access an existing account?\n");
    printf("1.Create New Account\t2.Access Account\t3.Exit\n");
    
    // takes input until user "ends" program (enters a 3)
    while(userChoice != 3)
    {
        // checks for proper integer input
        if (!scanf("%d", &userChoice))
        {
            scanf("%*[^\n]"); //discards input line up to the newline
            printf("Could not read an integer value! Please try again.\n");
        }
        // checks for integer input within range
        else if (userChoice < 1 || userChoice > 3)
        {
            printf("Please input an integer between 1 and 3.\n");
        }
        else
        {
            switch(userChoice)
            {
                // Case 1 - Add a new account (to accounts array in Bank struct)
                case 1:
                {
                    // Procedure call with pointers of bank, bankaccount
                    AddAccount(&bank, &(bank.accounts[bank.numAccounts]));
                    printf("What would you like to do now?\n"
                           "1.Create New Account\t2.Access Account\t3.Exit\n");
                    break;
                }
                // Case 2 - Access an existing account to deposit or withdraw money
                case 2:
                {
                    // Procedure call with bank memory pointer
                    FindAccount(&bank);
                    printf("What would you like to do now?\n"
                           "1.Create New Account\t2.Access Account\t3.Exit\n");
                    break;
                }
            }
        }
    }
    return 0;
}
