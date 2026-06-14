#include<iostream>
#include<map>

using namespace std;
void highestOccuringElement(int n, int arr[]){
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    for(auto it : mpp){
        int element = it.first;
        int count = it.second;

        if(count > maxFreq){
            maxFreq = count;
            maxEle = element;
        }

        if(count < minFreq){
            minFreq = count;
            minEle = element;
        }
    }
    cout<<"The highest frequency element is " << maxEle <<endl;
    cout<<"The lowest frequency element is " << minEle <<endl;
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array : " ;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    highestOccuringElement(n, arr);

    return 0;
}