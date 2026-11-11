#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

// function to find wordladder length
vector<vector<string>> wordLadderLength(string startWord, string endWord, vector<string> &wordList){
    // put all word from wordList in set to make as visited 
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);
    int level = 0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // erase all word that has been used in previous levels of transformation
        if(vec.size() > level){
            level++;
            for(auto it : usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        string word = vec.back();
        // store the answer
        if(word == endWord){
            // the first sequence where we reached end
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
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
    vector<vector<string>> result = wordLadderLength(startWord, endword, wordList);
    for(auto row : result){
        for(auto it : row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}