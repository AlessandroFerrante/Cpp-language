/*
 author: Alessandro Ferrante
 * linked_list_C++.cpp
*/

/*
| The file introduces the linked list with dummy node using the class and its methods 
| (get, insert, delete first, delete element, exist and show), instead of external functions.
*/

#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        // attributes
        string element;
    public: 
        // default constructor
        Node() : element(""), next(nullptr) { };
        // parameters constructor 
        Node(string e) : element(e), next(nullptr) { };

        // methods
        
        string get() { return element; };
        
        void insert(string data) {
            // element allocation
            Node * new_node= new Node(data);
            // attach the new node pointer to the list
            new_node->next = this->next;
            // pointer to list = new node
            this->next = new_node;
        }

        // delete the last one not inserted, which is at the top
        void delete_first(){
            Node * first = this->next;
            this->next = first->next;

            delete first;
        }
        
        // ? delete the specif element
        void delete_element(string data){
            Node * current = this->next; // ? for the current node
            Node * prev = this; // ? for the previous node
            while (current != nullptr){
                if (current->get() == data){
                    //* data found
                    prev->next = current->next;
                    delete current;
                    return;
                }
                //* data not found, scrolls the list
                current = current->next;
                prev  = prev->next;
            }
        }

        void show() {
            cout << "MyList is : ";
            Node * p = this->next;
            while (p != nullptr){
                cout << p->get() << " -> ";
                p = p->next;
            }
            cout << "END";
        }

        bool  exist(string data) {
            Node * p = this->next;
            while (p != nullptr) {
                if (p->get() == data)
                    return true;
                p = p->next;
            }
            return false;
        }

        // pointer to the next node (class node)
        Node * next;   
};

// ? creates a pointer of type class Node, pointer to list, to first node
typedef Node List;

// overloading << insertion operator for printing the object
ostream& operator<<(ostream& output, Node & n){
    n.show();
    return output;
}

int main(int argc, char ** argv) {
    List mylist;

    mylist.insert("Alessandro");
    mylist.insert("Marco");
    mylist.insert("Cristian");
    mylist.insert("Peppe");
    mylist.insert("1234");

    // ? print the list using the rereferenced operator <<
    cout << mylist << endl;

    if (mylist.exist("Marco"))
        cout << "'Marco' trovato" ;
    cout << endl;    

    //mylist.delete_first();
    mylist.delete_element("1234");

    // ?print the list using the show() method
    mylist.show();

    return 0;
}