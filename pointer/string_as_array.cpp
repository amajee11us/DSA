#include <iostream>

using namespace std;

int main(){
    int length;
    char *name;

    cout << "Enter Length of string : ";
    cin >> length;
    cout << "\n";

    name = (char*)malloc(length * sizeof(char));
    char *temp = name; // save this address to be used as starting point later
    cout << "Enter input string : ";
    
    for(int i=0 ; i< length; i++){
        cin >> *name;
        // other options :
        //*name = getchar();
        name++;
    }
    name = temp; // name = &name[0] -- > *(name + 0) so dont use
    for(int i=0 ; i< length; i++){
        cout << *(name + i);
    }
    cout << "\n";
    return 0;
}