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
int MaxDepth(Node* root){
    if (root==NULL){
        return 0;
    }

    int x = 0;
    int y = 0;
    x=MaxDepth(root->left);
    y=MaxDepth(root->right);

    return 1+max(x,y);
}