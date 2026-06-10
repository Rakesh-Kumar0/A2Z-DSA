#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

void divisor(int num){
    vector<int> list ;
    for(int i=1; i*i<=num; i++){
        if(num % i == 0){
            list.push_back(i);
            if(num / i != i){
            list.push_back(num / i);
            }
        }
        
    }
    sort(list.begin(), list.end());
    for(auto it : list){
        cout << it << endl ;
    }
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin>> t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin >> num;
        divisor(num);
        
    }
    return 0;
}