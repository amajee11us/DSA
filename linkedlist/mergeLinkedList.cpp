#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
You’re given two Linked Lists “A” and “B” that are sorted. Write a code to merge the two Linked Lists. 
Input : [2 ← 3 ← 7] [4 ←5 ← 9]
Output : [2 ← 3 ← 4 ← 5 ← 7 ← 9] 

*/

struct Node{
    int val;
    Node* next;
};

Node* newNode(int val){
    Node* node = new Node();
    node->val = val;
    node->next = NULL;
    return node;
}

Node* insert(Node* head, int val){
    if(head == NULL){
        head = newNode(val);        
    }
    else if(head->next == NULL){
        Node* node = newNode(val);
        head->next = node;
    }        
    else
        insert(head->next, val);
    return head;
}

void display(Node* head){
    if(head == NULL)
        return;
    else{
        cout << head->val << " <-- ";
        display(head->next);
    }
}

void merge(Node* head1, Node* head2){
    // ASSUMPTION : both list 1 and list 2 are sorted
    Node* prev = NULL;
    while(head1 != NULL){
        while(head2->val < head1->val && head2 != NULL){
            Node* toInsert = head2;
            head2 = head2->next;
            toInsert->next = head1;
            prev->next = toInsert;
            prev = toInsert;
        }
        prev = head1;
        head1 = head1->next;
    }
    head1 = prev;
    while(head2 != NULL){
        head1->next = head2;
        head2 = head2->next;
    }
}

int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;

    head1 = insert(head1, 2);
    insert(head1, 3);
    insert(head1, 7);

    head2 = insert(head2, 4);
    insert(head2, 5);
    insert(head2, 9);

    display(head1);
    cout << endl;
    display(head2);
    cout << endl;

    merge(head1, head2);

    display(head1);
    cout << endl;
    
    return 0;
}