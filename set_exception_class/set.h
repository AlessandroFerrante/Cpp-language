/*
 author Alessandro Ferrante
 * set.h
*/

/*
 | The file contains only the declaration of the SetDuplicates and Set classes.
 *
 | The example uses the <exception> header, which is part of the C++ Standard Library to implement exception handling.
 ? when accessing an instance of a class through the `operator[]` indexing operator. 
 ? Specifically, it attempts to access the elements of an `s` object within a `while` loop 
 ? that handles exceptions for cases of underflow or overflow when accessing the array. 
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
*/

#include <iostream>
#include <exception> // _ Standard Library to implement exception handling

using namespace std;

// | Function to handling error

// ? Parent class for the Underflow and Overflow classes,
// ! but "child class" of the 'standard exception class'
class RangeError : public exception {
    public : 
        // default constructor
        RangeError() : exception() {};
        virtual const char * getMessage(){ return "Range Error"; };
};

// ? child class of th e RangeError class
class UnderflowError : public RangeError {
    public : 
        // dafault costructor
        UnderflowError() : RangeError() {};
        const char * getMessage() { return "Index < 0 Error"; };
};

// ? child class of the RangeError class
class OverflowError : public RangeError {
    public :
        // defautl constructor
        OverflowError() : RangeError() {};
        const char * getMessage() { return "Index >= size Error"; }; 
};

// Parent class
class SetDuplicates{
    // ? 'protected' is used as 'private' but also allows access to child classes
    protected: 
        // attributes
        int * data; //* Dynamic array to contain the elements of the set
        int size; //* Set size
    public: 
        // default constructor
        SetDuplicates();
        // copy constructor
        SetDuplicates(SetDuplicates& s);
        // destructor
        ~SetDuplicates();

        // methods  
        
        virtual void add(int elem); // ? 'Virtual' method to add an element to the set
        bool remove(int elem); // ? To remove a set element
        bool find(int elem); // ? To search for an element of the set

        //* redefinition of the left-shift operator
        friend ostream& operator<<(ostream& output_stream, SetDuplicates & s);
        // ? Addition operator (+=) overloaded
        SetDuplicates& operator+=(int elem){
            this->add(elem);
            return *this;
        };
        // ? Subtraction operator (-=) overloaded
        SetDuplicates& operator-=(int elem){
            remove(elem);
            return *this;
        };
        // ? Union operator (+) overloaded
        SetDuplicates operator+(SetDuplicates & rhs);
        // ? Difference operator (-) overloaded
        SetDuplicates operator-(SetDuplicates & rhs);
        
        // ? Operator for accessing elements via index with exception handling 
        int operator[](int index){ 
            if (index < 0)
                throw UnderflowError();  // ? Function that throw an exception for underflow error
            if (index >= size)
                throw OverflowError();   // ? Function that throw an exception for overflow error

            return data[index]; 
        };

        // ? Method to get the length of the set
        int length() { return size; }; 
};

// Child class that inherits from Set Duplicates
class Set : public SetDuplicates {
    public: 
        // ? override inherited method, adds an element to the set
        void add(int elem) override;
        // ? derived class-specific union operator
        Set operator+(Set& rhs);
};