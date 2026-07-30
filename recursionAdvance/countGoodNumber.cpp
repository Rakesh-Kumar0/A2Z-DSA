#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int MOD = 1e9 +7;
int countGoodNumber(int index, int n){
    // Base case: if we've reached the end of the string
    // Return 1 as we've formed a valid string
    if(index == n) return 1;

    int result = 0;
    // even index : use even digits
    if(index % 2 == 0){
        for(int digit : {0, 2, 4, 6, 8}){
            result = (result + countGoodNumber(index + 1, n)) % MOD;
        }
    }
    // odd index : use prime digits
    else{
        for(int digit : {2, 3, 5, 7}){
            result = (result + countGoodNumber(index + 1, n)) % MOD;
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    int result = countGoodNumber(0, n);
    cout<<"Count of goods are : " << result;
    return 0;
}