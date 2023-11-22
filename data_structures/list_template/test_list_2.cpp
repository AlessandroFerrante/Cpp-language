/*
 author: Alessandro Ferrante
 * test_list.cpp
*/

/*
 | The file imports the "linked_list.h" file 
 | which implements a 'List' class with TEMPLATE and a child class 'OrderedList' (with ordered insertion)
 | This file implements a Person class
 | initializes the respective objects and inserts them into an ordered list
*/

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

class Person {
    private: 
        string name;
        string lastname;
        int age;
    public:
        // default constructor
        Person() : name(""), lastname(""), age(0) { }
        // parameters constructor
        Person(string _name, string _lastname, int _age) : 
        name(_name), lastname(_lastname), age(_age) { }
        // copy constructor
        Person(const Person & p) : name(p.name), lastname(p.lastname), age(p.age) { }

        bool operator==(Person & rhs) {
            if (name == rhs.name && lastname == rhs.lastname && age == rhs.age)
                return true;
            else 
                return false;
        }

        bool operator<(Person & rhs) {
            if (lastname < rhs.lastname) return true;
            if (lastname == rhs.lastname){
                if (name < rhs.name) return true;
                if (name == rhs.name)
                    if (age == rhs.age) return true;
            }
            return false;
        }

        friend ostream& operator<<(ostream & out, const Person & p){
            out << "(" << p.name << "," << p.lastname << "," << p.age << ")";
            return out;        
        }
};

int main(int argc, char ** argv){
    OrderedList<Person> mylist;
    Person p1 ("Capo", "Plaza", 25);
    mylist.insert(p1);
    mylist.insert(Person("Alessandro", "Ferrante", 20));
    mylist.insert(Person("Marco", "Ferrante", 19));
    mylist.insert(Person("Giuseppe", "Denaro", 19));
    //cout << p1 <<endl;
    mylist.show();
    //cout <<  mylist << endl;

    mylist.delete_element(Person("Alessandro" , "Ferrante", 20));

    mylist.show();
 
    return 0;
}

