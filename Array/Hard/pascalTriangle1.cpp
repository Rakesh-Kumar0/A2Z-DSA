/*
    To find the element at the coordinates (R,C) where R is the row number and C is the Column number, 
    we can simply simulate the generation of pascal's triangle for R rows. In Pascal’s Triangle, 
    the element at row R and column C corresponds to the binomial coefficient (r-1)C(c-1). 
    To calculate this binomial coefficient, we can simply apply the formula of binomial coefficient 
    i.e. (r-1)!/(c-1)!(r-c)!.

    Instead of computing full factorials (which can overflow and be slow), 
    we can multiply and divide in a loop to compute the coefficient efficiently.

*/

#include<iostream>
#include<vector>
using namespace std;

// function to compute binomial coffecient(nCr)
long long findPascalElement(int rowNo, int colNo){
    // element is C(rowNo-1, colNo-1)
    int n = rowNo -1;
    int r = colNo - 1;
    long long result = 1;
    // Compute C(n, k) using iterative formula
    for(int i=0; i<r; i++){
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;

}

int main(){
    int rowNo;
    int colNo;
    cout<<"Enter row number and colume number : ";
    cin>>rowNo >>colNo;

    long long result = findPascalElement(rowNo, colNo);
    cout<<result;
    return 0;
}