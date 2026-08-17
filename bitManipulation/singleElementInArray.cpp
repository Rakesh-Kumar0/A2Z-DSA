#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singleElement(vector<int> &arr){
    int xorr = 0;
    for(int i=0; i<arr.size(); i++){
        xorr = xorr^arr[i];
    }
    return xorr;
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
    int result = singleElement(arr);
    cout<<result;
    return 0;
}