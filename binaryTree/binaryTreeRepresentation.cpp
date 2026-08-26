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

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Root : "<<root->data <<endl;
    cout<<"Left child : "<<root->left->data<<endl;
    cout<<"Right child : "<<root->right->data<<endl;
    return 0;
}