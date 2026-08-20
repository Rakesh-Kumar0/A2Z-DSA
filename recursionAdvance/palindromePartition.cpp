#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

// functio which check string is palindrome
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
        
    }
    return true;

}

// function which do partition of string
void func(int idx, string s, vector<vector<string>> &res, vector<string> &path){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }

    for(int i=idx; i<=s.size(); i++){
        if(isPalindrome(s,idx,i)){
            path.push_back(s.substr(idx, i-idx+1));
            func(i+1, s, res, path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, res, path);
    return res;

}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    vector<vector<string>> result = partition(s);
    for(auto row : result){
        for(auto it : row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}