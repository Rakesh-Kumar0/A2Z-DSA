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
bool getPath(Node* root, vector<int> &res, int x){
    if(root == NULL) return false;
    res.push_back(root->data);
    if(root->data == x) return true;
    if(getPath(root->left, res, x) || getPath(root->right, res, x)) return true;
    res.pop_back();
    return false;
}

vector<int> path(Node* root, int x){
    vector<int> res;
    if(root == NULL) return res;
    getPath(root, res, x);
    return res;

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
    int node;
    cout<<"Enter node : ";
    cin>>node;
    vector<int> result = path(root, node);
    for(auto it : result){
        cout<<it<<" ";
    }
    
    return 0;
}