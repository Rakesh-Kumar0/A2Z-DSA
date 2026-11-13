#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

int shortestPath(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    dist[0][0] = 0;
    pq.push({0,{0,0}});
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        // to return ans without empty pq
        if(row == n-1 && col == m-1) return diff;
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newEffort = max(abs(grid[row][col] - grid[nrow][ncol]),diff);
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                }
            }
        }
    }
    return 0;
}
int main(){
    int n,m;
    cout<<"Enter no. of rows and no. of columns : ";
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    cout<<"Enter elements of grid : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    int result = shortestPath(grid);
    cout<<result;
    return 0;
}