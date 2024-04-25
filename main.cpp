/*Carrie Bailey
 * Spring 2024
 * I/O Exercises
 * Program #4: prints numbers 1 -10 in column 1, squared in column 2, cubed in column 3*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


    int main() {

        int account_number =0;
        char account_type = ' ';
        float minimum_balance, account_balance = 0.00;
        //input file variables & open input file
        ifstream in;
        in.open("C:\\Users\\siusl\\CLionProjects\\CS221_Spring_Bank_Accounts\\bank_accounts.txt");
        if (in.good()) {
            while (in) {
                in >> account_number >> account_type >> minimum_balance >> account_balance;


                float level_1_interest = .05, level_2_interest = .03;
                float savings_interest = .04;
                int savings_fee = 10, checking_fee = 25;

//TESTING ***DELETE***
//    account_type = 'S';
//    account_balance = 5000;
//    minimum_balance = 4000;
//account type checking
                if (account_type = 'C') {
                    //more than 5000 above minimum balance is 5% interest
                    if (account_balance - minimum_balance > 5000) {
                        account_balance = account_balance * level_1_interest + account_balance;
                        cout << "Account type " << account_type << " account # " << account_number
                             << " is eligible for "
                             << level_1_interest * 100 << "% interest. Your new balance is $" <<
                             account_balance;
                    }
                        //less than 5000 over minimum balance is 3% interest
                    else if (account_balance - minimum_balance >= 1) {
                        account_balance = account_balance * level_2_interest + account_balance;
                        cout << "Account type " << account_type << " account # " << account_number
                             << " is eligible for "
                             << level_2_interest * 100 << "% interest. Your new balance is $" <<
                             account_balance;
                    }
                        //below minimum balance is a $25 fee
                    else {
                        account_balance = account_balance - checking_fee;
                        cout << "Account type " << account_type << " account # " << account_number
                             << " does not meet the minimum balance, therefore is subject to a $" <<
                             checking_fee << " fee. Your new balance is $" << account_balance;
                    }
                }
//savings account
                else {
                    //if above minimum balance, 4% interest
                    if (account_balance - minimum_balance >= 1) {
                        account_balance = account_balance * savings_interest + account_balance;
                        cout << "Account type " << account_type << " account # " << account_number
                             << " is eligible for "
                             << savings_interest * 100 << "% interest. Your new balance is $" <<
                             account_balance;
                    } else {
                        account_balance = account_balance - savings_fee;
                        cout << "Account type " << account_type << " account # " << account_number
                             << " does not meet the minimum balance, therefore is subject to a $" <<
                             savings_fee << " fee. Your new balance is $" << account_balance;
                    }

                }
            }
        }
        else {
            cout << "Could not read file";
            return -1;
        }
    return 0;
}
