/*
 author: Alessandro Ferrante
 * LinkedList.cpp
*/

/*
 | The file introduces the linked list with the use of classes with the get method 
 ? Use the "get function" because element is a private attribute of the class
 ? get() returns the 'element' as a string type
*/

#include <iostream>
#include <string>

using namespace std;

class Node {
    private: 
        // attributes
        string element;
    public: 
        // constructor
        Node(string e) : element(e) { };

        // method get
        string get() { return element; };

        // pointer to the next node (class node)
        Node * next; // ? creates a pointer of type 'class Node'
};

typedef Node* List; // ? creates a pointer of type class Node, pointer to list, to first node

void insert(List & l, string data){
    // element allocation
    Node * new_node = new Node(data); 

    // attach the new node pointer to the list
    new_node -> next = l; 

    // pointer to list = new node
    l = new_node;
}

void delete_first(List & l){
    Node * first = l; // ? it is a temporary node
    Node * new_first = l->next; // ? saves the node following the first

    delete first;// ? deallocates the first node of the list

    l = new_first; // ? set the new first node
}

void show(List the_list){
    while(the_list != nullptr){
        // ?  use the "get function" because 'element' is a private attribute of the class
        cout << the_list->get() << endl; // ? get() returns the 'element' as a string type

        the_list = the_list->next;
    }
}
int main(int argc, char ** argv){
    List mylist = nullptr;

    cout << "Mylist : " << endl;
    insert(mylist, "Alessandro");
    insert(mylist, "Marco");
    insert(mylist, "Maria");

    show(mylist);
    delete_first(mylist); // ? delete the first node of the list, which is the last one inserted
    cout << "Mylist : " << endl;
    show(mylist);
}