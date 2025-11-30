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

Node* minVal(Node* root){
    if(root==NULL) return NULL;
    Node* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    }
    return temp;
}