/******************************************************************************
 * Name: Sergey Noritsyn
 * Teacher: Mr.Naccarato's Period 1 TEJ4M1
 * Date: March 8th, 2021
 * Summary: This program stores the BankAccount struct and declares the 
 * relevant procedures for creating an account, as well as depositing to or 
 * withdrawing money from an existing account.
 ******************************************************************************/
typedef struct
{
    // fields
    char name[100];
    int accountNumber;
    double balance;
} BankAccount;

// procedures
void CreateAccount(BankAccount *b);
void DepositMoney(BankAccount *b);
void WithdrawMoney(BankAccount *b);
