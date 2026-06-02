#include<iostream>

using namespace std;

int main(){

    string s1 = "Rakesh Kumar";

    cout << s1 << endl ;

    // Taking string as an input

    string s2 ;
    cout << "Enter your string : " ;
    cin >> s2; // it will only take first word as an input
    cout << "your string is " << s2 << endl;

    string s3;
    cout << "Enter your string : ";
    getline(cin , s3); // it will take all word before enter
    cout << "your string is " <<s3 <<endl;
}