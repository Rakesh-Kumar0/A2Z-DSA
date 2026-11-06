#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    queue<pair<int,int>> q;
    // first way
    // traverse the first row and last row
    // for(int j=0; j<m; j++){
    //     // first row
    //     if(grid[0][j] == 1){
    //         q.push({0,j});
    //         vis[0][j] = 1;
    //     }

    //     // last row
    //     if(grid[n-1][j] == 1){
    //         q.push({n-1,j});
    //         vis[n-1][j] = 1;
    //     }
    // }

    // // traverse the first col and last col
    // for(int i=0; i<n; i++){
    //     // for first col
    //     if(grid[i][0] == 1){
    //         q.push({i,0});
    //         vis[i][0] = 1;
    //     }
    //     // last col
    //     if(grid[i][m-1] == 1){
    //         q.push({i,m-1});
    //         vis[i][m-1] = 1;
    //     }
    // }

    // second way
    // traverse the first row last row first col and last col
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] == 1;
                }
            }
        }
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,+1,0,-1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int cnt = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout<<"Enter elements of grid in '0' and '1' : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    int result  = numberOfEnclaves(grid);
    cout<<result;
    return 0;
}