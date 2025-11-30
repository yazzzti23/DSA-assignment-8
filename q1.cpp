#include <iostream>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    };
};
TreeNode* insertintoBst(TreeNode* &root, int d){
    if(root == NULL){
        root = new TreeNode(d);
        return root;
    }

    if(d>root->data){
        root->right = insertintoBst(root->right, d);
    }
    else{
        root->left = insertintoBst(root->left,d);
    }

    return root;
}

void preorder(TreeNode *root){
    if(root==NULL) return;

    cout<<" "<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

    
}

void inorder(TreeNode *root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<" "<<root->data<<" ";
    inorder(root->right);

    
}

void postorder(TreeNode *root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data<<" ";
    
}

int main(){
    TreeNode* root = NULL;
    cout<<"insert into bst: ";
    int data;
    cin >> data;
    while(data!=-1){
       insertintoBst(root, data)  ;
       cin>>data;                               
    }

    cout<<"the preorder traversal of the binary tree is "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"the in order traversal of the tree is "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"the postorder traversal of the tree is "<<endl;
    postorder(root);
}