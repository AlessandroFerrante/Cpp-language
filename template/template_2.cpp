/*
 author: Alessandro Ferrante
 *template_2.cpp
*/
/* 
 | The example uses "templates"
 | Templates allow you to write generic code, independent of specific data types. 
 | Instead of writing a separate version of code for each data type, you can define a template 
 | that takes types as parameters, allowing for greater flexibility 
 | and reuse of code for a variety of data types.
 _ The <typename T> prompts you to specify the type when the object is instantiated.

 - The file contains the declaration Person class,
 - the implementation of the methods and instantiation the 'String' objects, for testing.
 ? To insert 'numbers' and 'Person objects' into 'Set objects', import 'the template_set.h file'
 ? The example uses "templates" in class declarations and method implementations
 ? Uses the <cstring> header, to handle string operations.
*/
#include <iostream>
#include <cstring>
#include "template_set.h"

using namespace std;

class Person{
    private:
        char name[40];
        char lastname[40];
    public: 
        // default constructor
        Person(){
            name[0] = 0;
            lastname[0] = 0;
        };
        // parameters constructor
        Person(const char * _name, const char * _lastname){
            strcpy(name, _name);
            strcpy(lastname, _lastname);
        };
        // copy constructor
        Person(const Person & p){
            strcpy(name, p.name);
            strcpy(lastname, p.lastname);
        };

        // ? Redefinition of comparison operator '=='
        bool operator==(Person & rhs){
            if(strcmp(name, rhs.name) ==0 & strcmp(lastname, rhs.lastname) ==0 ) 
                return true;
            else
                return false;
        };

        friend ostream& operator<<(ostream& out, Person & p){
            out << p.name << " " << p.lastname; 
            return out;
        }

};

int main(int argc, char ** argv){
    
    // ? The <typename T> prompts you to specify the type when the object is instantiated, 
    // ? the type of the variable is specified with <typename> (ex. <int>, <float>).
    SetDuplicates<int> s;

    s += 20;
    s +=2;
    s += 50;
	s += 30;
	s += 50;
	s += 10.5;
	cout << "S: ";
	s.show();

    SetDuplicates<float> s2;
	s2 += 10.3;
	s2 += 4.5;
	cout << "S2: ";
	s2.show();
	
    // ? The <typename> can be used to pass an object, in this case it is <Person>
	SetDuplicates<Person> s3;
	s3 += Person("Mario", "Rossi");
	s3 += Person("Giuseppe", "Verdi");
	cout << "S3: ";
	s3.show(); // ? displays the elements of type Person within the s3 set
	
	s3 -= Person("Mario", "Rossi");
	cout << "S3: ";
	s3.show();
	
	return 0;
}