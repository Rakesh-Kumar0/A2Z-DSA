#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// Function to insert element in sorted order
void insert(stack<int> &st, int temp){
    // Base case: if the stack is empty or temp is larger than the top element
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    // Otherwise, pop the top element and recursively insert
    int val = st.top();
    st.pop();
    insert(st, temp);
    // Push the popped element back
    st.push(val);
}

// Function to sort the stack
void sortStack(stack<int> &st){
    if(!st.empty()) {
        int temp = st.top();
        st.pop();
        sortStack(st);
        insert(st, temp);
    }
}
int main(){
    stack<int> st;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter elements in stack : ";
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        st.push(value);
    }
    sortStack(st);
    cout<<"sorted  stack : ";
    while(!st.empty()){
        cout<<st.top() <<" ";
        st.pop();
    }
    return 0;

}