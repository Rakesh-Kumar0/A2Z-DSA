#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;


// Function to count the minimum number of student required
int countStudents(vector<int> &arr, int pages){
    int student = 1;
    int pagesStudent = 0;
    for(int i=0; i<arr.size(); i++){
        if((pagesStudent + arr[i]) <= pages){
            pagesStudent += arr[i];
        }
        else{
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

// brute force approch
// Function to find the minimum possible maximum pages.
int findPages(vector<int> &arr, int n, int student){
    // If students are more than books, allocation is impossible.
    if(student > n) return -1;
    // Minimum possible answer is the largest book.
    int low = *max_element(arr.begin(), arr.end());

    // Maximum possible answer is the sum of all pages.
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i=low; i<=high; i++){
        int cntStu = countStudents(arr, i);
        if(cntStu == student) return i;
    }
    return -1;
}


// binary search

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
    int student ;
    cout<<"Enter the numbers of student : ";
    cin>>student;
    int result =findPages(arr, n, student);
    cout<<result;
    return 0;
}