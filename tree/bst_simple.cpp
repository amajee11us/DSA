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
            cout << "Insertng : " << val << endl;
            root = _insertNode(root, node);
        }

        int remove(int val){
            int deleted_val = 0;
            // delete element from the tree and re-configure
            root = _deleteNode(root, val);
            return deleted_val;
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

        Node* _deleteNode(Node *root, int key){
            if(root == NULL){
                return root;
            }
            else if(key < root->val){
                root->leftchild = _deleteNode(root->leftchild, key);
            }
            else if(key > root->val){
                root->rightchild = _deleteNode(root->rightchild, key);
            }
            else{
                if(root->leftchild == NULL){
                    Node *temp = root->rightchild;
                    free(root);
                    return temp;
                }
                else if(root->rightchild == NULL){
                    Node *temp = root->leftchild;
                    free(root);
                    return temp;
                }

                // find the inorder successor of the root node
                Node *temp = _inOrderSuccessor(root->rightchild);

                root->val = temp->val;

                root->rightchild = _deleteNode(root->rightchild, temp->val);
                free(temp);
            }
            return root;
        }

        Node* _inOrderSuccessor(Node *node){
            Node *current_node = node;
            while(current_node != NULL && current_node->leftchild != NULL){
                current_node = current_node->rightchild;
            }
            return current_node;
        }

        void _preOrder(Node *root){
            if(root == NULL){
                return;
            }
            cout << root->val << "-->";
            _preOrder(root->leftchild);
            _preOrder(root->rightchild);
        }

        void _inOrder(Node *root){
            if(root == NULL){
                return;
            }
            _inOrder(root->leftchild);
            cout << root->val << "-->";
            _inOrder(root->rightchild);
        }

        void _postOrder(Node *root){}
};

int main(){
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.display(2);

    cout << "Deleting the value : 20" << endl;
    tree.remove(20);
    tree.display(2);

    cout << "Deleting the value : 30" << endl;
    tree.remove(30);
    tree.display(2);

    cout << "Deleting the value : 60" << endl;
    tree.remove(60);
    tree.display(2);
    
    return 0;
}