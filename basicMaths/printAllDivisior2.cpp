#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> divisor(int num){
    vector<int> list ;
    for(int i=1; i<= sqrt(num); i++){
        if(num % i == 0){
            list.push_back(i);
            if(num / i != i){
            list.push_back(num / i);
            }
        }
        
    }
    sort(list.begin(), list.end());
    return list;
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin>> t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin >> num;
        vector<int> result = divisor(num);
        for(int it : result){
            cout<<it << endl ;
        }
    }
    return 0;
}