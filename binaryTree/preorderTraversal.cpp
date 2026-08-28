#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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

void preorder(Node* root){
    if(root == NULL) return ;
    cout<< root->data <<" ";
    preorder(root->left);
    preorder(root->right);
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
    preorder(root);
    return 0;
}