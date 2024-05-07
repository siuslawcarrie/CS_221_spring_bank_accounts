/*Carrie Bailey
 * Spring 2024
 * I/O Exercises 
 * Program #4: prints numbers 1 -10 in column 1, squared in column 2, cubed in column 3*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <stdio.h>
#include <cctype>

using namespace std;


int main() {
//VARIABLES
    int account_number = 0;//acct number
    char account_type = ' ';//acct type - checking or savings
    float minimum_balance = 0.00, account_balance = 0.00;//acct balances
    //input file variables & open input file
    ifstream in;
    //open txt file
    in.open("C:\\Users\\siusl\\CLionProjects\\CS221_Spring_Bank_Accounts\\bank_accounts.txt");
    //if file opens
    if (in.good()) {
        //while NOT end of file
        while (!in.eof()) {
            //read in acct number, acct type, min balance, acct balance in that order
            in >> account_number >> account_type >> minimum_balance >> account_balance;
//variables for acct adjustments

            float level_1_interest = .05, level_2_interest = .03;//checking accounts interest rates
            float savings_interest = .04;//savings account interest rates
            float savings_fee = 10, checking_fee = 25;//fees below minimum balance

            cout << fixed << setprecision(2);//2 decimals

//account type checking
            if (account_type == 'C') {
                //more than 5000 above minimum balance is 5% interest
                if (account_balance - minimum_balance > 5000) {
                    //calculate new balance
                    account_balance = account_balance * level_1_interest + account_balance;
                    //display acct type, number and new balance
                    cout << "Account type " << account_type << " account # " << account_number
                         << " is eligible for "
                         << level_1_interest * 100 << "% interest." << endl;
                    cout << "Your new balance is $" <<
                         account_balance << ". " << endl;
                }
                    //less than 5000 over minimum balance is 3% interest
                else if (account_balance - minimum_balance >= 1) {
                    //calculate new balance
                    account_balance = account_balance * level_2_interest + account_balance;
                    //display acct type, number and new balance
                    cout << "Account type " << account_type << " account # " << account_number
                         << " is eligible for "
                         << level_2_interest * 100 << "% interest." << endl;
                    cout << "Your new balance is $" <<
                         account_balance << ". " << endl;
                }
                    //below minimum balance is a $25 fee
                else {
                    //calculate acct balance
                    account_balance = account_balance - checking_fee;
                    //display acct type, number and new balance
                    cout << "Account type " << account_type << " account # " << account_number
                         << " does not meet the minimum balance, therefore is subject to a $" <<
                         checking_fee << " fee. " << endl;
                    cout << "Your new balance is $" << account_balance << ". " << endl;
                }
            }
//savings account
            else {
                //if above minimum balance, 4% interest
                if (account_balance - minimum_balance >= 1) {
                    //calculate new balance
                    account_balance = account_balance * savings_interest + account_balance;
                    //display acct type, number and new balance
                    cout << "Account type " << account_type << " account # " << account_number
                         << " is eligible for "
                         << savings_interest * 100 << "% interest. Your new balance is $" <<
                         account_balance<< ". " << endl;
                    //account below minimum balance
                } else {
                    //calculate new balance
                    account_balance = account_balance - savings_fee;
                    //display acct type, number and new balance
                    cout << "Account type " << account_type << " account # " << account_number
                         << " does not meet the minimum balance, therefore is subject to a $" <<
                         savings_fee << " fee. Your new balance is $" << account_balance<<endl;
                }

            }
        }
        //if text file won't open
    } else {
        cout << "Could not read file";
        return -1;
    }
    return 0;
}
