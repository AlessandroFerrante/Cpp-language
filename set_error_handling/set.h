/*
 author Alessandro Ferrante
 * set.h
*/

/*
 | The file contains only the declaration of the SetDuplicates and Set classes.
 *
 | This example demonstrates the implementation of exception handling 
 | when accessing an instance of a class through the `operator[]` indexing operator. 
 | Specifically, it attempts to access the elements of an `s` object within a `while` loop 
 | that handles exceptions for cases of underflow or overflow when accessing the array. 
 ? Furthermore, the example includes the redefinition of the set, union and difference operators, 
 ? addition and subtraction operators, 
 | with the addition of an element access operator via index that handles any access errors.
 * 
 ? A virtual function or method is a class function that is expected 
 ? to be overridden in 'derived classes'. When you reference a derived class object 
 ? using a pointer or base class reference, you can call a virtual function for 
 ? that object and execute the derived class's version of the function.
 *
 ? Virtual functions ensure that the correct function for an object is called,
 ? regardless of the expression used to make the function call.
 ? Suppose that a base class contains a function declared as virtual and 
 ? that a derived class defines the same function. The derived class function is called 
 ? for objects of the derived class, even if it is called using a pointer 
 ? or reference to the base class.
 * 
 ! Functions in derived classes override virtual functions in base classes 
 ! only if their types are the same.
 *
 | The 'virtual' keyword can be used when declaring override functions in a derived class, 
 | but it is not required, virtual function overrides are always virtual.

 _ Abstract class and pure virtual function
 ! Virtual functions in a base class must be defined unless they are declared using the pure specifier.
 | This is a virtual function declared using pure identifier syntax (=0).
 | You create an abstract class by declaring at least one pure virtual member function.
 | The classes derived from the abstract class implemented must be pure virtual function or are also abstract classes.
 | Abstract classes serve as expressions of general concepts from which more specific classes can be derived. 
 | It is not possible to create an abstract type object. However, you can use pointers and references to abstract class types. 
 */
#include <iostream>

using namespace std;

// ? Define an enumeration to handle login errors
typedef enum{
    Underflow, // ? Error if index is less than zero 
    Overflow   // ? Error if index is greater than or equal to array size
} access_error;

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
        
        virtual void add(int elem); // ? Pure 'virtual' method to add an element to the set
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
                throw Underflow;  // Error if index is less than zero  
            if (index >= size)
                throw Overflow;   // Error if index is greater than or equal to array size
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