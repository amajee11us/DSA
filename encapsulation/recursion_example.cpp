#include <iostream>

using namespace std;

int power(int value, int power);

int power(int value, int pow){
    if(pow == 1){
        return value;
    }
    else{
        return value * power(value, pow - 1);
    }
}

int main(){
    int value;

    cout << "Enter value : ";
    cin >> value;

    int powered = power(value, 3);
    cout << "\n Cube of number : " << powered << endl;
    return 0;
}