#include <iostream>

using namespace std;

int main(){
    int *a;
    int arr[5];
    int i = 0;
    a = arr;
    for(i=0; i < 5; i++){
        *(a + i) = i;
        cout << *(a + i) << "\t" << (a + i) << "\t" << "\n";
    }
    return 0;
}