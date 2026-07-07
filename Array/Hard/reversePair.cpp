#include<iostream>
#include<vector>
using namespace std;

//brute force approch
// int reversePair(vector<int> &arr, int n){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > 2 * arr[j]){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }


// optimal approch
void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            // right is smaller
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    int countPair(vector<int> &arr, int low , int mid, int high){
        int cnt = 0;
        int right = mid + 1;
        for(int i=low; i<=mid; i++){
            while(right<= high && arr[i] > 2 * arr[right]){
                right++;
            }
            cnt = cnt + (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt = cnt + countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }

int reversePair(vector<int> &arr, int n){
    return  mergeSort(arr, 0, n-1);}


int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an ayyar : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int result = reversePair(arr, n);
    cout<<result;

    return 0;
}