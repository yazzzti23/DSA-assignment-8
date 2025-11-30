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
Node* maxVal(Node* root){
    if(root == NULL) return NULL;
    Node* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    return temp;
}
Node* DeleteNode(Node* root, int key){
    if(root == NULL) return NULL;
    

    if(root->data==key){
        //0 child
        if(root->left== NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child // left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;//here if the root has 1 left child then we put the left child at the roots place and then delete the root
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!= NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child//means return either predecessor or successor 
        if(root->left!=NULL && root->right!=NULL){
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = DeleteNode(root->right, min);
            return root;
        }
    }
    else if(root->data>key){
        root->left = DeleteNode(root->left, key);
        return root;
    }
    else{
        root->right = DeleteNode(root->right, key);
    }
    return root;
}