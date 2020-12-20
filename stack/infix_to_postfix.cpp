#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node{
    char val;
    Node *next;
};

class Stack{
    public:
        int MAX_COUNT;
        Node *head;
        int current_count;

        Stack(){
            head = NULL;
            current_count = 0;
        }
        Stack(int max_count){
            MAX_COUNT = max_count;            
        }

        void push(int val){
            if(current_count > MAX_COUNT){
                cout << "Overflow detected!!!" << endl;
                return;
            }

            Node *node = new Node();
            node->val = val;
            node->next = NULL;

            if(head == NULL){
                head = node;
            }
            else{
                node->next = head;
                head = node;
            }
            current_count++;
        }

        Node* pop(){
            if(current_count <= 0){
                cout << "Underflow detected!!" << endl;
                return NULL;
            }

            Node *del = head;
            head = head->next;
            cout << "Deleted value : " << del->val << endl;
            current_count--;

            return del;
        }

        void display(){
            Node *start = head;
            while(start != NULL){
                cout << start->val << "-->";
                start = start->next;
            }
            cout << endl;
        }
};

class ExpressionSolver : public Stack{
    Stack s;
    int a;
    ExpressionSolver(int max_count){
        Stack s(max_count);
        a = 0;        
    }

    string infixToPostfix(string input){
        string output_string = "";
        cout << s.MAX_COUNT <<endl;
    }
};

int main(){
    ExpressionSolver exp(100);

    return 0;
}