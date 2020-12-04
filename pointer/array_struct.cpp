#include <iostream>

using namespace std;

struct name{
    int a;
    float b;
};

int main(){
    name *ele;

    int n = 5;
    
    ele = (struct name*)malloc(n * sizeof(struct name));
    int rand_ele = 2;
    float rand_float = 4.0;

    for(int i=0; i < 5; i++){
        (*(ele + i)).a = rand_ele;
        (*(ele + i)).b = rand_float; 
        rand_ele += 2;
        rand_float += 1.2;
    }

    for(int j=0; j < n; j++){
        cout << (*(ele+j)).a << "\t" << (*(ele+j)).b << "\n"; 
    }
    
    
    return 0;
}
