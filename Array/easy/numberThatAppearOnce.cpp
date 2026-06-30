#include<iostream>
#include<vector>
using namespace std;


// Brute Force approch

// int numberAppearOnce(vector<int> &arr, int n){
//     for(int i=0; i<n; i++){
//         int num = arr[i];
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(num == arr[j]){
//                 cnt +=1;
//             }
//         }
//         if(cnt == 1){
//             return num;
//         }
//     }
//     return 0;
// }


//optimal approch

int numberAppearOnce(vector<int> &arr, int n){
    int xorr = 0;
    for(int i=0; i<n; i++){
        xorr = xorr ^ arr[i];
    }
    return xorr;
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
    int result = numberAppearOnce(arr, n);
    cout<<"The number that appear once is " <<result;
    return 0;
}