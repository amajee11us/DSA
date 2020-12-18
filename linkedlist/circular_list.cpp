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

// For a stack add elements to the head (LIFO)
Node* push(Node *head, int val){
    Node *node = new Node();
    node->val = val;
    if(head == NULL){
        head = node;
        node->next = head; 
    }
    else{
        Node *prev_head = head;
        Node *last = head;
        while(last->next != prev_head){
            last = last->next;
        }
        
        node->next = prev_head;
        head = node;  
        last->next = head;      
    }

    return head;
}
//Node* push_at_end(Node *head, int val){
//}
// pop or delete a node from the head (LIFO)
Node* pop(Node *head){
    // store the head pointer in a place
    Node *to_del = head;
    head = head->next;
    cout << "Value deleted : "<< to_del->val<< endl;
    delete to_del;
    return head;
}

void peek(Node *start){
    cout << "Printing the whole list." << endl;
    Node *p = start->next;
    cout << start->val << "\t" << start << "\t" << start->next << endl;
    while(p != start){
        cout << p->val << "\t" << p << "\t" << p->next << endl;
        p = p->next;
    }

}

int main(){
    Node *head = NULL;
    //Node *prev = NULL;
    
    //int MAX_LIMIT = 3;
    int current_count = 0;
    
    bool exit = false;
    while(exit != true){
        //Print choices after every operation
        cout << "Choices : " << endl;
        cout << "1. Push -- Add a value." << endl;
        cout << "2. Pop -- Remove a value." << endl;
        cout << "3. Peek -- Display the full list." << endl;
        cout << "0. Exit" << endl;

        cout << "Enter any option from 1 through 3 or 0: ";
        int choice;
        cin >> choice;
        
        switch(choice){
            case 0:
                cout << "Exiting." << endl;
                exit = true;
                break;
            case 1: // this is to push a new element
                cout << "\n Enter the new element : ";
                int val;
                cin >> val;
                head = push(head, val);
                current_count++;
                /*
                if(current_count > MAX_LIMIT){
                    cout << "Overflow detected" << endl;
                    break; // end
                }
                */
                break;
            case 2: // pop
                if(current_count <= 0){
                    cout << "Underflow detected." << endl;
                    break;
                }
                head = pop(head);
                break;
            case 3:
                peek(head);
                break;
            default:
                cout << "No such option exist. Try again!!!";
        }
    }
    cout << "You have exited the system.";
    return 0;
}