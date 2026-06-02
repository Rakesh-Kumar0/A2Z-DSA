#include<iostream>

using namespace std;

int main(){

    int arr[3][5];
    cout << "Enter elements of an array " << endl ;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Elements of an array are " << endl ;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }
    return 0;
}