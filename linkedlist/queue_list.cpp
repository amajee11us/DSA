#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

class Queue{
    public:
        int MAX_COUNT;
        int current_count;
        Node *head, *tail;

        Queue(int max_count){
            MAX_COUNT = max_count;
            current_count = 0;
            head = NULL;
            tail = NULL;
        }

        void enqueue(int val){
            /*
                Add elements to end of list
            */
            if(current_count + 1 > MAX_COUNT){
                cout << "Overflow detected" << endl;
                return;
            }
            Node *node = new Node();
            node->val = val;

            if(head == NULL){
                head = node;
                tail = node;
                node->next = NULL;// indicating the end of list
            }
            else{
                tail->next = node;
                tail = node;
                node->next = NULL; //last node
            }
            current_count++;
        }

        Node* dequeue(){
            /*
                Delete elements from top of list - FIFO
            */
           if(head == NULL){
               cout << "Underflow deteccted" << endl;
               return NULL;
           }
           Node *deleted = head;
           head = head->next;

           current_count--;

           cout << "Deleted value : " << deleted->val << endl;
           delete deleted;

           return deleted;
        }

        void display(){
            display_from(head);
        }

    private:
        void display_from(Node *start){
            if(start == NULL){
                cout << endl;
                return;
            }
            else{
                cout << "(" << start->val << "," << start << ") -->";
                return display_from(start->next);
            }
        }
};

int main(){
    Queue queue(100);
        
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
                queue.enqueue(val);
                break;
            case 2: // pop
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            default:
                cout << "No such option exist. Try again!!!";
        }
    }
    cout << "You have exited the system.";
    return 0;
}