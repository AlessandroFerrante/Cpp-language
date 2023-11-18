/*
 author: Alessandro Ferrante
 * vector.cpp
*/

/*
 | The file introduces the standard <vector> class 
 | with some of its methods for performing operations with vectors
*/
#include <iostream>
#include <vector>

using namespace std;

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
    
    // ? to view v
    cout << "Vector v : " ;
    for(const auto& p : v) {
        cout << p << " -> ";
    }
    cout << "END" << endl;


    // ? to view v1
    cout << "Vector v1 : ";
    if( v1.empty( ) ){
        cout << "empty vector!" << endl;
    }
    else{
        for(const auto& d : v1) {
            cout << d << " -> ";
        }
        cout << "END" << endl;
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
        for(const auto& p : v) {
            cout << p << " -> ";
        }
        cout << "END" << endl;
    }

    // ? to view v1
    cout << "Vector v1 : " ;
    for(const auto& d : v1) {
        cout << d << " -> ";
    }  
    cout << "END" << endl;
    
    
    return 0;
}