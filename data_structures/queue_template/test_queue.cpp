/*
 author: Alessandro Ferrante
 * test_queue.cpp
*/

/*
 | The file imports the "queue.h" file 
 | which implements a 'Queue' class with TEMPLATE 
 | This file implements a Student class
 | initializes the respective objects and inserts them into a Queue.
*/

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

class Student{
    private:
        string freshman;
        string name;
        string lastname;
    public: 
        // default constructor
        Student() : freshman(""), name(""), lastname("") { }
        // pameters constructor
        Student(string _freshman, string _name = "", string _lastname = "") : 
            freshman(_freshman), name(_name), lastname(_lastname) { };
        Student(const Student & s): freshman(s.freshman), name(s.name), lastname(s.lastname) { }

        // to
        bool operator==(Student & s){
            return (freshman == s.freshman);
        }

        bool operator<(Student & s){
            // ? true if this < rhs false in other cases 
            // ? sorting only on first and last name
            if(lastname < s.lastname) return true;
            if(lastname == s.lastname){
                if(name == s.name) return true;
            }
            return false;
        }

        friend ostream& operator<<(ostream& out,const Student & s){
            out << "("<< s.freshman << ", " << s.name << ", " << s.lastname << ");" ;
            return out; 
        }
};

int main(int argc, char ** argv){
    Queue<Student> myqueue;

    myqueue.put(Student("1001", "Alessandro",  "Ferrante"));
    myqueue.put(Student("1002", "Marco", "Ferrante"));
    myqueue.put(Student("1003", "Mario", "Rossi"));
    myqueue.put(Student("1004", "Giuseppe", "Verdi"));
    
    myqueue.show();
    
    // ? terminate when the queue is empty and throw an exception
    for(;;){
        Student s = myqueue.get();
        cout << s << endl;
    }

    return 0;
}
