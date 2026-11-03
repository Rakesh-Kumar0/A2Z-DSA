#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function of dfs traversal
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &mat, int newColor, int delrow[], int delcol[], int iniColor){
   ans[row][col] = newColor;
   int n = mat.size();
   int m = mat[0].size();
   for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
            dfs(nrow, ncol, ans, mat, newColor, delrow, delcol, iniColor);
        }
   }

}

vector<vector<int>> floodFill(vector<vector<int>> &mat, int sr, int sc, int newColor){
    vector<vector<int>> ans = mat;
    int iniColor = mat[sr][sc];
    //the starting pixel already has the newColor
    if(iniColor == newColor) return ans;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    dfs(sr,sc, ans, mat, newColor,delrow, delcol, iniColor);
    return ans;
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
    int sr, sc;
    cin>>sr>>sc;
    int newColor = mat[sr][sc] +1;
    vector<vector<int>> result = floodFill(mat, sr, sc, newColor);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}