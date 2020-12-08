#include <iostream>

using namespace std;

int main(){
    int length;
    char *name;
    char val;

    cout << "Enter Length of string : ";
    cin >> length;
    cout << "\n";

    name = (char*)malloc(length * sizeof(char));
    char *temp = name; // save this address to be used as starting point later
    char *end;
    cout << "Enter input string : ";
    
    for(int i=0 ; i< length; i++){
        cin >> *name;
        // other options :
        //*name = getchar();
        name++;
    }

    // JUMP the address
    name = temp; // name = &name[0] -- > *(name + 0) so dont use
    end = temp + (length * sizeof(char));
    while(name < end){
        cout << *name;
        name = name + (2 * sizeof(char));        
    }
    cout << "\n";
    return 0;
}