#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Question:
For a given Binary Tree (BT), 
write a code to print the vertical traversal from the 
leftmost to rightmost levels. 
*/

struct Node{
    int val;
    Node *leftchild;
    Node *rightchild;
};

Node* newNode(int data){
    Node *newNode = new Node;
    newNode->val = data;
    newNode->leftchild = newNode->rightchild = NULL;
    return newNode;
}

void minMaxDepth(Node *node, int *min, int *max, int depth){
    if(node == NULL)
        return;
    if(*min > depth)
        *min = depth;
    else if(*max < depth)
        *max = depth;    
    minMaxDepth(node->leftchild, min, max, depth - 1);
    minMaxDepth(node->rightchild, min, max, depth + 1);
}

void displayElementsOnLine(Node *node, int line_count, int depth){
    if(node == NULL)
        return;
    
    if(depth == line_count)
        cout << node->val << " ";   
    
    displayElementsOnLine(node->leftchild, line_count, depth - 1);
    displayElementsOnLine(node->rightchild, line_count, depth + 1);
}

void traverseVertical(Node *root){
    int min = 0, max = 0, currdepth = 0;
    minMaxDepth(root, &min, &max, currdepth);
    //cout << min << " " << max << endl;
    for(int vline = min; vline <= max; vline++){
        displayElementsOnLine(root, vline, 0);
        cout << endl;
    }
}

int main(){
    // create the tree -- this is a BT and BST
    Node *root = newNode(4);
    root->leftchild = newNode(3);
    root->leftchild->leftchild = newNode(2);
    
    root->rightchild = newNode(5);
    root->rightchild->leftchild = newNode(6);
    root->rightchild->rightchild = newNode(7);
    
    traverseVertical(root);
    return 0;
}