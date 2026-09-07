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

vector<int> topView(Node* root){
    vector<int> ans;
    queue<pair<Node*, int>> q;
    map<int, int> mpp;
    if(root == NULL) return ans;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left != NULL){
            q.push({node->left, line-1});
        }
        if(node->right != NULL){
            q.push({node->right, line+1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;

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
    vector<int> result = topView(root);
    for(auto it : result){
        cout<<it<<" ";
    }
    
    return 0;
}