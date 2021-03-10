#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display(vector<int> vec, int size){
    for(int i=0; i < size; i++){
        cout << vec[i] << "\t";
    }
    cout << endl;
}

int main(){
    vector<int> entries;
    vector<int> vec1;
    vector<int> vec2;

    int size;
    cout << "Enter the number of elements : ";
    cin >> size;
    cout << endl;

    for(int i=0; i< size; i++){
        cout << "Enter Element : ";
        int val;
        cin >> val;
        entries.push_back(val);
        cout << endl;
    }

    // handle odd number of instances
    int new_size = size;
    if(size % 2 == 0){
       new_size = size/2;
       for(int i=0; i<size; i++){
           if(i%2 == 0){
               vec1.push_back(entries[i]);
           }
           else{
               vec2.push_back(entries[i]);
           }
       }
    }
    else{
        new_size = size - 1;
        int count = 0;
        int prev_small = 0;
        int i,j;
        int smallest;
        for(i = 0 ; i < size; i++){  
            smallest = 65535;          
            for(j = 0; j < size; j++){
                if(count == 0){
                    if(entries[j] < smallest){
                        smallest = entries[j];
                    }
                }
                else{
                    if(entries[j] > prev_small && entries[j] < smallest){
                        smallest = entries[j];
                    }
                }
            }
            cout << "Smallest " << smallest << endl;
            prev_small = smallest;
            if(count == 0){
                count++;
                continue;
            }
            else{
                if(count % 2 !=0){
                    vec1.push_back(smallest);
                }
                else{
                    vec2.push_back(smallest);
                }
                count++;
            }
        }

    }

    // display
    display(vec1, new_size/2);
    display(vec2, new_size/2);
    
    return 0;
}