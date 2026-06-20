#include<iostream>
#include<vector>
#include<set>
using namespace std;


// brute force

// int removeDuplicate(vector<int> &arr, int n){
//     set<int> st;
//     for(int i=0; i<n; i++){
//         st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it : st){
//        arr[index] = it;
//        index++ ;
//     }
//     return index;
// }

// optimal approch

int removeDuplicate(vector<int> &arr, int n){
    int i = 0;
    for(int j=1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout <<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int result = removeDuplicate(arr, n);
    cout<<"Number of unique element is " << result;
    
    return 0;
}