#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node{
    char val;
    Node *next;
};

int current_count = 0;
int STACK_SIZE = 0;

Node* push(Node *head, Node *newNode){
    if(head == NULL){
        head  = newNode;
        current_count++;
    }
    else{
        Node *start = head;
        while(start->next != NULL){
            start = start->next;
        }
        start->next = newNode;
        current_count++;
    }
    return head;
}

void display(Node *head){
    Node *start = head;
    while(start != NULL){
        cout << start->val << ",";
        start = start->next;
    }
    cout << endl;
}
/*
Node* pop(Node *head){

}
*/

int main(){
    // initialization
    STACK_SIZE = 3;
    Node *head_pts[3];

    int n_ele;
    cout << "Enter number of elements : ";
    cin >> n_ele;

    int num_stacks = 1; // default to onl 1 stack
    Node *head = NULL;
    head_pts[0] = head;

    while(current_count < n_ele){
        if(current_count < (num_stacks * STACK_SIZE)){
            // here it is still in an incomplete stack
            Node *newNode = new Node();
            cout << "Enter value : ";
            cin >> newNode->val;

            head_pts[num_stacks - 1] = push(head_pts[num_stacks - 1], newNode);

            display(head_pts[num_stacks - 1]);
        }
        else{
            // stack overflow occured
            num_stacks++;
            Node *newhead = NULL;          

            // add the element again
            Node *newNode = new Node();
            cout << "Enter value : ";
            cin >> newNode->val;
            newhead = push(newhead, newNode);

            head_pts[num_stacks - 1] = newhead;

            display(head_pts[num_stacks - 1]);
        }
    }
    
    return 0;
}