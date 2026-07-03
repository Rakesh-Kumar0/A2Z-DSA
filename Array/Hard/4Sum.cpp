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
// vector<vector<int>> fourSum(vector<int> &arr, int n, int target){
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             set<long long> hashset;
//             for(int k=j+1; k<n; k++){
//                 int sum = arr[i] + arr[j] + arr[k];
//                 int fourth = target -sum;
//                 if(hashset.find(fourth) != hashset.end()){
//                     vector<int>temp = {arr[i], arr[j], arr[k], fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//             }
//             hashset.insert(arr[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());  // it will store all triplets in sorted order
//     return ans;
// }


// optimal approch

vector<vector<int>> fourSum(vector<int> &arr, int n, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j != i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i] , arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
                else if(sum < target){
                    k++;
                }
                else {
                    l--;
                }
            }
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