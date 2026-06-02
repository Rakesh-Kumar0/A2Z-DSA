#include<iostream>

using namespace std;

int main(){
    string name = "Rakesh";
    cout << name[3] << endl ;
    int len = name.size();
    cout << name[len - 1] << endl ;
    name[3] = 't';
    cout << name[3];
    return 0;
}