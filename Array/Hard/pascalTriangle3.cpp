/* 
    To generate the entire Pascal’s Triangle for the first N rows, we can start with the first row c
    ontaining a single 1 and iteratively build each subsequent row using the property that every 
    element (except the first and last) is the sum of the two elements directly above it from 
    the previous row. The first and last elements of each row are always 1. By storing the previous row, 
    we can calculate the next row easily. This process continues until we have constructed all N rows, 
    resulting in the complete Pascal’s Triangle structure.

*/

#include <iostream>
#include<vector>
using namespace std;

// Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        // Result vector to hold all rows
        vector<vector<int>> triangle;

        // Loop for each row
        for (int i = 0; i < numRows; i++) {
            // Create a row with size (i+1) and initialize all elements to 1
            vector<int> row(i + 1, 1);

            // Fill elements from index 1 to i-1 (middle values)
            for (int j = 1; j < i; j++) {
                // Each element = sum of two elements above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add current row to the triangle
            triangle.push_back(row);
        }
        return triangle;
    }


    


int main() {
    int n;
    cout<<"enter number of row : ";
    cin>>n;
    vector<vector<int>> result = generate(n);
    for (auto &row : result) {
        for (auto &val : row) cout << val << " ";
        cout << endl;
    }
}
