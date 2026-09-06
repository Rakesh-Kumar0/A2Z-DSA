#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<climits>
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

bool isLeaf(Node* root){
    return root->left == NULL && root->right == NULL;
}

void addLeftBoundary(Node* root, vector<int> &res){
    Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(Node* root, vector<int> &res){
    vector<int> temp;
    Node* cur = root->right;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=temp.size()-1; i>=0; i--){
        res.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(Node* root){
    vector<int> res;
    if(root == NULL) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
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
    vector<int> result = printBoundary(root);
    for(auto it : result){
        cout<<it<<" ";
    }  
    
    return 0;
}