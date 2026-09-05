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

int maxPathDown(Node* root, int &maxi){
    if(root == NULL) return 0;
    int leftSum = max(0,maxPathDown(root->left, maxi));
    int rightSum = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, leftSum + rightSum + root->data);
    return (root->data + max(leftSum, rightSum));
}
int maxPathSum(Node* root){
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
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
    int result = maxPathSum(root);
    cout<<result;
    
    return 0;
}