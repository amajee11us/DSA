#include <iostream>
#include <fstream>

using namespace std;

void file_write(string fname){
    ofstream fst;
    string line;

    fst.open(fname);

    while(fst){
        getline(cin, line);

        if (line == "-1"){
            break;
        }

        fst << line << endl;
    }

    fst.close();
}

int main(){
    ifstream fin; // input file stream
    ofstream fout; //out put file stream
    // create first file
    file_write("sample1.txt");
    file_write("sample2.txt");

    ifstream fin1; // ptr for first class
    ifstream fin2; // ptr for second class

    fin1.open("sample1.txt");
    fin2.open("sample2.txt");

    swap(fin1, fin2);

    string line;
    
    cout << "CONTENTS OF FILE 1 after swapping" << endl;
    while(fin1){
        getline(fin1, line);

        if (line == ""){
            continue;
        }
        cout << line << endl;
    }

    fin1.close();

    cout << "CONTENTS OF FILE 2 after swapping" << endl;
    while(fin2){
        getline(fin2, line);

        if (line == ""){
            continue;
        }
        cout << line << endl;
    }

    fin2.close();
    

    return 0;
}