#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestSubArrayWithSum0(vector<int> &arr, int n){
    map<int , int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum +=arr[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
    }
    return maxi;

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
    int result = longestSubArrayWithSum0(arr, n);
    cout<<result;
    return 0;
}