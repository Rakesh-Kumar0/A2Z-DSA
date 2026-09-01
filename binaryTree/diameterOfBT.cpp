#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
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

// brute force
int getHeight(Node* root){
    if(root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return 1 + max(lh, rh);
}

int findMax(Node* root){
    if(root == NULL) return 0;
    int maxi = INT_MIN;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    maxi = max(maxi, leftHeight + rightHeight);
    findMax(root->left);
    findMax(root->right);
    return maxi;
}

// optimal approch

// int dfsHeight(Node* root){
//     if(root == NULL) return 0;
//     int lh = dfsHeight(root->left);
//     if(lh == -1) return -1;
//     int rh = dfsHeight(root->right);
//     if(rh == -1) return -1;
//     if(abs(lh-rh) > 1) return -1;
//     return max(lh, rh) + 1;
// }
// bool checkBalance(Node* root){
//     return dfsHeight(root) != -1;
// }

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int result = findMax(root);
    cout<<result;
    
    return 0;
}