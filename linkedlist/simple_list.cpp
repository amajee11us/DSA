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

int main(){
    Node *head = NULL;
    Node *first = NULL;
    
    head = new Node();
    first = new Node();

    head->val = 8;
    head->next = first;

    first->val = 2;
    first->next = NULL;

    Node *start = head;
    while(start != NULL){
        cout << start->val << "\t" << start->next << endl;
        start = start->next;
    }

    return 0;
}