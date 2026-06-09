#include<iostream> 
#include<cmath>
using namespace std;

bool armstrong(int num){
    int dupl = num;
    int sumOfCube = 0;
    int n = to_string(num).length(); // n is  umber of digits
    while(num > 0){
        int lastDigit = num % 10 ;
        num = num / 10 ;
        sumOfCube = sumOfCube + pow(lastDigit, n);
    }
    if(dupl == sumOfCube) return true ;
    else return false ;
}

int main(){

    int t;
    cout << "Enter number of testcases : ";
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin >> num ;
        if(armstrong(num)) cout<<num <<" is armstrong " << endl;
        else cout<<num <<" is not armstrong " <<endl;
    }
    return 0 ;
}