#include <iostream>

using namespace std;

// Double list has two pointers prev and next
// prev - stores the address of the previous node
// next - stores the address of the next node
struct Node{
    int val;
    Node *prev;
    Node *next;
};

class DoubleList{
    public:
        int MAX_COUNT;
        int current_count;
        Node *head;

        DoubleList(int max_count){
            MAX_COUNT = max_count;
            head = NULL;
            current_count = 0;
        }

        void push_at_begin(int val){
            if(current_count > MAX_COUNT){
                cout << "Overflow detected !!" << endl;
                return;
            }
            Node *node = new Node();
            node->val = val;
            node->prev = NULL;
            node->next = NULL;

            if(head == NULL){
                head = node;
            }
            else{
                node->next = head;
                head->prev = node;
                head = node;
            }
            current_count++;
        }

        void push_at_end(int val){
            if(current_count > MAX_COUNT){
                cout << "Overflow detected !!" << endl;
                return;
            }
            Node *node = new Node();
            node->val = val;
            node->prev = NULL;
            node->next = NULL;

            if(head == NULL){
                head = node;
            }
            else{
                Node *last = traverse_from(head);
                last->next = node;
                node->prev = last;
            }
            current_count++;
        }

        void push_at_pos(int val, int pos){}

        Node* delete_from_begin(){
            if(head == NULL){
                cout << "Underflow detected" << endl;
                return NULL;
            }
            Node *temp = head;
            head = head->next;
            head->prev = NULL;

            cout << "Deleted value : " << temp->val << endl;
            delete temp;

            current_count--;
            return temp;
        }

        Node* delete_from_end(){
            if(head == NULL){
                cout << "Underflow detected" << endl;
                return NULL;
            }

            Node *last = traverse_from(head);
            Node *temp = last;

            if(current_count == 1){
                head = NULL;
            }
            else{
                (last->prev)->next = NULL;
                last->prev = NULL;
            }            
            current_count--;
            cout << "Deleted value : " << temp->val << endl;

            delete temp;
            return temp;
        }

        Node *delete_from_pos(int pos){}

        void traverse(){
            Node *start = head;
            while(start!= NULL){
                cout << start->val << "-->";
                start = start->next;
            }
            cout << endl;
        }
    private:
        Node* traverse_from(Node *start){
            Node *p = start;
            if(p->next == NULL){
                return p;
            }
            else
            {
                return traverse_from(p->next);
            }            
        }

};

int main(){
    DoubleList dlist(100);
        
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
                dlist.push_at_end(val);
                break;
            case 2: // pop
                dlist.delete_from_end();
                break;
            case 3:
                dlist.traverse();
                break;
            default:
                cout << "No such option exist. Try again!!!";
        }
    }
    cout << "You have exited the system.";
    return 0;
}