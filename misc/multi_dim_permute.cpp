#include <iostream>
#include <string>

using namespace std;

void display(int ***arr, int dims[]){
    for(int i=0; i < dims[0]; i++){
        for(int j =0; j < dims[1]; j++){
            for(int k = 0; k < dims[2]; k++){
                int ele = arr[i][j][k];
                cout << ele << "\t";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }
}
int main(){
    int arr[2][3][3] = {
        {
            {1 ,1, 1},
            {2, 2, 2},
            {3, 3, 3}
        },
        {
            {4, 4, 4},
            {5, 5, 5},
            {6, 6, 6}
        }
    };

    int dim_c = 2;
    int dim_h = 3;
    int dim_w = 3;

    int dims[] = {dim_c, dim_h, dim_w};

    // now the input combination
    int swap[] = {1, 0, 2}; 

    //compute output size
    int out_dims[3];
    for(int i=0; i< 3; i++){
        out_dims[i] = dims[swap[i]];
    }

    cout << "Output dims : ";
    for(int i=0; i < 3; i++){
        cout << out_dims[i] << " x ";
    }
    cout << endl;

    int output[out_dims[0]][out_dims[1]][out_dims[2]];

    for(int i=0; i < dims[0]; i++){
        for(int j =0; j < dims[1]; j++){
            for(int k = 0; k < dims[2]; k++){
                int ele_pos[] = {i, j, k};
                output[ele_pos[swap[0]]][ele_pos[swap[1]]][ele_pos[swap[2]]] = arr[i][j][k];
            }
        }
    }


    for(int i=0; i < dims[0]; i++){
        for(int j =0; j < dims[1]; j++){
            for(int k = 0; k < dims[2]; k++){
                int ele = arr[i][j][k];
                cout << ele << "\t";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }

    cout << "Output array" << endl;

    for(int i=0; i < out_dims[0]; i++){
        for(int j =0; j < out_dims[1]; j++){
            for(int k = 0; k < out_dims[2]; k++){
                int ele = output[i][j][k];
                cout << ele << "\t";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }
    
    return 0;
}