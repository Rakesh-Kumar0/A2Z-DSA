#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

// function to find wordladder length
int wordLadderLength(string startWord, string endWord, vector<string> &wordList){
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    // put all word from wordList in set to make as visited 
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();
        if(word == endWord) return step;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                // it exist in the set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, step+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main(){
    int n;
    cout<<"Enter number of word in wordlist : ";
    cin>>n;
    vector<string> wordList(n);
    for(int i=0; i<n; i++){
        cin>>wordList[i];
    }
    string startWord;
    cin>>startWord;
    string endword;
    cin>>endword;
    int result = wordLadderLength(startWord, endword, wordList);
    cout<<result;
    return 0;
}