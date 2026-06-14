#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int arr[n];
    cout << "Enter the elements of an array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // precompute

    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cout<<"Enter the number of query : ";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the number which we have to query : ";
        cin>>num;

        // fetching
        cout<<"The number of time  "<< num <<" is appear " << " is " << hash[num] << endl ;
    }
    return 0;
}