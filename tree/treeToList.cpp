#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
For a given binary tree “BT,” 
convert it into a Doubly Linked List (DLL), 
using the left and right pointers in the nodes 
as the previous and subsequent pointers in the DLL.
*/

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    Node* node = new Node();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void treeToList(Node* root, Node **head){
    if(root == NULL)    
        return;

    static Node* prev = NULL;

    treeToList(root->left, head);

    // whatever is the node --> add to list
    if(prev == NULL)
        *head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    treeToList(root->right, head);
}

void displayTree(Node* root){
    if(root == NULL)
        return;
    displayTree(root->left);
    cout << root->val << " ";
    displayTree(root->right);
}

int main(){
    Node* root =  createNode(1);
    root->left = createNode(3);
    root->left->left = createNode(2);
    root->right = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(10);

    displayTree(root);
    cout << endl;

    //for the list
    Node *head = NULL;
    
    treeToList(root, &head);

    while(head != NULL){
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
    
    return 0;
}