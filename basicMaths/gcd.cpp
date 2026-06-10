#include<iostream>
using namespace std;
 
// brute approch
void gcd(int num1, int num2){
    int gcd = 1;
    for(int i=1; i<=min(num1, num2); i++){
        if(num1 % i == 0 && num2 % i == 0){
            gcd = i;
        }
    }
    cout << gcd ;
}

// better approch
// void gcd(int num1, int num2){
//     int gcd = 1;
//     for(int i=min(num1, num2); i>=1; i++){
//         if(num1 % i == 0 && num2 % i == 0){
//             gcd = i;
//         }
//     }
//     cout << gcd ;
// }

int main(){
    int t;
    cout<<"Enter number of testcases : ";
    cin >> t;
    for(int i=0; i<t; i++){
        int num1, num2;
        cout <<"Enter first number and second number : ";
        cin >> num1 >> num2 ;
        gcd(num1, num2);
    }
    return 0;
}