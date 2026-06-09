#include<iostream> 
using namespace std;

int reverseNumber(int num){
    int reversedNum = 0;
    while(num > 0){
        int lastDigit = num % 10 ;
        num = num / 10 ;
        reversedNum = reversedNum * 10 + lastDigit ;
    }
    return reversedNum;
}

int main(){
    int t;
    cout << "Enter number of testcases : ";
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin >> num ;
        int result = reverseNumber(num);
        cout << "Reversed number is : " << result << endl ;
    }
    return 0;
}