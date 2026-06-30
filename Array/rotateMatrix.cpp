#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

// brute force approch
// vector<vector<int>> rotateMatrix(vector<vector<int>> &mat, int n, int m){
//     vector<vector<int>> ans(n, vector<int>(m));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             ans[j][(n-1)-i] = mat[i][j];
//         }
//     }
//     return ans;
// }

// Optimal approch

void rotateMatrix(vector<vector<int>> & mat, int n, int m){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

 

int main(){
    int n;
    cout<<"Enter number of rows : ";
    cin>>n;
    int m;
    cout<<"Enter number of columns : ";
    cin>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout<<"Enter elements of an matrix : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    rotateMatrix(mat,n,m);
    // Print final matrix
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}