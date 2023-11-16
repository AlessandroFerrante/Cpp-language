/*
 author: Alessandro Ferrante
 * template_set.h
*/

/*
 | The example uses "templates"
 | Templates allow you to write generic code, independent of specific data types. 
 | Instead of writing a separate version of code for each data type, you can define a template 
 | that takes types as parameters, allowing for greater flexibility 
 | and reuse of code for a variety of data types.
 _ The <typename T> prompts you to specify the type when the object is instantiated.

 - The file contains the declaration SetDuplicates class and the implementation of the methods.
 ? The example uses "templates" in class declarations and method implementations
 ? The file is imported into the 'template_2.cpp' file to insert 'numbers' and 'Person objects' into 'Set objects'
 ? uses the <exception> header, to implement exception handling.
*/

#include <iostream>
#include <exception>

using namespace std;

// ? Parent class for the Underflow and Overflow classes,
// ? but "child class" of the 'standard exception class'
class RangeError : public exception {
    public : 
        // default constructor
        RangeError() : exception() {};
        virtual const char * getMessage(){ return "Range Error"; };
};

// ? child class of the RangeError class
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

// | SetDuplicates class with the use of templates, 
// _The <typename T> prompts you to specify the type when the object is instantiated
template <typename T> class SetDuplicates{
    protected: // as private, but also visible to child classes
        T * data;
        int size;
    public: 
        // default constructor
        SetDuplicates() : size (0) { };
        // copy constructor
        SetDuplicates(SetDuplicates& s) {
            size = s.size;
            data = new T[size];
            for (int i = 0; i < size; i++){
                data[i] = s.data[i];
            }
        };       
        // destructor
        ~SetDuplicates() {
            if (size > 0)
                delete []data;
        };

        // ? Pure 'virtual' method to add an element to the set    
        virtual void add(T elem) {
            //  New larger array
            T * new_data = new T[size + 1];
            // Copy of elements already existing in the set
            for (int i = 0; i < size; i++){
                new_data[i]= data[i];
            }

            // ? Adding the element to the new array
            new_data[size] = elem; 

            // ? Deallocates memory of the existing array if it already contained elements
            if(size > 0)
                delete []data;

            data = new_data; // ? Update the pointer to the new array
            size++; // ? Increments the size of the set object
        }

        // ? To remove a set element
        bool remove(T elem){
            int i;
            for(i = 0; i < size; i++){
                if (data[i] == elem)
                    break;
            }
            
            // ? if the element does not exist, return false
            if(i == size)
                return false;

            size--;

            // If the set is not empty
            if (size > 0){
                // ? Move the elements following the element to be removed to cover the hole, 
                // ? in fact it starts from the position where the control stops 
                // ? and sets j = i (i -> position of the element found)
                for(int j = i ; j < size; j++){
                    data[j] = data[j+1];
                }

                T * new_data = new T[size];
                for (int i = 0; i < size; i++){
                    new_data[i]  = data[i];
                }
                // deallocate the memory pointed to the previous array; 
                delete []data;
                // update the pointer to the new array
                data = new_data;
            }
            else
                delete []data;
            return true;
        }

        // ? To search for an element of the set
        bool find(T elem){
            for (int i = 0; i < size; i++){
                if (data[i] == elem)
                    return true;
            }
            return false;
        }

        SetDuplicates& operator+=(T elem){
            this->add(elem);
            return *this;
        }
        // ? Subtraction operator (-=) overloaded
        SetDuplicates& operator-=(T elem){
            remove(elem);
            return *this;
        }

        // ? Operator for accessing elements via index with exception handling 
        int operator[](int index){ 
            if (index < 0)
                throw UnderflowError();  // ? Function that throw an exception for underflow error
            if (index >= size)
                throw OverflowError();   // ? Function that throw an exception for overflow error

            return data[index]; 
        }

        // ? to display the object data
        void show() {
            for (int i = 0; i < size;i++) {
                cout << data[i] << endl;
            }
	    }
};