#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

// Brute force approch
// vector<int> majorityElement(vector<int> &arr, int n){
//     vector<int> list;
//     for(int i=0; i<n; i++){
//         if(list.size() == 0 || list[0] != arr[i]){
//             int cnt = 0;
//             for(int j=0; j<n; j++){
//                 if(arr[i] == arr[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/3){
//                 list.push_back(arr[i]);
//             }
//         }
//         if(list.size() == 2) break;
//     }
//     return list;
// }


// better approch
// vector<int> majorityElement(vector<int> &arr, int n){
//     vector<int> list;
//     map<int, int> mpp;
//     int mini = int(n/3) +1;
//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++;
//         if(mpp[arr[i]]==mini){
//             list.push_back(arr[i]);
//         }
//         if(list.size() == 2) break;
//     }
//     return list;
// }

// optimal approch
vector<int> majorityElement(vector<int> &arr, int n){
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for(int i=0; i<n; i++){
        if(cnt1 == 0 && arr[i] != ele2){
            cnt1++;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2++;
            ele2 = arr[i];
        }
        else if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    int cnt3 = 0;
    int cnt4 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1) cnt3++;
        if(arr[i] == ele2) cnt4++;
    }
    int mini = int(n/3) + 1;
    if(cnt3 >= mini) ans.push_back(ele1);
    if(cnt4 >= mini) ans.push_back(ele2);
    return ans ;
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
    vector<int> result = majorityElement(arr, n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}