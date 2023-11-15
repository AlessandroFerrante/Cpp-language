/*
 author Alessandro Ferrante
 * test_set.cpp
*/

/* 
 | The file contains only the instantiation of the object and causes the access error exception;
 * 
 | This example demonstrates the implementation of exception handling 
 | when accessing an instance of a class through the `operator[]` indexing operator. 
 | Specifically, it attempts to access the elements of an `s` object within a `while` loop 
 | that handles exceptions for cases of underflow or overflow when accessing the array. 
 ? Furthermore, the example includes the redefinition of the set, union and difference operators, 
 ? addition and subtraction operators, 
 | with the addition of an element access operator via index that handles any access errors.
 * 
*/

#include "set.h"
#include "set.cpp"

using namespace std;

int main(int argc, char ** argv){
    // Initialization with default constructor
    Set s;
    
    // ? add elements to the set, with redefined operators (overloading).
    s += 20;
    s += 2;
    s += 50;
	s += 30;
	s += 50;

    cout << "S: " << s << endl;

    int i = 0;

    // ? Attempt to access the elements of an object s in a while loop
    try{
        while (true){
            cout << s[i] << endl;
            i++;    // ? Incrementa l'indice per accedere al prossimo elemento, causando un Overflow
          //i--;    // ? Se decrementa l'indice si causerebbe un Underflow;
        }
    }
    // ? Catch any access_error exceptions
    catch (access_error err){
        // ? Specifies the error type: Underflow=0 and Overflow=1
        cout << "Errore numero " << err << endl;
    }

	return 0;
}