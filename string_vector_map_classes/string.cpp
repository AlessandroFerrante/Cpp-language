/*
 author: ALessandor Ferrante
 * string.cpp
*/

/*
 | The file uses the standard <string> class to perform various operations with strings
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv){
    // Declaration and initialization of strings
    string s = "HeclloWorld";
    string s1 = "Hello";
    
    // ? concatenation of a string
    s1 = s1 + "world";

    // ? insertion of the comma in position 5
    s1.insert(5, ",");

    // display the resulting string
    cout << "S1 : " << s1 << endl;
    
    // ? finds the position of the letter 'c' in the string
    int w_pos  = s.find("c");
    // 
    if (w_pos != string::npos){
        // ? extract a 5 character substring from s starting from the found position (of 'c')        
        string s2 = s.substr(w_pos, 5); // 
        cout << "Substring : " << s2 << endl;
    }
    
    // ? Print the string as a character array
    // ? s1.c_str() is a function of the standard <string> class
    printf("stringa C: %s\n", s1.c_str());

    // ? print string vertically
    cout << "Vertical string" << endl;
    for(int i = 0; i < s1.length(); i++){
        cout << s1[i] << endl;
    }
    
    // ? changes the initial letter of the string
    s1[0] = 'h';
    cout << s1 << endl;

    return 0;
}