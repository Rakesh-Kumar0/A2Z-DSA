#include<iostream>
#include<vector>
using namespace std;

// without use of lowerBound and upperBoud
int firstPosition(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1 ;
    }
    return first;
}

int lastPosition(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            last = mid;
            low  = mid + 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1 ;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int target){
    int first = firstPosition(arr, n, target);
    if(first == -1) return {-1, -1};
    int last = lastPosition(arr,n,target);
    return {first, last};
}
int count(vector<int> &arr, int n, int target){
    pair<int,int> ans = firstAndLastPosition(arr,n,target);
    if(ans.first == -1) return 0;
    return ans.second - ans.first +1;
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
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    int result = count(arr, n , x);
    cout<<result;
    return 0;
}