#include<iostream> 
using namespace std;

bool palindrome(int num){
    int dupl = num;
    int reversed = 0;
    while(num > 0){
        int lastDigit = num % 10 ;
        num = num / 10 ;
        reversed = reversed * 10 + lastDigit;
    }
    if(reversed == dupl) return true;
    else return false;
    
}


int main(){
    int t;
    cout<< "Enter number of testcases : ";
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin >> num;
        if(palindrome(num)) cout<< num <<" is palindrome " << endl;
        else cout <<num  <<" is not palindrome " << endl;
    }
    return 0;
}
