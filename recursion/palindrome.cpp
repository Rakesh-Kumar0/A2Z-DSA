#include<iostream>
#include<string>
using namespace std;

bool palindrome(string str, int l, int n){
    if(l >= n / 2) return true;
    if(str[l] != str[n-l-1]) return false;
    return palindrome(str, l+1, n);
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        string str;
        cout <<"Enter string : ";
        cin >>str;
        int n = str.length();
        if(palindrome(str, 0, n)) cout<<"Given string is palindrome "<< endl;
        else cout<<"Given string is not palindrome " <<endl;
    }
    return 0;
}