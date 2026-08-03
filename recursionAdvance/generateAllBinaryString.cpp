#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

void generate(int n, string curr, vector<string> &result){
    // base case
    if(curr.length() == n){
        result.push_back(curr);
        return ;
    }
    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if(curr.empty() || curr.back() != '1'){
        generate(n, curr + "1", result);
    }
}

int main(){
    int n;
    cout<<"Enter length of the string : ";
    cin>>n;
    vector<string> result; // store result
    generate(n, "", result);
    for(string &s : result){
        cout<<s <<" ";
    }
    cout<<endl;

    return 0;

}