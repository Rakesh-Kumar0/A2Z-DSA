#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

// brute force
// Check if a string has valid parentheses
// bool isValid(string s){
//     int balance = 0;
//     for(char c : s){
//         if(c == '(') balance++;
//         else balance--;
//         if(balance < 0) return false;
//     }
//     if(balance == 0) return true;
//     return false;
// }
// void generateAll(int n, string curr, vector<string> &res){
//     if(curr.length() == 2 * n){
//         if(isValid(curr)) res.push_back(curr);
//         return ;
//     }
//     generateAll(n, curr + '(', res);
//     generateAll(n, curr + ')', res);
// }

// vector<string> generateParanthesis(int n){
//     vector<string> res;
//     generateAll(n, "", res);
//     return res;
// }


// optimal approch
void backtraking(string curr, int open, int close, int n, vector<string> &res){
    if(curr.length() == 2 * n){
        res.push_back(curr);
        return ;
    }
    if(open < n) backtraking(curr + '(', open + 1, close, n, res);
    if(close < open) backtraking(curr + ')', open, close + 1, n, res);
}

vector<string> generateParanthesis(int n){
    vector<string> res;
    backtraking("", 0, 0, n, res);
    return res;
}

int main(){
    int n;
    cout<<"Enter length of the string : ";
    cin>>n;
    vector<string> result = generateParanthesis(n);
    for(string s : result){
        cout<<s <<" ";
    }
    cout<<endl;

    return 0;

}