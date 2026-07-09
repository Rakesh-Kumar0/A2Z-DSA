#include<iostream>
#include<vector>
using namespace std;

// brute force approch
vector<int> firstAndLastOccurrence(vector<int> &arr, int n, int target){
    int first = -1;
    int last = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            if(first == -1) first = i;
            last = i;
        }
    }
    return {first, last};
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    vector<int> result = firstAndLastOccurrence(arr, n , x);
    cout<<"{"<<result[0]<<" "<<result[1]<<"}";
    return 0;
}