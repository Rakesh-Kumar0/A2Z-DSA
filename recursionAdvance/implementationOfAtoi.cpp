#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

// Recursive helper
int helper(const string &s, int i, long long num, int sign){
    // If we are out of bounds or at a non-digit, return
    if(i >= s.size() || !isdigit(s[i])) return (int)(sign * num);
    // update number with currrent digit
    num = num * 10 +(s[i] - '0');

    // Clamp if overflow
    if(sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if(sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

    // Recurse for next character
    return helper(s, i+1, num, sign);
}

int myAtoi(string s, int i=0){
    // Skip leading whitespaces
    while(i < s.size() && s[i] == ' ') i++;
    // Handle sign
    int sign = 1;
    if(i < s.size() && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    // Call recursive helper
    return helper(s, i, 0, sign);

}

int main(){
    string s ;
    cout<<"Enter your string : ";
    getline(cin, s);
    int result = myAtoi(s, 0);
    cout<<result;
    return 0;
}