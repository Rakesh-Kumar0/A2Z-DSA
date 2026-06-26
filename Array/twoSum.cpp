#include<iostream> 
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// Brute force approch
// vector<int> twoSum(vector<int> &arr, int n, int target){
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] + arr[j] == target){
//                return {i, j};
//             }
           
//         }
       
//     }
//     return {-1, -1};
// }


// better approch

// vector<int> twoSum(vector<int> &arr, int n, int target){
//     map<int , int> mpp;
//     for(int i=0; i<n; i++){
//         int a = arr[i];
//         int more = target - a;
//         if(mpp.find(more) != mpp.end()){
//             return {mpp[more], i};
//         }
//         mpp[a] = i;
//     }
//     return {-1 , -1};
// }


// optimal approch

string twoSum(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            return "Yes";
        }
        else if(sum < target){
            left++;
        }
        else{
            right++;
        }
    }
    return "No";
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
    string result = twoSum(arr, n, target);
    cout<< result;
    return 0;
}