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

bool isSymmetricHelp(Node* left, Node* right){
    if(left == NULL || right == NULL) return left == right;
    if(left->data != right->data) return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(Node* root){
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    bool result = isSymmetric(root);
    cout<<result;
    return 0;
}