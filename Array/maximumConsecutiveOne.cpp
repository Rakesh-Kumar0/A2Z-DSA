#include<iostream>
#include<vector>
using namespace std;

int maxConsecutiveOne(vector<int> &arr, int n){
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            cnt +=1;
            maxi = max(maxi, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array in 0 and 1 only : ";
    for(int i=0; i<n; i++){
        int temp; 
        cin>>temp;
        arr.push_back(temp);
    }

    int result = maxConsecutiveOne(arr, n);
    cout<<"Maximum number of consecutive one is " <<result;
    return 0;
}