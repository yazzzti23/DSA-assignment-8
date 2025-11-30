/*All nodes in the left subtree  <  root
All nodes in the right subtree >  root
AND both subtrees are BSTs */
#include <iostream>
#include <limits.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (root == NULL)
        return true;

    // The current node must lie strictly within the range.
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return 
        isBSTUtil(root->left,  minVal, root->data) &&
        isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    // Example Tree:
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    if (isBST(root))
        cout << "This is a BST\n";
    else
        cout << "This is NOT a BST\n";

    return 0;
}
