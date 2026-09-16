#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
#include<stack>
#include<set>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

int findHeightLeft(Node* node){
    int hght = 0;
    while(node){
        hght++;
        node->left;
    }
    return hght;
}

int findHeightRight(Node* node){
    int hght = 0;
    while(node){
        hght++;
        node->right;
    }
    return hght;
}
// function to count node
int countNodes(Node* root){
    if(root == NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh) return (1<<lh) -1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    int result = countNodes(root);
    cout<<result;
    return 0;
}