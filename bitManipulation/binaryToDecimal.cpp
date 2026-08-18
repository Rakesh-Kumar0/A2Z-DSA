#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int convertToDecimal(string s){
    int length = s.size();
    int num = 0;
    int p2 = 1;
    for(int i=length-1;i>=0; i--){
        if(s[i] == '1') num +=p2;
        p2 = p2*2;
    }
    return num;
}

int main(){
    string s;
    cout<<"Enter binary string : ";
    cin>>s;
    int result = convertToDecimal(s);
    cout<<result;

    return 0;
}