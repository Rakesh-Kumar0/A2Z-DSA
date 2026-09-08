#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
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

void recursion(Node* root, int level, vector<int> &res){
    if(root == NULL) return ;
    if(level == res.size()) res.push_back(root->data);
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res);
}

vector<int> rightView(Node* root){
    vector<int> res;
    recursion(root, 0, res);
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
    vector<int> result = rightView(root);
    for(auto it : result){
        cout<<it<<" ";
    }
    
    return 0;
}