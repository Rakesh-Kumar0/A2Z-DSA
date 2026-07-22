#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;


// Function to count the minimum number of painter required
int countPainter(vector<int> &arr, int time){
    int painter = 1;
    int boardsPainter = 0;
    for(int i=0; i<arr.size(); i++){
        if((boardsPainter + arr[i]) <= time){
            boardsPainter += arr[i];
        }
        else{
            painter++;
            boardsPainter = arr[i];
        }
    }
    return painter;
}

// brute force approch
// Function to find the minimum time to paint all boards using at most k painters
int findtime(vector<int> &arr, int n, int painter){
    // If students are more than books, allocation is impossible.
    if(painter > n) return -1;
    // Minimum possible answer is the largest book.
    int low = *max_element(arr.begin(), arr.end());

    // Maximum possible answer is the sum of all pages.
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i=low; i<=high; i++){
        int cntPainter = countPainter(arr, i);
        if(cntPainter == painter) return i;
    }
    return -1;
}


// binary search
// int findPages(vector<int> &arr, int n, int student){
//    int low = *max_element(arr.begin(), arr.end());
//    int high = accumulate(arr.begin(), arr.end(), 0);
//    while(low <= high){
//     int mid = low +(high - low)/2;
//     int cntStu = countStudents(arr, mid);
//     if(cntStu > student) low = mid + 1;
//     else high = mid - 1;
//    }
//    return low;
// }

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
    int painter ;
    cout<<"Enter the numbers of partition : ";
    cin>>painter;
    int result =findtime(arr, n, painter);
    cout<<result;
    return 0;
}