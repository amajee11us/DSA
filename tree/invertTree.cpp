#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Proram to invert a binary tree.
An inversion, or mirror, of a Binary Tree (T),​ 
is just a Binary Tree M(T) whose left and right children (of all non-leaf nodes) 
are swapped.
*/

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* node = new Node;
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void invert(Node* node){
    if (node == NULL)
        return;
    
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    invert(node->left);
    invert(node->right);
}

// in-order traversal
void display(Node* node){
    if(node == NULL)
        return;
    
    display(node->left);
    cout << node->val << " ";
    display(node->right);
}
int main(){
    // take an example tree from GFG
    Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(4);
    root->right->left = newNode(3);
    root->right->right = newNode(5);
    // this is a BST

    //display the tree before inversion
    display(root);
    cout << endl;

    // perform inversion
    invert(root);

    // display the tree after inversion
    display(root);
    cout << endl;

    return 0;
}