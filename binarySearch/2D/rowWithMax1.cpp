#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force
int rowWithMax1s(vector<vector<int>> &mat, int n, int m){
    int maxCnt = -1;
    int index = -1;
    for(int i=0; i<n; i++){
        int cntOnes = 0;
        for(int j=0; j<m; j++){
            cntOnes +=mat[i][j];
        }
        if(cntOnes > maxCnt){
            maxCnt = cntOnes;
            index = i;
        }
    }
    return index;
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
    int result = rowWithMax1s(mat, n, m);
    cout<<result;
    return 0;
}