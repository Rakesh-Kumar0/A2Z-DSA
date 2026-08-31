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
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
        ans.push_back(node->data);
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