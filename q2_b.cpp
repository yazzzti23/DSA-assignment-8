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