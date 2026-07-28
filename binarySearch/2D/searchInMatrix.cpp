#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force
// bool searchElement(vector<vector<int>> &mat, int n, int m, int target){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(mat[i][j] == target) return true;
//         }
//     }
//     return false;
// }


// better approch
// bool binarySearch(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0, high = n - 1;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (nums[mid] == target)
//                 return true;
//             else if (target > nums[mid])
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return false;
//     }
// bool searchElement(vector<vector<int>> &mat, int n, int m, int target){
//     for(int i=0; i<n; i++){
//         if(mat[i][0] <= target && target <= mat[i][m-1]) return binarySearch(mat[i], target);
//     }
//     return false;
// }

// binary search
bool searchElement(vector<vector<int>> &mat, int n, int m, int target){
    int low = 0;
    int high = n*m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main(){
    int n, m;
    cout<<"Enter no. of rows and cloumns : ";
    cin>>n >>m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout<<"Enter elements of matrix : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    int target;
    cout<<"Enter value of target : ";
    cin>>target;
    bool result = searchElement(mat, n, m, target);
    cout<<result;
    return 0;
}