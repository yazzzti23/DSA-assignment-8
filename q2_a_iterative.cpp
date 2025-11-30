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

Node *Search(Node* root, int key){
    Node*  curr = root;
    
    while(curr!=NULL){
        if(curr->data == key){
            return curr;
        }
        else if(curr->data<key){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return NULL;//not found
}