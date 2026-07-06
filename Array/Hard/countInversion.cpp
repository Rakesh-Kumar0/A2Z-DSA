#include<iostream>
#include<vector>
using namespace std;

//brute force approch
// int countInversion(vector<int> &arr, int n){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// optimal approch

int cnt = 0;
void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            // right is smaller
            else{
                temp.push_back(arr[right]);
                cnt += (mid -left +1);
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

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

int countInversion(vector<int> &arr, int n){
    mergeSort(arr, 0, n-1);
    return cnt;
}
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
    int result = countInversion(arr, n);
    cout<<result;

    return 0;
}