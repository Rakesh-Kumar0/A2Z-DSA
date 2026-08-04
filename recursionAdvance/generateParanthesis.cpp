#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

void generate(int n, string curr, vector<string> &result){
    
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