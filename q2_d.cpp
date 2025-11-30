#include <iostream>
using namespace std;
//in successor if - target is in leftsubtree - root might be a successor but if the target is in right subtree root cannot be a successor so we 
//we check if suppose for succ there is not right ST then we check if target data is less than root data - if yess
// then that means the succ might be in left subtree so we put the succ= fucnto(left)
//if the target data is > root data then we just return fucn call to right ST we dont assign it to the succ we return it 
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

Node* inorderSucc(Node* root, Node* target){
    if(root == NULL){
        return NULL;
    }

    //right subtree exists;
    if(target->right!=NULL){
        return minVal(target->right);
    }
    //right subttree doesnt exist
    Node* successor = NULL;

    while(root != NULL){
        if(target->data < root->data){
            successor = root; // root is a possible successor
            root = root->left;
        }
        else if(target->data > root->data){
            root = root->right;
        }
        else {
            break; // found the target
        }
    }
    return successor;
}

