#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void insert(int arr[], int end){
    int last = arr[end];
    int j = end - 1;
    while(j >= 0 && arr[j] > last){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void insertSort(int arr[], int key, int len){
    if(key >= len){
        return;
    }
    int end = key;
    insert(arr, end);
    insertSort(arr, key+1, len);
}
/*
 [12, 11, 13, 5, 6] - key = 0 and last = 4
 []

*/
int main(){
    // start main program
    int size = 5;

    int arr[] = {12, 11, 13, 5, 6};

    cout << "Input array : " << endl;
    for(int i=0; i < size; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;

    insertSort(arr, 0, size);
 
    cout << "Output array : " << endl;
    for(int i=0; i < size; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}