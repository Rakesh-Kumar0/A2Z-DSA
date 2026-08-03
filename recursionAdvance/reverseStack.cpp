#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val){
    // If stack is empty, push the value
    if(st.empty()){
        st.push(val);
        return ;
    }

    // pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack
    insertAtBottom(st, val);

    // Push the popped element back
    st.push(topVal);
}

// Function to reverse the stack
void reverseStack(stack<int> &st){
    // Base case: If stack is empty, return
    if(st.empty()) return ;
    // pop the top element
    int topVal = st.top();
    st.pop();

    //recursively reverse the remaining elements
    reverseStack(st);
    // Insert the popped element at the bottom
    insertAtBottom(st, topVal);
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
    reverseStack(st);
    cout<<"reverse   stack : ";
    while(!st.empty()){
        cout<<st.top() <<" ";
        st.pop();
    }
    return 0;

}