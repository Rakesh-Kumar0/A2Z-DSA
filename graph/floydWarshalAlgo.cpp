
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void floydWarshall(vector<vector<int>>& matrix, int n){
    // Try every vertex as an intermediate vertex
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9){
                    matrix[i][j] = min( matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // if final matrix still have 1e9 that means that is not rechable
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1e9)
            matrix[i][j] =  -1;
        }
    }

    // Negative cycle detection
    for(int i=0; i<n; i++){
        if(matrix[i][i] < 0){
            cout<<"\nNegative cycle detected!";
            return;
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges: ";
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(n,1e9));
    // Distance from a vertex to itself is zero
    for(int i=0; i<n; i++){
        matrix[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        matrix[u][v] = min(matrix[u][v],wt);
    }

    floydWarshall(matrix,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
