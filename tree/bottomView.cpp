#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Program to print bottom view of the BST
eg:
        20
    /    \
    8       22
/   \      \
5      3      25
    / \      
    10    14
Output: 5, 10, 3, 14, 25
*/
struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* newNode(int data){
    Node* node = new Node;
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

void getBottomView(Node* node, 
                   int depth, int width, 
                   map <int, pair <int, int>> &m){
    if (node == NULL)
        return;
    
    if(m.find(width) == m.end())
        m[width] = make_pair(node->val, depth);
    else{
        pair <int, int> p = m[width];
        if(p.second <= depth){
            m[width].second = depth;
            m[width].first = node->val;
        }
    }

    getBottomView(node->left, depth + 1, width - 1, m);
    getBottomView(node->right, depth + 1, width + 1, m);
}

void printBottomView(Node* root){
    map <int, pair <int, int>> m;

    getBottomView(root, 0, 0, m);

    for(auto i = m.begin(); i != m.end(); ++i){
        auto p = i->second;
        cout << p.first << " ";
    }    
}

int main(){
    Node * root = newNode(20);
    root -> left = newNode(8);
    root -> right = newNode(22);
    root -> left -> left = newNode(5);
    root -> left -> right = newNode(3);
    root -> right -> left = newNode(4);
    root -> right -> right = newNode(25);
    root -> left -> right -> left = newNode(10);
    root -> left -> right -> right = newNode(14);

    printBottomView(root);
    return 0;
}