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
Node* maxVal(Node* root){
    if(root == NULL) return NULL;
    Node* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    return temp;
}

Node* inorderPred(Node* root, Node* target){
    if(root == NULL) return NULL;

    //if left subtree exists
    if(target->left!=NULL){
        return maxVal(target->left);
    }

    // if left subtree doesnt exist
    Node* predecessor = NULL;

    while(root != NULL){
        if(target->data > root->data){
            predecessor = root;      // root is a possible predecessor
            root = root->right;      // go right to find a closer one
        }
        else if(target->data < root->data){
            root = root->left;       // too big, go left
        }
        else {
            break;                   // found target
        }
    }

    return predecessor;
}