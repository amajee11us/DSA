// C++ program to explain  
// multiple inheritance 
#include <iostream> 
using namespace std; 
  
// first base class 
class Vehicle { 
    public:
        Vehicle() 
        { 
            cout << "This is a Vehicle" << endl; 
        } 
    protected:
        int veh_count = 10;

        void get_update(){
            updator();
        }
    private:
        void updator(){
            veh_count += 25;
        }
}; 

// second base class 
class FourWheeler { 
  public: 
    FourWheeler() 
    { 
      cout << "This is a 4 wheeler Vehicle" << endl; 
    } 
}; 

// sub class derived from two base classes 
class Traffic: public Vehicle, public FourWheeler{ 
  public:
    Traffic(){
        cout << "We are in a traffic" << endl;
        cout << veh_count << endl;
        get_update();
        cout << veh_count << endl;
    }
    int load = 20;
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Traffic obj; 
    //cout << obj.load << endl;
    return 0; 
} 