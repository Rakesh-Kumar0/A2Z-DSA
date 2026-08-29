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

void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
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
    inorder(root);
    return 0;
}