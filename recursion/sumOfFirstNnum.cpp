#include<iostream> 
using namespace std;

void printSum(int i, int sum){
    if(i < 1){
        cout<<sum << endl;
        return ;
    }
    printSum(i-1, sum+i);
}

int main(){

    int t;
    cout<< "Enter the number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter the value of n : ";
        cin>>n;
        printSum(n, 0);
    }
    return 0;
}