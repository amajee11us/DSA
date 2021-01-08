#include "include/myMathHeader.h"

using namespace myName;
using namespace std;

int main(){
    Mathlib mylib;
    int num1 = mylib.get_input();
    int num2 = mylib.get_input();

    // add
    cout << "Addition result : " << mylib.do_sum(num1, num2) << endl;

    // multiply
    cout << "Multiplication result : " << mylib.do_multiply(num1, num2) << endl;

    // divide
    cout << "Division result : " << mylib.do_divide(num1, num2) << endl;

    int p = mylib.get_input();
    cout << "Power : " << mylib.power(num1, p) << endl;
    return 0;
}