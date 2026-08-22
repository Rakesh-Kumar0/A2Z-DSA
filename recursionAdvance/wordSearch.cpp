#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

// DFS function to search for the word
bool dfs(vector<vector<char>> &grid, string word, int i, int j, int idx){
    // If all characters matched, return true
    if(idx == word.size()) return true;
    // check boundaries and character match
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != word[idx]) {
        return false;
    }
    // Store current character and mark as visited
    char temp = grid[i][j];
    grid[i][j] = '#';

    // Explore all four directions
    bool found = dfs(grid, word, i + 1, j, idx + 1) || 
                 dfs(grid, word, i - 1, j, idx + 1) ||
                 dfs(grid, word, i, j + 1, idx + 1) ||
                 dfs(grid, word, i, j - 1, idx + 1);

    // Restore the character (backtracking)
    grid[i][j] = temp;

    return found;

}

// Function to check if the word exists in the board
bool exist(vector<vector<char>> &grid, string word){
    int rows = grid.size();
    int cols = grid[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            // Start DFS if first letter matches
            if(dfs(grid, word, i, j, 0)) return true;
        }
    }
    // If no path found, return false
    return false;
}


int main(){
    int n, m;
    cout<<"Enter no. of rows : ";
    cin>>n;
    cout<<"Enter no. of column : ";
    cin>>m;
    vector<vector<char>> grid(n, vector<char> (m));
    cout<<"Enter elements of grid : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    string word;
    cout<<"Enter word : ";
    cin>>word;
    bool result = exist(grid, word);
    cout<<result;
    return 0;
}