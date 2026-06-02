#include<iostream>

using namespace std;

int main(){

    // WAP to take a day number and print corresponding day i.e. for 1 print monday and so on... 
    
    int dayNum;
    cout << "Enter the day number : " ;
    cin >> dayNum ;
    switch(dayNum){
        case 1:
        cout << "Monday" ;
        break;

        case 2:
        cout << "Tuesday" ;
        break;

        case 3:
        cout << "Wednesday" ;
        break;

        case 4:
        cout << "Thusday" ;
        break;

        case 5:
        cout << "Friday" ;
        break;

        case 6:
        cout << "Saturday" ;
        break;

        case 7:
        cout << "Sunday";
        break;

        default:
        cout << "enter valid daynumber ";
    }
    return 0;
}