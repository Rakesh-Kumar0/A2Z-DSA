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

// function that will mark the parent or upward arrow
void markParents(Node* root, unordered_map<Node*, Node*> &parent_track , Node* target){
    queue<Node*> queue;
    queue.push(root);
    while(!queue.empty()){
        Node* current = queue.front();
        queue.pop();
        if(current->left){
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

// function that will measure distance
vector<int> distanceK(Node* root, Node* target, int k){
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<Node*, bool> visited;
    queue<Node*> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!queue.empty()){ // second bfs to go upto k level from target node and using our hashtable info
        int size = queue.size();
        if(curr_level++ == k) break;
        for(int i=0; i<size; i++){
            Node* current = queue.front();
            queue.pop();
            if(current->left && !visited[current->left]){
                queue.push(current->left);
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right]){
                queue.push(current->right);
                visited[current->right] = true;
            }

            if(parent_track[current] && !visited[parent_track[current]]){
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while(!queue.empty()){
        Node* current = queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    return result;
}

int main(){
    // creating the root node
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    Node* target = root->left;
    int k;
    cout<<"Enter value of k : ";
    cin>>k;
    vector<int> result = distanceK(root, target, k);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}