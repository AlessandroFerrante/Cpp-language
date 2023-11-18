/*
 author: Alessandro Ferrante
 * vector.cpp
*/

/*
 * ---------------------------------------------------------------------------------------
 | The file introduces the 'iterators' with the standard <vector> class 
 | with some of its methods for performing operations with vectors.
 * ---------------------------------------------------------------------------------------
 _ Iterators are objects that allow you to iterate through the elements of a sequence, 
 _ such as an array or a container data structure such as a list or vector. 
 * ---------------------------------------------------------------------------------------
 ? To print the elements of the vector we use a function implemented 
 ? within a namespace, to avoid repeating the same snippet multiple times.
 * ---------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

namespace vect{
    void print_vect(vector<float> & vect){
        /*for(vector<float>::const_iterator it = vect.cbegin(); it != vect.cend(); it++) {
            cout << *it << " -> ";
        }*/
        // ? use "auto" notation instead of extended "vector<string>::const_iterator" notation
        for(auto it = vect.cbegin(); it != vect.cend(); it++) {
            cout << *it << " -> ";
        } 
        cout << "END" << endl;
    }
};

int main(int argc, char ** argv) {
    // ? Create a vector v with 3 elements of value 0 
    vector<float> v; 
    // ? Create a vector v1 by allocating the elements of v
    vector<float> v1;//(v.get_allocator());

    //? add the elements to the end of the vector
    v.push_back(10.3);
    v.push_back(5.2);
    v.push_back(4.1);
    v.push_back(1.4);
    //? deletes the elements at the end of the vector
    v.pop_back();
    
    // ?to view v
    /*
    cout << "Vector v : " ;
    for(const auto& p : v) {
        cout << p << " -> ";
    }
    cout << "END" << endl;
    */

    // ? iterator, use 'it' to access each element in the sequence
    for(vector<float>::iterator it = v.begin(); it != v.end(); it++){
        *it = *it * 10.0;
    }
    // ? const iterator, does not change the values
    cout << "Vector v : " ;
    // ? Use 'it' to access each element in the sequence
    for(vector<float>::const_iterator it = v.cbegin(); it != v.cend(); it++){
        cout << *it << " -> ";
    }
    cout << "END" << endl;

    // ? reverse iterator
    cout << "Reverse Vector v : END";
    for(vector<float>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        cout << " <- " << *it ;
    }
    cout << " <- " << "START" << endl;

    // ? to view v1
    cout << "Vector v1 : ";
    if( v1.empty( ) ){
        cout << "empty vector!" << endl;
    }
    else{
        vect::print_vect(v1); // ? call the function implemented in the namespace
    }

    // ? inverts the elements of the vectors
    cout << "Swap" << endl;
    v.swap(v1); 

    // ? to view v
    cout << "Vector v : ";
    if( v.empty( ) ){
        cout << "empty vector!" << endl;
    }
    else{
        vect::print_vect(v); // ? call the function implemented in the namespace
    }

    // ? to view v1
    cout << "Vector v1 : " ;
    vect::print_vect(v1); // ? call the function implemented in the namespace
    
    return 0;
}