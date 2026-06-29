#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

// brute force approch

void setMatrixZeroes(vector<vector<int>> & mat, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (mat[i][j] == 0) {
                // Mark all elements in this row as -1 (except existing zeros)
                for (int col = 0; col < m; col++) {
                    if (mat[i][col] != 0)
                      mat[i][col] = -1;
                }

                // Mark all elements in this column as -1 (except existing zeros)
                for (int row = 0; row < n; row++) {
                    if (mat[row][j] != 0)
                        mat[row][j] = -1;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
}

// better approch


// Optimal approch
 

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
    setMatrixZeroes(mat,n,m);
    // Print final matrix
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}