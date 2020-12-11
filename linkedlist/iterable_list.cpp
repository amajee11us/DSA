#include <iostream>

using namespace std;

/*
 ________________
|__value__|_next_|
Node 
*/

struct Node{
    int val;
    struct Node *next;
};

Node* insert_at_begin(Node *head){
    Node *node = new Node();
    cout << "Enter value : ";
    cin >> node->val;

    node->next = head;        
    head = node;

    return head;
}
int main(){
    Node *head = NULL;
    //Node *prev = NULL;
    
    int node_count = 5;

    cout << "Creating basic lsit :" << endl;
    int i = 0;
    while(i < node_count){
        head = insert_at_begin(head);     
        i++;
    }
    int pos = 0;
    int val;
    cout << "Enter position : ";
    cin >> pos;
    cout << "\n Enter value : ";
    cin >> val;

    Node *prev = head;
    Node *next = head;
    for(int i=0; i < pos; i++){
        prev = prev->next;
        next = prev;
    }
    next = next->next;
    Node *node = new Node();
    node->val = val;
    prev->next = node;
    node->next = next;

    Node *start = head;
    while(start != NULL){
        cout << start->val << "\t" << start->next << endl;
        start = start->next;
    }

    return 0;
}