#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

// brute force approch
int smallestDivisor(vector<int> &arr, int threshold){
    int maxi = *max_element(arr.begin(), arr.end());
    for(int div=1; div<=maxi; div++){
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = sum + ceil((double)arr[i]/(double)div);
        }
        if(sum <= threshold) return div;
    }
    return -1;
}


int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){

        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int threshold ;
    cout<<"Enter threshold value : ";
    cin>>threshold;
    int result = smallestDivisor(arr, threshold);
    cout<<result;
    return 0;
}