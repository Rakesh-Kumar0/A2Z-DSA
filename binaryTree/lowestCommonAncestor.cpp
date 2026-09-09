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
Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    // base case
    if(root == NULL || root == p || root == q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    // result

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else{
        return root; // if both left and right are not null that is my answer
    }
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
    Node* p = root->left;
    Node* q = root->right;
    Node* result = lowestCommonAncestor(root, p, q);
    cout<<result->data;
    return 0;
}