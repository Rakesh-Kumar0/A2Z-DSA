#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Brute Force
// void moveAllZeroToEnd(vector<int> &arr, int n){
//     vector<int> temp;
//     for(int i=0; i<n; i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }
//     for(int i=0; i<temp.size(); i++){
//         arr[i] = temp[i];
//     }
//     for(int i=temp.size(); i<n; i++){
//         arr[i] = 0;
//     }
// }

// optimal apporch
// using two pointer approch

void moveAllZeroToEnd(vector<int> &arr, int n){
    int j = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i=j+1; i<n; i++){
        if(arr[i] != 0){
            swap(arr[j], arr[i]);
            j++;
        }
    }
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
    moveAllZeroToEnd(arr, n);
    for(auto it : arr){
        cout<<it <<" ";
    }
    return 0;
}