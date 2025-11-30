#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* Search(Node* root, int key){
    if(root == NULL){
        return root;
    }
    if(root->data == key){
        return root;
    }
    if(root->data<key){
        return Search(root->right, key);
    }
    else{
        return Search(root->left, key);
    }
}
