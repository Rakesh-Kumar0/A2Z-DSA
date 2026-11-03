#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function to find minimum time to rot all orange
int rottenOrange(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>,int>> q;
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int time = 0;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    // check if fresh orange are rotten or not
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 2 && mat[i][j] == 1){
                return -1;
            }
        }
    }
    return time;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    int result = rottenOrange(mat);
    cout<<result<<"";
    return 0;
}