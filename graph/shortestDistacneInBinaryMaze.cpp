#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int,int> &src, pair<int,int> &dest){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>> q;
    dist[src.first][src.second] = 0;
    q.push({0,{src.first, src.second}});
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && dis+1 < dist[nrow][ncol]){
                if(nrow == dest.first && ncol == dest.second) return dis + 1;
                dist[nrow][ncol] = dis+1;
                q.push({dis + 1,{nrow,ncol}});
            }
        }
    }
    return -1;
}
int main(){
    int n,m;
    cout<<"Enter no. of rows and no. of columns : ";
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    cout<<"Enter elements in only '0' and '1' : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    pair<int,int> src, dest ;
    cout<<"Enter source : ";
    cin>>src.first>>src.second;
    cout<<"Enter destination : ";
    cin>>dest.first>>dest.second;
    int result = shortestPath(grid, src,dest);
    cout<<result;
    return 0;
}