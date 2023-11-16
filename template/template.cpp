/*
 author: Alessandro Ferrante
 * template.cpp
*/

/*
 | The example uses "templates"
 | Templates allow you to write generic code, independent of specific data types. 
 | Instead of writing a separate version of code for each data type, you can define a template 
 | that takes types as parameters, allowing for greater flexibility 
 | and reuse of code for a variety of data types.
 _ The <typename T> prompts you to specify the type when the object is instantiated.
 - The file contains the declaration 'String' class, 
 - the implementation of the methods and instantiation the 'String' objects, for testing.
 ? Uses the <cstring> header, to handle string operations.
*/

#include <iostream>
#include <cstring>

using namespace std;

class String {
    private: 
        char * char_array;
    public: 
        // parameters constructor 
        String(const char * s){
            char_array = new char[strlen(s) + 1];
            strcpy(char_array, s);
        }
        // default constructor
        String(){
            char_array = new char[2];
            strcpy(char_array, "c");
        }
        // copy constructor
        String(String & s) {
            char_array = new char[strlen(s.char_array) + 1];
            strcpy(char_array, s.char_array);
        }
        // destructor
        ~String(){ delete [] char_array; }

        // ? comparison operator >
        bool operator>(String & rhs){
            return strcmp(char_array, rhs.char_array) > 0;
        }

        // ? copy assignment operator =
        void operator=(const String& rhs) {
            if (this != &rhs) {
                delete[] char_array;
                char_array = new char[strlen(rhs.char_array) + 1];
                strcpy(char_array, rhs.char_array);
            }
            else{
                cout << "You're copying the same object! " << endl;
            }
        }

        // ? redefinition of the left-shift operator to print
        friend ostream& operator<<(ostream& out, String & s){
            out << s.char_array;
            return out;
        }
};

// ? Template function that returns the maximum between two values ​​of generic type T.
// ? In this way it is possible to use variables of different types
template <typename T> T Max(T a, T b){
    if (a > b) return a;    // ? Use the > redeferenced operator to compare
    else return b;
}

int main(int argc, char ** argv){
    // with numbers
    float a = Max(1.0, 3.0);
    int v = Max(3, 4);

    // with strings
    String s1("Alessandro");
    String s2("Marco");

    // compare stringsand returns the string that follows the other
    String s_max;
    s_max = Max(s1, s2);

    cout << s_max << endl; // ? Use the redeferenced operators = and > 

    s1 = s1;// test = operator 
    s2 = s1;
    cout << s2 << endl;
}