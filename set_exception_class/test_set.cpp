/*
 author Alessandro Ferrante
 * test_set.cpp
*/

/* 
 | The file contains only the instantiation of the object and causes the access error exception;
 * 
 | The example uses the <exception> header, which is part of the C++ Standard Library to implement exception handling.
 | when accessing an instance of a class through the `operator[]` indexing operator. 
 | Specifically, it attempts to access the elements of an `s` object within a `while` loop 
 | that handles exceptions for cases of underflow or overflow when accessing the array. 
 ? Furthermore, the example includes the redefinition of the set, union and difference operators, 
 ? addition and subtraction operators, 
 ? with the addition of an element access operator via index that handles any access errors.
 *
 | The <exception> header has key components that allow you to specify 
 | different types of errors (exception, bad_exception, logic_error, runtime_error).
 *
 | When using exceptions, you use the keywords try, catch and throw. 
 ? The try block encloses code that might throw an exception,
 ? and the catch block catches and handles the exception if one is thrown. 
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
    try {
        // ! Code that might throw an exception
		i = -1;  // ? It decrements the index and causes an Underflow, because it starts from position -1;
		while (true) {
			cout << s[i] << endl;
			i++; // ? Increment the index to access the next element, causing an overflow
		}
	}
    // ? Catch any access_error exceptions
	catch (UnderflowError & err) {
        // ? Specifies the error type
		cout << "Underflow! " << err.getMessage() << endl;
	}
    // ? Catch any access_error exceptions
	catch (OverflowError & err) {
        // ? Specifies the error type
		cout << "Overflow! " << err.getMessage() << endl;
	}

	return 0;
}