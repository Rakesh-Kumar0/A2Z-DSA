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

bool isSameTree(Node* root1, Node* root2){
    if(root1 == NULL || root2 == NULL) return (root1 == root2);
    return (root1->data == root2->data) && (isSameTree(root1->left, root2->left)) && (isSameTree(root1->right, root2->right));
}


int main(){
    // creating the root node of first tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    // creating the root node of second tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    bool result = isSameTree(root1, root2);
    cout<<result;
    
    return 0;
}