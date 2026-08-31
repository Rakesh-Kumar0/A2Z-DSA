#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> iterativePreorderTraversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    if(root == NULL) return ans;
    Node* cur = root;
    while(cur != NULL || !st.empty()){
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else cur = temp;
        }
    }
    return ans;
}

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = iterativePreorderTraversal(root);
    
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}