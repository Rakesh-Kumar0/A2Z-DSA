#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

// brute force approch
// vector<vector<int>> fourSum(vector<int> &arr, int n, int target){
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 for(int l=k+1; l<n; l++){
//                     if(arr[i]+arr[j]+ arr[k]+arr[l] == target){
//                     vector<int> temp{arr[i], arr[j], arr[k], arr[l]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());  // it will store all triplets in sorted order
//     return ans;
// }

// better approch
vector<vector<int>> fourSum(vector<int> &arr, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> hashset;
            for(int k=j+1; k<n; k++){
                int sum = arr[i] + arr[j] + arr[k];
                int fourth = target -sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int>temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
            }
            hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());  // it will store all triplets in sorted order
    return ans;
}

// optimal approch

// vector<vector<int>> threeSum(vector<int> &arr, int n){
//     vector<vector<int>> ans;
//     sort(arr.begin(), arr.end());
//     for(int i=0; i<n; i++){
//         if(i>0 && arr[i] == arr[i-1]) continue;
//         int j = i+1;
//         int k = n-1;
//         while(j < k){
//             int sum = arr[i]+arr[j]+arr[k];
//             if(sum > 0){
//                 k--;
//             }
//             else if(sum < 0){
//                 j++;
//             }
//             else {
//                 vector<int> temp = {arr[i] , arr[j], arr[k]};
//                 ans.push_back(temp);
//                 j++;
//                 k--;
//                 while(j <k && arr[j] == arr[j-1]) j++;
//                 while(j<k && arr[k] == arr[k+1]) k--;
//             }
//         }
//     }
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
    int target;
    cout<<"Enter value of target : ";
    cin>>target;
    vector<vector<int>> result = fourSum(arr, n, target);
    for(auto row : result){
       for(auto value : row){
         cout<<value <<" ";
       }
       cout<<endl;
    }
    return 0;
}