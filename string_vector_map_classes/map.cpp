/*
 author: Alessandro Ferrante
 * map.cpp
*/

/*
 | The file introduces the standard map class with some of the methods.

 _ The map is a standard container made up of (key,value) pairs, 
 _ which can be retrieved based on a key, in logarithmic time.
 
 | Used for storing and retrieving data from a collection 
 | where each element is a pair that has both a data value and a sort key.
 |  The key value is unique and is used to automatically sort the data.
 |  The value of an item in a map can be changed directly. 
 | The key value is a constant and cannot be changed. 
 | Instead, the key values associated with the old items should be deleted 
 | and the new key values should be inserted into the new items.
 
 - Parametri del modello:
 ? _Key – Type of key objects.
 ? _Tp Type of mapped objects.
 ? _Compare – Comparison function object type, defaults to less<_Key>.
 ?  _Alloc – Allocator type, defaults to allocator<pair<const _Key, _Tp>. 
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char ** argv){
    // key = freshman(type string);
    // value = name+lastname (type string);
    // - map<type key, type value> name model;
    map<string, string> database;

    // ? Sstore name and surname by associating them with the key
    database["X81000100"] = "Mario Rossi";
    database["X81000101"] = "Giuseppe Verdi";
	database["X81000102"] = "Salvatore Bianchi";
	
    // ? Display the values ​​or contents of the models using the reference key
	cout << database["X81000100"] << endl;
	cout << database["X81000101"] << endl;
	cout << database["X81000102"] << endl;
}