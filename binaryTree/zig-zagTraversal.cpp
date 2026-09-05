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

vector<vector<int>> zigzagLevelOrder(Node* root){
    vector<vector<int>> result;
    queue<Node*> nodesQuequ;
    bool leftToRight = true;
    if(root == NULL){
        return result;
    }
    nodesQuequ.push(root);
    while(!nodesQuequ.empty()){
        int size = nodesQuequ.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            Node* node = nodesQuequ.front();
            nodesQuequ.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = node->data;
            if(node->left){
                nodesQuequ.push(node->left);
            }

            if(node->right){
                nodesQuequ.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
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
    vector<vector<int>> result = zigzagLevelOrder(root);
  for(auto row : result){
    for(auto it : row){
        cout<<it<<" ";
    }
    cout<<endl;
  }
    
    return 0;
}