
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& matrix, int distanceThreshold){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9){
                    matrix[i][j] = min( matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    int cntCity = n+1;
    int cityNo = -1; // initial no city is consider

    for(int city=0; city<n; city++){
        int cnt = 0; // it count the city which is reachable under threshold
        for(int adjCity=0; adjCity<n; adjCity++){
            if(matrix[city][adjCity] <= distanceThreshold){
                cnt++;
            }
        }
        if(cnt <= cntCity){
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
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
        matrix[v][u] = min(matrix[v][u], wt);
    }

    int distanceThreshold;
    cout<<"Enter threshold distance : ";
    cin>>distanceThreshold;
    int result = findCity(n,m,matrix,distanceThreshold);
    cout<<result;
    return 0;
}
