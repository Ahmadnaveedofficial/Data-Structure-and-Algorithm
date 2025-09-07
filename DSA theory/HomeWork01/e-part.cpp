// e) Write functions to simulate a simple bank account system:
// • deposit(float balance, float amount) → adds money to the balance and returns the updated
// balance.
// • withdraw(float balance, float amount) → subtracts money from the balance if enough funds
// exist, otherwise shows an error.
// Example: If balance = 1000 and user withdraws 500 → new balance = 500.

#include <iostream>
using namespace std;
float deposit(float balance,float amount) {
    balance+=amount;
    return balance;
}
float withdraw(float balance,float amount) {
    if(amount>balance){
        cout<<"Error: Insufficient funds."<<endl;
        return balance;
    }else{
        balance-=amount;
        return balance;
    }
}
int main(){
    float balance=1000;
    cout<<"Initial balance: "<<balance<<endl;
    float amount;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    balance=deposit(balance,amount);
    cout<<"Balance after deposit: "<<balance<<endl;
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    balance=withdraw(balance,amount);
    cout<<"Balance after withdrawal: "<<balance<<endl;
    return 0;
}