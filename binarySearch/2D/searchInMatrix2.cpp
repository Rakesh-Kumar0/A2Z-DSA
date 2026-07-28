#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// binary search
bool searchElement(vector<vector<int>> &mat, int n, int m, int target){
    int row = 0;
    int col = m-1;
    while(row < n && col >=0){
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) row++;
        else col--;
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