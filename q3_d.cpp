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

int minDepth(Node* root){
    if (root==NULL){
        return 0;
    }
    int x=0;
    int y=0;

    //left child null
    if(root->left==NULL){
        x = minDepth(root->right);
        return 1+x;
    }
    //right child null
    if(root->right==NULL){
        y = minDepth(root->left);
        return 1+y;
    }

    return 1+min(x,y);
}