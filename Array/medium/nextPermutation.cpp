#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Better Approch
// void nextPermutation(vector<int> &arr, int n){
//     next_permutation(arr.begin(), arr.end());
// }

// Implementation of above algorithm

vector<int> nextPermutation(vector<int> &arr, int n){
    // find break point
    int index = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
        index = i;
        break;
        }
    }
    if(index == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // find number greater than break point
    for(int i=n-1; i>=index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1, arr.end());
    return arr;
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

    vector<int> result = nextPermutation(arr, n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}