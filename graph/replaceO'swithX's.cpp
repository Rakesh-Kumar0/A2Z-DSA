#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function for dfs treversal

void dfs(int row, int col, vector<vector<char>> &vis, vector<vector<char>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = '1';
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0, +1, 0, -1};
    for(int i=0; i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
            dfs(nrow, ncol, vis, grid);
        }
    }
}

vector<vector<char>> fill(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> vis(n, vector<char>(m));

    // traverse first row and last row
    for(int j=0; j<m; j++){
        // first row
        if(!vis[0][j] && grid[0][j] == 'O'){
            dfs(0,j,vis,grid);
        }

        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 'O'){
            dfs(n-1, j, vis, grid);
        }
    }

    // traverse first col and last col
    for(int i=0; i<n; i++){
        // first col
        if(!vis[i][0] && grid[i][0] == 'O'){
            dfs(i,0,vis,grid);
        }
        // last col
        if(!vis[i][m-1] && grid[i][m-1] == 'O'){
            dfs(i, m-1, vis, grid);
        }
    }

    // change remaining O's with X's
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
    return grid;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    cout<<"Enter elements of grid in O's and X's : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<char>> result = fill(grid);
    for(auto rows : result){
        for(auto it : rows){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}