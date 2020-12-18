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

class CircularList{
    public:
        Node *head;
        int current_count;
        int MAX_COUNT;

    CircularList(int max_count){
        MAX_COUNT = max_count;
        current_count = 0;
        head = NULL;
    }
    public:
        void push_at_begin(int val){
            if((current_count + 1) > MAX_COUNT){
                cout << "List overflow !!" << endl;
                return;
            }
            //create the node
            Node *node = new Node();
            node->val = val;

            //check for empty list
            if(head == NULL){
                head = node;
                node->next = head; // store the value back
            }
            else{
                Node *last = _traverse_from(head);
                /*
                while(last->next != head){
                    last = last->next;
                }*/
                cout << last->val << endl;
                node->next = head;
                head = node; // update the head
                last->next = node;                
            }
            current_count++;
        }

        Node* pop_from_begin(){
            if(head == NULL){
                cout << "Underflow detected!!" << endl;
                return NULL;
            }
            Node *deleted = head;

            Node *last = _traverse_from(head);
            cout << last->val << endl;
            head = head->next;
            last->next = head;
            current_count--;

            return deleted;
        }

        void push_at_end(Node *head, int val){
            if((current_count + 1) > MAX_COUNT){
                cout << "List overflow !!" << endl;
                return;
            }
            //create the node
            Node *node = new Node();
            node->val = val;

            //check for empty list
            if(head == NULL){
                head = node;
                node->next = head; // store the value back
            }
            else{
                Node *last  = _traverse_from(head);
                last->next = node;
                node->next = head;
            }
            current_count++;
        }

        Node* pop_from_end(Node *head){
            if(head == NULL){
                cout << "Underflow detected!!" << endl;
                return NULL;
            }

            Node *prev = head;
            Node *next = head->next;
            while(next != head){
                next = next->next;
                prev = prev->next;
            }
            Node *deleted = next;
            delete next;
            prev->next = head;
            current_count--;

            return deleted;
        }

        void display(){
            Node *p = head;
            //cout << "(" << head->val << "," << head << ")" << "--->" << "\t";
            
            do{
                cout << "(" << p->val << "," << p << ")" << "--->" << "\t";
                p = p->next;
            }while(p != head);
            
            cout << endl;
        }
    
        Node* _traverse_from(Node *start){
            Node *pos = start;
            if(pos->next == head){
                return pos;
            }
            else{
                return _traverse_from(pos->next);
            }
        }
};

int main(){
    CircularList cir_list(100);
        
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
                cir_list.push_at_begin(val);
                break;
            case 2: // pop
                cir_list.pop_from_begin();
                break;
            case 3:
                cir_list.display();
                break;
            default:
                cout << "No such option exist. Try again!!!";
        }
    }
    cout << "You have exited the system.";
    return 0;
}