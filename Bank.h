/******************************************************************************
 * Name: Sergey Noritsyn
 * Teacher: Mr.Naccarato's Period 1 TEJ4M1
 * Date: March 8th, 2021
 * Summary: This program stores the Bank struct and declares the relevant 
 * procedures, which are used for adding new accounts to the array field, as well
 * as finding existing accounts either by name or by account number.
 ******************************************************************************/
#include "BankAccount.h"
typedef struct
{
    // fields
    BankAccount accounts[1000];
    int numAccounts;
} Bank;

// procedures
void AddAccount(Bank *bb, BankAccount *b);
void FindAccount(Bank *b);
void FindWithNumber(Bank *b);
void FindWithName(Bank *b);
