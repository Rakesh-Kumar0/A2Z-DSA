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
int widthOfBinaryTree(Node* root){
    if(root == NULL) return 0;
    queue<pair<Node* , int>> q;
    int width = 0;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for(int i=0; i<size; i++){
            int cur_id = q.front().second-min;
            Node* node = q.front().first;
            q.pop();
            if(i == 0) first = cur_id;
            if(i == size-1) last = cur_id;
            if(node->left) q.push({node->left, cur_id*2+1});
            if(node->right) q.push({node->right, cur_id*2+2});

        }
        width = max(width, last-first+1);
    }
    return width;
}

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);
    Node* p = root->left;
    Node* q = root->right;
    int result = widthOfBinaryTree(root);
    cout<<result;
    return 0;
}