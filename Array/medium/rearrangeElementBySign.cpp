#include<iostream>
#include<vector>
using namespace std;

// Brute force approch
// void rearrangeElementsBySign(vector<int> &arr, int n){
//     vector<int> pos; // it will store positive elements
//     vector<int> neg; // it will store negative elements
//     for(int i=0; i<n; i++){
//         if(arr[i] > 0){
//             pos.push_back(arr[i]);
//         }
//         else {
//             neg.push_back(arr[i]);

//         }
//     }
//     for(int i=0; i<n/2; i++){
//         arr[2 * i] = pos[i];
//         arr[2 * i +1] = neg[i];
//     }
// }


// Optimal Approch

vector<int> rearrangeElementsBySign(vector<int> &arr, int n){
    vector<int> ans(n);
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex = posIndex + 2;
        }
        else {
            ans[negIndex] = arr[i];
            negIndex = negIndex + 2;
        }
    }
    return ans;
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
    vector<int> result = rearrangeElementsBySign(arr, n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}