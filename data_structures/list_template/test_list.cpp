/*
 author: Alessandro Ferrante
 * test_list.cpp
*/

/*
 | The file imports the "linked_list.h" file 
 | which implements a List class (with template) and a daughter class OrderedList (with ordered insertion)
 | both of which allow the use of different types of elements (string, int and float etc.),
 | in fact in this file three functions are implemented with three different types of lists 
*/

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

// ? unordered list of strings
void test_list_of_strings() {
    List<string> mylist;

    mylist.insert("Alessandro");
    mylist.insert("Marco");
    mylist.insert("Cristian");

    mylist.show();

    if (mylist.exist("Marco"));
        cout << "Marco trovato!" << endl;

    //mylist.delete_first();
    mylist.delete_element("Cristian");

    mylist.show();
}

// ? unordered list of integers
void the_list_of_ints(){
    List<int> intlist;

    intlist.insert(20);
    intlist.insert(10);
    intlist.insert(15);
	intlist.insert(4);
	intlist.insert(30);
    
    intlist.show();
    cout << endl;

    intlist.delete_first();
    intlist.delete_element(4);
    intlist.show();
    cout << endl;
}

// ? ordered list of floats numbers
void the_ordered_list_of_float(){
    OrderedList<float> floatlist;

    floatlist.insert(20.3);
    floatlist.insert(20.2);
    floatlist.insert(20.1);
    floatlist.insert(20.01);
    floatlist.insert(4.3);

    floatlist.show();
    cout << endl;
    floatlist.delete_first();
    floatlist.delete_element(20.1);
    floatlist.show();
}

int main(int argc, char ** argv) {
    // * test list of strings
    test_list_of_strings();

    // * test list of integers
    the_list_of_ints();

    // * test ordered list of float numbers
    the_ordered_list_of_float();
}