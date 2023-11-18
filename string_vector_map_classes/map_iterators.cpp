/*
 author: Alessandro Ferrante
 * map.cpp
*/

/* 
 * ----------------------------------------------------------------------------------------
 | The file introduces the 'iterators' with the standard map class with some of the methods.
 * -----------------------------------------------------------------------------------------
 _ Iterators are objects that allow you to iterate through the elements of a sequence, 
 _ such as an array or a container data structure such as a list or vector. 
 _ There are iterator with begin() and end() methods,
 _ cost_iterator with cbegin() and cend() methods and
 _ reverse_iterator with the rbegin() and rend() methods;
 _ they use 'it' to be able to iterate and refer to the element.
 * -----------------------------------------------------------------------------------
 | Used for storing and retrieving data from a collection 
 | where each element is a pair that has both a data value and a sort key.
 |  The key value is unique and is used to automatically sort the data.
 |  The value of an item in a map can be changed directly. 
 | The key value is a constant and cannot be changed. 
 | Instead, the key values associated with the old items should be deleted 
 | and the new key values should be inserted into the new items.
 * -----------------------------------------------------------------------------------
 + The map is a standard container made up of (key,value) pairs, 
 + which can be retrieved based on a key, in logarithmic time.
 - Parametri del modello:
 ? _Key – Type of key objects.
 ? _Tp Type of mapped objects.
 ? _Compare – Comparison function object type, defaults to less<_Key>.
 ?  _Alloc – Allocator type, defaults to allocator<pair<const _Key, _Tp>. 
 * -----------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char ** argv){
    // key = freshman(type string);
    // value = name+lastname (type string);
    // - map<type key, type value> name model;
    map<string, string> database;

    // ? Store name and surname by associating them with the key
    database["X81000100"] = "Mario Rossi";
    database["X81000101"] = "Giuseppe Verdi";
	database["X81000102"] = "Salvatore Bianchi";
	
	/**
    // ? Display the values contents of the models using the reference key
    cout << database["X81000100"] << endl;
	cout << database["X81000101"] << endl;
	cout << database["X81000102"] << endl;
    */

    // ? Display the values contents of the models using vector and iterators
    vector<string> keys;
    //? Save the keys, const iterator, does not change the values
    for(map<string, string>::const_iterator it = database.cbegin() ; it!= database.cend(); it++){
        keys.push_back(it->first);
    }
    
    // ? Display values of the map database, const iterator, does not change the values
    /*
    for(vector<string>::const_iterator it = keys.cbegin(); it != keys.cend(); it++){
        cout << *it << "," << database[*it] << endl;
    }
    */
   // ? use "auto" notation instead of extended "vector<string>::const_iterator" notation
   for(auto it = keys.cbegin(); it != keys.cend(); it++){
        cout << *it << "," << database[*it] << endl;
    }
}