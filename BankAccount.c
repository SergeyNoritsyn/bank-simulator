/******************************************************************************
 * Name: Sergey Noritsyn
 * Teacher: Mr.Naccarato's Period 1 TEJ4M1
 * Date: March 8th, 2021
 * Summary: This program stores the instructions for the BankAccount struct
 * procedures, in order to create accounts that get stored in the accounts array,
 * as well as update the balances of existing accounts.
 ******************************************************************************/
#include <stdio.h>
#include "BankAccount.h"
void CreateAccount(BankAccount *b)
{
    // User Input
    printf("Enter your name: ");
    scanf(" %[^\n]s", b -> name);
    printf("Enter your account number: ");
    scanf("%d", &b -> accountNumber);
    printf("Enter your initial balance, in dollars: ");
    scanf("%lf", &b -> balance);
}

void DepositMoney(BankAccount *b)
{
    // input variables
    double amount;
    
    // User Input
    printf("Enter the amount of money you wish to deposit.\n");
    scanf("%lf", &amount);
    
    // Update balance using pointer
    b -> balance += amount;
    printf("Thank you! your new balance is $%0.2lf.\n", b -> balance);
}

void WithdrawMoney(BankAccount *b)
{
    //input variables
    double amount;
    
    // User Input
    printf("Enter the amount of money you wish to withdraw.\n");
    scanf("%lf", &amount);
    
    // Update balance (check for maximum withdrawable amount)
    if (b -> balance < amount)
    {
        // Take out maximum amount
        b -> balance = 0;
        printf("You have withdrawn the maximum amount of money from your account.\n"
               "Your balance is now $0.00.\n");
    }
    else
    {
        // Subtract from balance
        b -> balance -= amount;
        printf("Thank you! Your balance is now $%0.2lf.\n", b -> balance);
    }
}
