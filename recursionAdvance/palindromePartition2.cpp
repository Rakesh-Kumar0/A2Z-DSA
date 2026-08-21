#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

// function to check palindrome
bool isPalindrome(int i, int j, string s){
    while(i <= j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

// function to find partition
int fun(int i, int n, string &s, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(i, j, s)){
            int cost = 1 + fun(j+1, n, s, dp);
            minCost = min(minCost, cost);
        }
        
    }
    return dp[i] = minCost;
}
int palindromePartition(string &s){
    int n = s.size();
    vector<int> dp(n, -1);
    return fun(0, n, s, dp) - 1;
}

int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    int result = palindromePartition(s);
    cout<<result;
    return 0;
}