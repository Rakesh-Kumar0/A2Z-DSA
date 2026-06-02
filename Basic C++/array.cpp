#include<iostream>

using namespace std;

int main(){

    // datatype array_name[size]
    int arr[5];
    cout << "Enter elements of array " << endl ;
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    cout << "Elements of array are " << endl ;
    for(int i = 0; i < 5; i++){
        cout <<arr[i] << endl;
    }
    return 0;
}