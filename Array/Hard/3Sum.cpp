#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

// brute force approch
vector<vector<int>> threeSum(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+ arr[k] == 0){
                    vector<int> temp{arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());  // it will store all triplets in sorted order
    return ans;
}

// better approch

// vector<vector<int>> threeSum(vector<int> &arr, int n){
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         set<int> hashset;
//         for(int j=i+1; j<n; j++){
//             int third = -(arr[i] + arr[j]);
//             if(hashset.find(third) != hashset.end()){
//                 vector<int>temp{arr[i], arr[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());  // it will store all triplets in sorted order
//     return ans;
// }

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
    vector<vector<int>> result = threeSum(arr, n);
    for(auto row : result){
       for(auto value : row){
         cout<<value <<" ";
       }
       cout<<endl;
    }
    return 0;
}