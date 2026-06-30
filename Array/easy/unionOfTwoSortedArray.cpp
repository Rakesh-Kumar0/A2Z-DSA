#include<iostream>
#include<set>
#include<vector>
using namespace std;

// Brute force approch
// vector<int> unionOfTwoSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
//     set<int> st;
//     for(int i=0; i<n1; i++){
//         st.insert(arr1[i]);
//     }
//     for(int j=0; j<n2; j++){
//         st.insert(arr2[j]);
//     }
//     vector<int> unionArr;
//     int i=0;
//     for(auto it : st){
//         unionArr.push_back(it);
//     }
//     return unionArr;
    
// }

// Optimal Approch

vector<int> unionOfTwoSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
    vector<int> unionArr;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    return unionArr;
}


int main(){
    int n1, n2;
    cout<<"Enter size of an first sorted array : ";
    cin>>n1;
    vector<int> arr1;
    cout<<"Enter elements of an first sotded array : ";
    for(int i=0; i<n1; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    cout<<"Enter size of second sorted array : ";
    cin>>n2;
   vector<int> arr2;
    cout<<"Enter elements of second sorted array : ";
    for(int i=0; i<n2; i++){
       int temp;
       cin>>temp;
       arr2.push_back(temp);
    }
    vector<int> result = unionOfTwoSortedArray(arr1, arr2, n1, n2);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}