/*
    To print the Nth row of the pascal triangle we can take advantage of the relationship between Nth element 
    and binomial coefficients.

    In a pascal's triangle, the Nth row contains the binomial coefficients C(N-1, 0), C(N-1, 1) and so on t
    ill C(N-1, N-1). Thus we can simply calculate all these values to return the Nth row of pascal triangle.

    Instead of computing full factorials, we can start with the first value as 1, 
    and use the relation C(n, k) = C(n, k−1) × (n−k+1) / k to compute the next value from the p
    revious one in constant time.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to generate the Nth row of Pascal's Triangle
vector<long long> getNthRow(int n){
    // Result vector to store the row
    vector<long long> row;
    // First value of the row is always 1
    long long val = 1;
    row.push_back(val);
        
    // Compute remaining values using the relation:
    // C(n, k) = C(n, k-1) * (n-k) / k
        for (int k = 1; k < n; k++) {
            val = val * (n - k) / k;
            row.push_back(val);
        }
        
        return row;
}

int main(){
    int n;
    cout<<"Enter number of rows : ";
    cin>>n;
    vector<long long> result = getNthRow(n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}