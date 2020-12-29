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
            head = NULL;
            current_count = 0;          
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

        char top(){
            return head->val;
        }

        void display(){
            Node *start = head;
            while(start != NULL){
                cout << start->val << ",";
                start = start->next;
            }
            cout << endl;
        }
};

class ExpressionSolver{
    public:
        Stack s; // create a member of the class and initialize it
        int a;
        ExpressionSolver(int max_count) : s(max_count){        
            a = 0;        
        }

    private:
        int getPrecedence(char op){
            // return character precedence
            int weight = -1;
            switch(op)
            {
                case '+':
                case '-':
                    weight = 1;
                    break;
                case '*':
                case '/':
                    weight = 2;
                    break;
                case '^':
                    weight = 3;
                    break;
            }
            return weight;
        }

        bool isOperator(char op){
            // check if this is a operand
            if((op == '+') || (op == '-') || (op == '/') || (op == '*') || (op == '^')){
                return true;
            }
            else{
                return false;
            }      
        }

        bool isOperand(char op){
            if(((op >= 'A') && (op <= 'Z')) || ((op >='a') && (op <= 'z')))
                return true;
            else
                return false;
        }
    
    public:
        string infixToPostfix(string input){
            string postfix_exp = "";
            cout << s.MAX_COUNT <<endl;
            int i = 0; // loop variabele
            // Step 1: Iterate over all elements of the stack
            while(i < input.length()){
                char element = input[i];
                if(isOperand(element) == true){
                    // Step 2: If an operand then add it to the output
                    postfix_exp += element;
                    i++;
                }
                else if(element == '('){
                    // Step 3: If at start of experiment then push to stack
                    s.push(element);
                    i++;
                }
                else if(element == ')'){
                    if(s.current_count <= 0){
                        // No element in the list
                        i++;
                    } 
                    else if(s.top() == '('){
                        cout << "Inside here " << endl;
                        char garbage = s.pop()->val;
                        i++;
                    }
                    else{
                        postfix_exp += s.pop()->val;
                    }
                }
                else if(isOperator(element) == true){
                    if(s.top() == '(' || (getPrecedence(element) > getPrecedence(s.top()))){
                        s.push(element);
                        i++;
                    }
                    else{
                        postfix_exp += s.pop()->val;
                    }
                }
                cout << postfix_exp << endl;
            }
            return postfix_exp;
        }
};

int main(){
    string infix = "(A/(B-C)*D+E))";

    ExpressionSolver exp(100);
    string postfix = exp.infixToPostfix(infix);

    cout << "Postfix Expression : " << postfix << endl;

    return 0;
}