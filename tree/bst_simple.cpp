#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *leftchild;
    Node *rightchild;
};

class BST{
    public:
        Node *root;
        
        BST(){
            root = NULL;
        }
    public:
        void insert(int val){
            Node *node = new Node();
            node->val = val;
            root = _insertNode(root, node);
        }

        void display(int type){            
            switch(type){
                case 1:
                    //pre-order
                    _preOrder(root);
                    break;
                case 2:
                    //in-order
                    _inOrder(root);
                    break;
                case 3:
                    //post-order
                    _postOrder(root);
                    break;
                default:
                    cout << "Such a choice does not exist." << endl;
            }
            cout << endl;
        }
    
    private:
        Node* _insertNode(Node *root, Node *newnode){
            if(root == NULL){
                root = newnode;
            }
            else if(newnode->val < root->val){
                // move to left sub-tree
                root->leftchild = _insertNode(root->leftchild, newnode);
            }
            else{
                // move to right subtree
                root->rightchild = _insertNode(root->rightchild, newnode);
            }
            return root;
        }

        void _preOrder(Node *root){
            if(root == NULL){
                return;
            }
            cout << root->val << "-->";
            _preOrder(root->leftchild);
            _preOrder(root->rightchild);
        }

        void _inOrder(Node *root){}

        void _postOrder(Node *root){}
};

int main(){
    BST tree;

    tree.insert(100);
    tree.insert(500);
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(600);
    tree.insert(300);

    tree.display(1);
    
    return 0;
}