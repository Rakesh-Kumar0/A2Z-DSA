#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i-1] <= arr[i]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter element of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    bool result = isSorted(arr, n);
    if(result == true) cout<<"Array is sorted ";
    else cout<<"Array is not sorted ";
    return 0;

}