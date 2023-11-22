/*
 author: Alessandro Ferrante
 * test_list.cpp
*/

/*
 | The file imports the "linked_list.h" file 
 | which implements a 'List' class with TEMPLATE and a child class 'OrderedList' (with ordered insertion)
 | This file implements a Student class
 | initializes the respective objects and inserts them into an ordered list
*/

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

class Student {
    private:
        string freshman;
        string name;
        string lastname;
    public: 
        // default constructor
        Student(): freshman(""), name(""), lastname("") { }
        // parameters constructor
        Student(string _freshman, string _name ="", string _lastname ="") : freshman(_freshman), name(_name), lastname(_lastname) { } 
        // copy constructor
        Student(const Student & s) : freshman(s.freshman), name(s.name), lastname(s.lastname) { }

        bool operator==(
             Student & s) {
            return (freshman == s.freshman);
        }

        bool operator<(Student & s) {
            if (lastname < s.lastname) return true;
            if (lastname == s.lastname) {
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
    OrderedList<Student> mylist;

    mylist.insert(Student("1001", "Mario", "Rossi"));
    mylist.insert(Student("1002", "Giuseppe", "Verdi"));
    mylist.insert(Student("1003", "Salvatore", "Bianchi"));
    
    mylist.show();
    cout << endl;

    // ? in the "parameters constructor", name and last name are initialized to empty strings
    mylist.delete_element(Student("1001"));

    mylist.show();
    cout << endl;

    string f;
    cout << "Inserisci una matricola : " ;
    cin >> f;

    Student * s = mylist.find(Student(f));
    if (s == nullptr)
        cout << "Matricola "<< f <<" non presente" << endl;
    else
        cout << *s << endl;

}