#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

// using bit manipulation
// Function to return all subsequences of string s
vector<string> getSubsequences(string s){
    int n = s.size();
    // total number of subsequence
    int total = 1 << n; // 2^n
    // Vector to store all subsequences
    vector<string> subsequences;
    // Iterate over all bit masks from 0 to 2^n - 1
    for(int mask=0; mask<total; mask++){
        string subseq = "";
        // Check each bit position in mask
        for(int i=0; i<n; i++){
            // If i-th bit of mask is set, include s[i]
            if(mask & (1<<i)) subseq +=s[i];
        }
        subsequences.push_back(subseq);
    }
    return subsequences;
}


int main(){
    string s ;
    cout<<"Enter the string : ";
    getline(cin, s);
    vector<string> result = getSubsequences(s);
    for(auto &subseq : result){
        cout<<subseq <<endl;
    }
   
    return 0;

}