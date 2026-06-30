#include<iostream>
#include<set>
#include<vector>
using namespace std;

// Brute force approch
// vector<int> intersectionOfTwoSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
//     vector<int> visited(n2); // size is equal to second array and initilize with 0
//     vector<int> ans;
//     for(int i=0; i<n1; i++){
//         for(int j=0; j<n2; j++){
//             if(arr1[i] == arr2[j] && visited[j] == 0){
//                 ans.push_back(arr1[i]);
//                 visited[j] = 1;
//                 break; // because array is sorted so we need not check ahead
//             }
//             if(arr2[j] > arr1[i]) break;
//         }
//     }
//     return ans;
     
//}


// Optimal Approch

vector<int> intersectionOfTwoSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]< arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
       
    return ans;
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
    vector<int> result = intersectionOfTwoSortedArray(arr1, arr2, n1, n2);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}