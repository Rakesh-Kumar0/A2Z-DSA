#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// function of bfs traversal

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();

        // traverse in the neighbours and marked them if its a land
        for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

}

// function to find the number of island
int numIsland(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cnt = 0 ;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

int main(){
    int n,m;
    cout<<"Enter no. of rows and no. of columns : ";
    cin>>n >>m;
    vector<vector<char>> grid(n, vector<char>(m));
    cout<<"Enter the elements in '0' and '1' only : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    int result = numIsland(grid);
    cout<<result;
    return 0;
}


