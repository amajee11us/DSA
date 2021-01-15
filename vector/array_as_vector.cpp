#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student{
    string name;
    float marks;
    vector<int> sports;
};

student create_record(const string& name, float marks){
    student record;
    record.name = name;
    record.marks = marks;

    return record;
}
int main(){
    vector<student> datastore;

    for(int i = 0; i < 10; i++){
        datastore.push_back(create_record("Anay", 12.5)); // add empty structure
    
        cout << "  Vector : "  << datastore[i].name << "\t" << datastore[i].marks <<  endl;
    }
    return 0;
}