#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> & mat){
    int n = mat.size();
    int m = mat[0].size();
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    vector<int> ans;
    while(top <= bottom && left <= right){
        for(int j=left;j<=right; j++){
            ans.push_back(mat[top][j]);
        }
        top++;
        for(int i=top; i<=bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        // if we have only one row
        if(top <= bottom){
            for(int j=right; j>=left; j--){
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
        } 
        
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;

}

 

int main(){
    int n;
    cout<<"Enter number of rows : ";
    cin>>n;
    int m;
    cout<<"Enter number of columns : ";
    cin>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout<<"Enter elements of an matrix : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    vector<int> result = spiralTraversal(mat);
    // Print final matrix
    for (auto it : result) {
       cout<<it <<" ";
    }

    return 0;
}