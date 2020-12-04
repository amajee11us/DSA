#include <iostream>

using namespace std;

int main(){
    int *a;
    int *b = a; // store one pointer into another

    int c = 10;
    *a = c; // store a value in pointer  a <-- c
    
    cout << *a; // print value assigned to a pointer
    
    return 0;
}