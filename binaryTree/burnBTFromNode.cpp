#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<unordered_map>
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

// function to find maximum time
int findMaxDistance(map<Node*, Node*> &mpp, Node* target){
    queue<Node*> q;
    q.push(target);
    map<Node* , int> visited;
    visited[target] = 1;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                flag = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                flag = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            if(mpp[node] && !visited[mpp[node]]){
                flag = 1;
                visited[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(flag) maxi++;
    }
    return maxi;
}

// function that will mark the parent or upward arrow
Node* bfsToMapParents(Node* root, map<Node*, Node*> &mpp , int start){
    queue<Node*> queue;
    queue.push(root);
    Node* res;
    while(!queue.empty()){
        Node* node = queue.front();
        if(node->data == start) res = node;
        queue.pop();
        if(node->left){
            mpp[node->left] = node;
            queue.push(node->left);
        }
        if(node->right){
            mpp[node->right] = node;
            queue.push(node->right);
        }
    }
    return res;
}

int timeToBureTree(Node* root, int start){
    map<Node* , Node*> mpp;
    Node* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

int main(){
    // creating the root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);
    int start = 1;
    int result = timeToBureTree(root, start);
    cout<<result;
    return 0;
}