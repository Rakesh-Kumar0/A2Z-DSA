#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

//function to find path
void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
    // base case
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }
    // doenward
    if(i+1<n && !vis[i+1][j] && mat[i+1][j] == 1){
        vis[i][j] = 1;
        solve(i+1, j, mat, n, ans, move +'D', vis);
        vis[i][j] = 0;
    }

    // left
    if(j-1>=0 && !vis[i][j-1] && mat[i][j-1] == 1){
        vis[i][j] = 1;
        solve(i, j-1, mat, n, ans, move +'L', vis);
        vis[i][j] = 0;
    }

    // right
    if(j+1<n && !vis[i][j+1] && mat[i][j+1] == 1){
        vis[i][j] = 1;
        solve(i, j+1, mat, n, ans, move +'R', vis);
        vis[i][j] = 0;
    }

    // upward
    if(i-1>=0 && !vis[i-1][j] && mat[i-1][j] == 1){
        vis[i][j] = 1;
        solve(i-1, j, mat, n, ans, move +'U', vis);
        vis[i][j] = 0;
    }
}

// main function
vector<string> findPath(vector<vector<int>> &mat, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int> (n, 0));
    if(mat[0][0] == 1) solve(0, 0, mat, n, ans, "", vis);
    return ans;
}

int main(){
    int n;
    cout<<"Enter no. of rows or column : ";
    cin>>n;
    vector<vector<int>> mat(n, vector<int> (n));
    cout<<"Enter elements of in 0 & 1 only : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    
    vector<string> result = findPath(mat, n);
    for(auto it : result){
        cout<<it;
    }
    return 0;
}