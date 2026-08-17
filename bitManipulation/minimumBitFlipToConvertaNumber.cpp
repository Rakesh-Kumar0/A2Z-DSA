#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minimumBitFlip(int start, int goal){
    // Variable to store bits that are different in both numbers 
    int num = start ^ goal;
    int count = 0;
    for(int i=0; i<31; i++){
        /* Update count if the rightmost bit is set */
        count += (num & 1);
        /* Shift the number every time by 1 place */
        num = num >> 1;
    }
    return count;
}

int main(){
    int start, goal;
    cout<<"Enter start value : ";
    cin>>start;
    cout<<"Enter goal value : ";
    cin>>goal;
    int result = minimumBitFlip(start, goal);
    cout<<result;

    return 0;
}