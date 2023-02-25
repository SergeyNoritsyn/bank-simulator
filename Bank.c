/******************************************************************************
 * Name: Sergey Noritsyn
 * Teacher: Mr.Naccarato's Period 1 TEJ4M1
 * Date: March 8th, 2021
 * Summary: This program implements the procedures of the Bank struct, which
 * search for a user's account using their name or their account number and
 * add new user accounts to the data structure.
 ******************************************************************************/
#include <stdio.h>
#include "Bank.h"
#include <string.h>
void AddAccount(Bank *bb, BankAccount *b)
{
    // Procedure call on BankAccount procedure to get user input
    CreateAccount(b);
    // Update total number of accounts
    bb -> numAccounts += 1;
}

void FindAccount(Bank *b)
{
    // input vairables
    int choice = 0;
    
    // Input prompt
    printf("Would you like to search by name or by account number?\n"
           "1.Name\t2.Account Number\n");
           
    // Check for correct input
    while (choice != 1 && choice != 2)
    {
        // checks for input to be an integer and within range
        if (!scanf("%d", &choice) || (choice != 1 && choice != 2))
        {
            scanf("%*[^\n]"); //discard line up to the newline
            printf("Could not read an integer value between 1 and 2! Please try again.\n");
        }
    }
    if (choice == 1)
    {
        // Procedure call to search for account name (string)
        FindWithName(b);
    }
    else
    {
        // Procedure call to search for account number (int)
        FindWithNumber(b);
    }
}

void FindWithNumber(Bank *b)
{
    // input/tracker variables
    int accountNum, flag = 0;
    int temp = 0;
    
    // Input prompt
    printf("Enter your account number: ");
    
    // Runs until manually exited using break
    while (1)
    {
        // resets value of counter for new input
        temp = 0;
        
        // checks for integer input (stops improper input errors)
        while (!scanf("%d", &accountNum))
        {
            scanf("%*[^\n]"); //discard line up to the newline
            printf("Could not read an integer value, please try again.\n");
        }
        
        // iterates through non-null inexes of array to check account numbers
        while(temp < b -> numAccounts)
        {
            // check for condition
            if (b -> accounts[temp].accountNumber == accountNum)
            {
                // updates flag (boolean)
                flag = 1;
                break;
            }
            temp++;
        }
        
        // Exits while loop
        if (flag == 1)
        {
            break;
        }
        else // Stays in loop and requests input again
        {
            printf("Sorry, this account number is not saved in the system.\n"
                   "Please try again: ");
        }
    }
    
    // User Input Prompt
    printf("The account with the number %d was found in our database, with the name %s!\n", 
            accountNum, b -> accounts[temp].name);
    printf("Your current balance is $%0.2lf. Would you like to deposit or withdraw from your account?\n", b -> accounts[temp].balance);
    printf("1.Deposit\t2.Withdraw\n");
    int choice = 0;
    // Checks for proper integer input
    while (choice != 1 && choice != 2)
    {
        if (!scanf("%d", &choice))
        {
            scanf("%*[^\n]"); //discard that line up to the newline
            printf("Could not read an integer value, please try again.\n");
        }
        else if (choice < 1 || choice > 2)
        {
            printf("Please enter an integer between 1 and 2.\n");
        }
    }
    if (choice == 1)
    {
        // Procedure call in BankAccount to update balance with a deposit
        DepositMoney(&(b -> accounts[temp]));
    }
    else
    {
        // Procedure call in BankAccount to update balance with a money withdrawal
        WithdrawMoney(&(b -> accounts[temp]));
    }
}

void FindWithName(Bank *b)
{
    // input/tracker variables
    int flag = 0, temp = 0;
    char accountName[100];
    
    // Input Prompt
    printf("Enter your account name: ");
    
    // while loop is exited with a manual break
    while (1)
    {
        // User Input
        scanf(" %[^\n]s", accountName);
        
        // Updates iterator
        temp = 0;
        
        // Checks all account names using string compare
        while(temp < b -> numAccounts)
        {
            if (strcmp(b -> accounts[temp].name, accountName) == 0)
            {
                // Updates flag boolean
                flag = 1;
                break;
            }
            temp++;
        }
        // Exits loop
        if (flag == 1)
        {
            break;
        }
        else // Requests input again
        {
            printf("Sorry, this account name is not saved in the system.\n"
                   "Please try again: ");
        }
    }
    
    // User Input Prompt (same as FindWithNumber() procedure)
    printf("The account with the name %s was found in our database!\n", 
            b -> accounts[temp].name);
    printf("Your current balance is $%0.2lf. Would you like to deposit or withdraw from your account?\n", b -> accounts[temp].balance);
    printf("1.Deposit\t2.Withdraw\n");
    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        if (!scanf("%d", &choice))
        {
            scanf("%*[^\n]"); //discard line up to the newline
            printf("Could not read an integer value, please try again.\n");
        }
        else if (choice < 1 || choice > 2)
        {
            printf("Please enter an integer between 1 and 2.\n");
        }
    }
    if (choice == 1)
    {
        // Deposit money (update balance)
        DepositMoney(&(b -> accounts[temp]));
    }
    else
    {
        // Withdraw money
        WithdrawMoney(&(b -> accounts[temp]));
    }
}
