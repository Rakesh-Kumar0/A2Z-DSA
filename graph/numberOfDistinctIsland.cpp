#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;

// function of dfs traversal
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &vec, int row0, int col0){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    vec.push_back({row-row0, col-col0});
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    for(int i=0; i<4; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
    }
    
    

}

// function to find the number of island
int countDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main(){
    int n,m;
    cout<<"Enter no. of rows and no. of columns : ";
    cin>>n >>m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout<<"Enter the elements in '0' and '1' only : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    int result = countDistinctIslands(grid);
    cout<<result;
    return 0;
}


