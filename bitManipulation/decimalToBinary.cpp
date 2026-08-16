#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string convertToBinary(int n){
    string res = "";
    while(n > 0){
        if(n % 2 == 1) res += '1';
        else res += '0';
        n = n/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    string result = convertToBinary(n);
    cout<<result;

    return 0;
}