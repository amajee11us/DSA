#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin; // input file stream
    ofstream fout; //out put file stream

    string line;

    fout.open("sample.txt");

    while(fout){
        getline(cin, line);

        if (line == "-1"){
            break;
        }

        fout << line << endl;
    }

    fout.close();

    // start reading the file
    fin.open("sample.txt");

    while(fin){
        getline(fin, line);

        if (line == ""){
            continue;
        }
        cout << line << "\t" << &(fin) << endl;
    }

    fin.close();

    return 0;
}