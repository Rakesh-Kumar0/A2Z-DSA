#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// btute force

// void secondLargestElement(vector<int> &arr, int n){
//     sort(arr.begin(), arr.end());
//     int largestElement = arr[n-1];
//     int secondLargestElement = INT_MIN;
//     for(int i=n-2; i>=0; i--){
//          if(arr[i] != largestElement){
//             secondLargestElement = arr[i];
//             break;
//          }
//     }
//     cout<<"SecondLargestElement is " <<secondLargestElement;
     
// }

// better approch

// void secondLargestElement(vector<int> &arr, int n){
//     int largestElement = arr[0];
//     for(int i=0; i<n; i++){
//         if(arr[i] > largestElement){
//             largestElement = arr[i];
//         }
//     }
//     int secondLargestElement = INT_MIN;
//     for(int i=0; i<n; i++){
//         if(arr[i] > secondLargestElement && arr[i] != largestElement){
//             secondLargestElement = arr[i];
//         }
//     }
//     cout<<"Second largest element is " << secondLargestElement;
// }


// optimal approch

void secondLargestElement(vector<int> &arr, int n){
    int largestElement  = arr[0];
    int secondLargestElement = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > largestElement){
            secondLargestElement = largestElement;
            largestElement = arr[i];
       }
       else if(arr[i] < largestElement && arr[i] > secondLargestElement){
        secondLargestElement = arr[i];
       }
    }
    cout<<"Second largest element is " << secondLargestElement;
}


int main(){

    int n;
    cout<< "Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    secondLargestElement(arr, n);
    return 0;
}