#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    int arr[n];
    cout <<"Enter the elements of an array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // percompute

    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++ ;
    }

    // Taking queries

    int q;
    cout<<"Enter number of query : ";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter number which you have to query : ";
        cin>>num;
        cout<<"The number of time "<<num <<" is appear is " << mpp[num] <<endl ;
    }
    return 0;
}