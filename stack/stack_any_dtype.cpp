#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class dtype>
class Stack{
    private:
        struct Node{
            dtype val;
            Node *next;
        }* head;
        int SIZE = 0;
    public:
        Stack(int MAX_SIZE){
            SIZE = MAX_SIZE;
            head = NULL;
        }

        void push(dtype val){
            Node *newNode = new Node;
            newNode->val = val;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            SIZE++;
        }

        dtype pop(){
            if(head == NULL){
                cout << "Empty stack. Nothing to pop." << endl;
                return (dtype)NULL;
            }
            Node *to_pop = head;
            dtype popped_value = to_pop->val;

            head = head->next;
            
            delete to_pop;
            
            SIZE--;
            return popped_value;
        }

        dtype top(){
            if(head == NULL){
                cout << "Empty stack. Nothing to return." << endl;
                return (dtype)NULL;
            }
            return head->val;
        }

        ~Stack(){
            while(head != NULL){
                pop();
            }
        }
};

int main(){
    Stack<int> int_stack(10);
    int_stack.push(1);
    cout << "Element on top : " << int_stack.top() << endl;
    int_stack.push(5);
    cout << "Element on top : " << int_stack.top() << endl;
    int_stack.pop();
    cout << "Element on top : " << int_stack.top() << endl;
    int_stack.pop();
    cout << "Element on top : " << int_stack.top() << endl;

    Stack<char> char_stack(10);
    char_stack.push('a');
    cout << "Element on top : " << char_stack.top() << endl;
    char_stack.push('b');
    cout << "Element on top : " << char_stack.top() << endl;
    char_stack.push('c');
    cout << "Element on top : " << char_stack.top() << endl;
    char_stack.pop();
    cout << "Element on top : " << char_stack.top() << endl;
    char_stack.pop();
    cout << "Element on top : " << char_stack.top() << endl;
    char_stack.pop();
    cout << "Element on top : " << char_stack.top() << endl;

    return 0;
}