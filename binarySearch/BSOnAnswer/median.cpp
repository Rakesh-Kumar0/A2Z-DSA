#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

// brute force approch
double median(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> arr3;
    int i=0; 
    int j=0;
    // mrege two sorted arrays
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n1){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < n2){
        arr3.push_back(arr2[j]);
        j++;
    }
    int n = n1 + n2;
    if(n % 2 == 1){
        return arr3[n/2];
    }
    
    return (double)((double)arr3[n/2] + (double)arr3[n/2 - 1])/2.0;
    
}

int main(){
    int n1, n2;
    cout<<"Enter size of first array : ";
    cin>>n1;
    vector<int> arr1;
    cout<<"Enter elements of first array : ";
    for(int i=0; i<n1; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }

    cout<<"Enter size of second array : ";
    cin>>n2;
    vector<int> arr2;
    cout<<"Enter elements of second array : ";
    for(int i=0; i<n2; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }
    double result = median(arr1, arr2);
    cout<<result;
    return 0;
}