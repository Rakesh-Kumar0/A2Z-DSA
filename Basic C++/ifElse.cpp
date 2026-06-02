#include<iostream>

using namespace std;

int main(){

    // write a program that take an input of age and print if you are adult or not

    int age;
    cout << "Enter your age : ";
    cin >> age;
    if(age == 0 || age < 0){
        cout << "please enter a valid age ";
    }
    
    else {
        if(age >= 18){
        cout << "your are adult " << endl;
        }

        else {
        cout << "your are not adult " << endl ;
        }
    }
    return 0;
}