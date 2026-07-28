#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force
bool searchElement(vector<vector<int>> &mat, int n, int m, int target){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == target) return true;
        }
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