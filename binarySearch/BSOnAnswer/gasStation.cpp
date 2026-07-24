#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
using namespace std;

// brute force approch
// long double minimizeMaxDistanc(vector<int> &arr, int k){
//     int n = arr.size();
//     vector<int> howMany(n-1 , 0);
//     for(int gasStations=1; gasStations<=k; gasStations++){
//         long double maxSection = -1;
//         int maxInd = -1;
//         for(int i=0; i<n-1; i++){
//             long double diff = (arr[i+1] - arr[i]);
//             long double sectionLength = diff / (long double)(howMany[i] + 1);
//             if(sectionLength > maxSection){
//                 maxSection = sectionLength;
//                 maxInd = i;

//             }
//         }
//         howMany[maxInd]++;
//     }
//     long double maxAns = -1;
//     for(int i=0; i<n-1; i++){
//         long double diff = (arr[i+1] - arr[i]);
//         long double sectionLength = diff / (long double)(howMany[i] + 1);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }



// better approch
// long double minimizeMaxDistanc(vector<int> &arr, int k){
//     int n = arr.size();
//     vector<int> howMany(n-1 , 0);
//     priority_queue<pair<long double, int>> pq;
//     for(int i=0; i<n-1; i++){
//         pq.push({arr[i+1] - arr[i], i});
//     }
//     for(int gasStations=1; gasStations<=k; gasStations++){
//         auto tp = pq.top();
//         pq.pop();
//         int sectionInd = tp.second;
//         howMany[sectionInd]++;
//         long double iniDiff = arr[sectionInd + 1] - arr[sectionInd];
//         long double  newSecLen = iniDiff / (long double)(howMany[sectionInd] +1);
//         pq.push({newSecLen, sectionInd});
//     }
    
//     return pq.top().first;
//}

// binary search
int noOfGasStationsRequired(vector<int> &arr, long double dist){
    int cnt = 0;
    for(int i=1; i<arr.size(); i++){
        int numberInBetween = ((arr[i] - arr[i-1])/dist);
        if((arr[i] - arr[i-1])/dist == numberInBetween*dist){
            numberInBetween--;
        }
        cnt +=numberInBetween;
    }
    return cnt;
}

long double minimizeMaxDistanc(vector<int> &arr, int k){
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for(int i=0; i<n-1; i++){
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high)/(2.0);
        int count = noOfGasStationsRequired(arr, mid);
        if(count>k){
            low = mid;
        }
        else high = mid;
    }
    return high;
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
    int k ;
    cout<<"Enter the numbers of new gasstation to be placed : ";
    cin>>k;
    int result =minimizeMaxDistanc(arr, k);
    cout<<result;
    return 0;
}