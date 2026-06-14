#include<iostream>
using namespace std;

int main(){

    string str;
    cout<<"Enter your string  : ";
    cin>>str;
    
    // precomputing
    
    int hash[256] = {0}; // 256 because of all character
    for(int i=0; i<str.size(); i++){
        hash[str[i]] +=1 ; 
        
    }

    int q;
    cout<<"Enter number of query : ";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter character which you have to query : ";
        cin>>ch;

        // fetching
        cout<<"The number of time "<< ch << " is appear is " << hash[ch] <<endl;
    }

    return 0;
}