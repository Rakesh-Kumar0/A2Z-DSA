#include<iostream>
using namespace std;

void countDigits(int num){
    int cnt = 0 ;
    while(num > 0){
        cnt++;
        num = num / 10 ;
    }
    cout <<"Number of digits are : " << cnt << endl ;
}

int main(){
    int t;
    cout<<"Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int num ;
        cout<<"Enter the number : ";
        cin>>num;
        countDigits(num);
    }
    return 0;
}

// time complexicity -> O(log10(n))