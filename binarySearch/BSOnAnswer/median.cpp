#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

// brute force approch
// double median(vector<int> &arr1, vector<int> &arr2){
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     vector<int> arr3;
//     int i=0; 
//     int j=0;
//     // mrege two sorted arrays
//     while(i < n1 && j < n2){
//         if(arr1[i] < arr2[j]){
//             arr3.push_back(arr1[i]);
//             i++;
//         }
//         else{
//             arr3.push_back(arr2[j]);
//             j++;
//         }
//     }
//     while(i < n1){
//         arr3.push_back(arr1[i]);
//         i++;
//     }
//     while(j < n2){
//         arr3.push_back(arr2[j]);
//         j++;
//     }
//     int n = n1 + n2;
//     if(n % 2 == 1){
//         return arr3[n/2];
//     }
    
//     return (double)((double)arr3[n/2] + (double)arr3[n/2 - 1])/2.0;
    
// }


// optimal approch
double median(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int i=0; 
    int j=0;
    int ind2 = n/2;
    int ind1 = ind2 -1;
    int cnt = 0;
    int ind1ele = -1;
    int ind2ele = -1;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == ind1) ind1ele = arr1[i];
            if(cnt == ind2) ind2ele = arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) ind1ele = arr2[j];
            if(cnt == ind2) ind2ele = arr2[j];
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == ind1) ind1ele = arr1[i];
        if(cnt == ind2) ind2ele = arr1[i];
        cnt++;
        i++;
    }
    while(j < n2){
        if(cnt == ind1) ind1ele = arr2[j];
        if(cnt == ind2) ind2ele = arr2[j];
        cnt++;
        j++;
    }
    
    if(n % 2 == 1){
        return ind2ele;
    }
    
    return (double)((double)ind1ele + (double)ind2ele)/2.0;
    
}

int main(){
    int n1, n2;
    cout<<"Enter size of first array : ";
    cin>>n1;
    vector<int> arr1;
    cout<<"Enter elements of first array : ";
    for(int i=0; i<n1; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }

    cout<<"Enter size of second array : ";
    cin>>n2;
    vector<int> arr2;
    cout<<"Enter elements of second array : ";
    for(int i=0; i<n2; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }
    double result = median(arr1, arr2);
    cout<<result;
    return 0;
}