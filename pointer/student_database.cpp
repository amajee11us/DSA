/*
Student database
name, stream
science --> PCM (any 2 subject)
marks <-- input each subject
student no -> 5
*/
#include <iostream>
#include <string>
#include<algorithm>
#include <sstream>

using namespace std;

struct Student{
    char name[100];
    char stream[10];
    float marks[3];
};

bool verifyStream(string stream);
void copyArray(string *src, string *dest);
void displayDetails(Student* record);

//streams
string streams[] = {"pcm", "eco"};
// Subject list
string pcm[] = {"physics", "chemistry", "maths"};
string eco[] = {"Economics", "Maths", "Stats"};

string subject[3];

void copyArray(string *src, string *dest, int input_size){
    for(int i=0; i < input_size; i++){
        *(dest + i) = *(src + i); // only copy values between memory
    }
}

bool verifyStream(string stream){
    transform(stream.begin(), stream.end(), stream.begin(),::tolower); // convert to lower case
    
    int stream_length = streams->length();
    bool is_same = false;
    
    for(int i =0; i < stream_length; i++){
        if(stream.compare(streams[i]) == 0){
            is_same = true;
            if(stream.compare("pcm") == 0){
                copyArray(pcm, subject, 3);
            }
            if(stream.compare("eco") == 0){
                copyArray(eco, subject, 3);
            }
            break;
        }
    }
    return is_same;    
}
void displayDetails(Student* record){
    cout << "---------------------------------------" << endl;
    cout << "NAME : \t" << record->name << endl;
    cout << "STREAM : \t" << record->stream << endl;
    cout << "MARKS : " << endl;
    for(int i = 0; i < sizeof(subject)/sizeof(string); i++){
        cout << "\t" << subject[i] << "\t" << record->marks[i] << endl;
    }
}

int main(){
    // main interface
    int         count;
    Student     *db;
    
    cout <<     "Enter number of students: ";
    cin  >>     count;

    //create a dynamic array of structures
    db = (struct Student*)malloc(count * sizeof(struct Student));
    
    for(int i=0; i < count; i++){
        cout << "\n Enter details for student "<< i+1 << "\n";
        
        cout << "\n Enter name: ";
        cin >> (db + i)->name;

        cout << "\n Enter stream: ";
        cin >> (db + i)->stream;
        bool st_ver = verifyStream((*(db + i)).stream);
        if(st_ver == false){
            cout << "Invalid stream entered. Such a stream does not exist." <<endl;
            break;
        }     
        // receive marks of subjects:
        
        for(int j=0; j < sizeof(subject)/sizeof(string); j++){
            cout << "Enter marks for subject - > " << subject[j] << " : ";
            cin >> (db + i)->marks[j];
            cout << endl;
        }
        
    }
    // Display all values
    for(int j=0;j < count; j++){
        displayDetails(db + j);
    }

    return 0;
}