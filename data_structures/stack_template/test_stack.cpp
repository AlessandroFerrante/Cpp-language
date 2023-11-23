/*
 author: Alessandro Ferrante
 * test_stack.cpp
*/

/*
 | The file imports the "stack.h" file 
 | which implements a 'Stack' class with TEMPLATE 
 | This file implements a Student class
 | initializes the respective objects and inserts them into a Stack.
*/

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class Student {
    private:
        string freshman;
        string name;
        string lastname;
    public: 
        Student() : freshman(""), name(""), lastname("") {};

        Student(string _freshman, string _name = "", string _lastname = "") : 
        freshman(_freshman), name(_name), lastname(_lastname) { };

        Student(const Student & s) : freshman(s.freshman), name(s.name), lastname(s.lastname) { };

        bool operator==(Student & s){
            return (freshman == s.freshman);
        }

        bool operator<(Student & s){
            if(lastname < s.lastname) return true;
            if(lastname == s.lastname){
            if(name < s.name) return true;
            }
            return false;
        }

        friend ostream& operator<<(ostream& out, const Student & s){
            out << "(" << s.freshman << "," << s.name << "," << s.lastname << ")" ;
            return out;
        }

};

int main(int argc, char ** argv){
    Stack<Student> mystack;

    mystack.push(Student("1001", "Alessandro", "Ferrante"));
    mystack.push(Student("1002", "Marco", "Ferrante"));
    mystack.push(Student("1003", "Cristian", "Sammito"));
    mystack.push(Student("1004", "Giuseppe", "Denaro"));

    mystack.show();
    
    // ? terminate when the stack is empty and throw an exception
    for(;;){
        Student s = mystack.pop();
        cout << s << endl;
    }

    return 0;
}
