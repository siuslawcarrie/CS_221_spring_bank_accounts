/*Carrie Bailey
 * Spring 2024
 * I/O Exercises
 * Program #4: prints numbers 1 -10 in column 1, squared in column 2, cubed in column 3*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
//   fstream newfile;
//   newfile.open("tpoint.txt",ios::out);  // open a file to perform write operation using file object
//   if(newfile.is_open()) //checking whether the file is open {
//      newfile<<"Tutorials point \n"; //inserting text
//      newfile.close(); //close the file object
//   }
//   newfile.open("tpoint.txt",ios::in); //open a file to perform read operation using file object
//   if (newfile.is_open()){ //checking whether the file is open
//      string tp;
//      while(getline(newfile, tp)){ //read data from file object and put it into string.
//         cout << tp << "\n"; //print the data of the string
//      }
//      newfile.close(); //close the file object.
//   }
//}
    int account_number;
    char account_type;
    float minimum_balance, account_balance, level_1_interest = .03, level_2_interest = .05;
    float savings_interest = .04;
    int savings_fee = 10, checking_fee = 25;

//TESTING ***DELETE***
    `account_type = 'S';
    account_balance = 13000;
    minimum_balance = 4000;
//account type checking
    if (account_type = 'C') {
        if (account_balance - minimum_balance > 5000){
            account_balance = account_balance * level_2_interest + account_balance;
        cout << "Your account is eligible for " << level_2_interest * 100 << "% interest. Your new balance is: $"
             << account_balance;
        }
        else if (account_balance - minimum_balance >= 1)
        {
            account_balance = account_balance * level_1_interest + account_balance;
            cout << "Your account is eligible for " << level_1_interest * 100 << "% interest. Your new balance is: $"
                 << account_balance;
        }
        else {
        account_balance = account_balance - checking_fee;
        cout<<"Your account does not meet the minimum balance and is subject to a $"<<checking_fee<<" fee. Your new balance is $"<<account_balance;
    }
        }
    if (account_type = 'S'){
            if (account_balance - minimum_balance >=1){
                account_balance = account_balance * savings_interest + account_balance;
                cout <<"Account type " <<account_type<<" account # "<<account_number<<" is eligible for "<<savings_interest * 100<<"% interest. Your new balance is $"<<account_balance;
            }

    }

      return 0;
}
