/*
 author: Alessandro Ferrante
 * list_dummy_node.cpp
*/

/*
 | The file introduces the dummy node in the linked list with the use of classes and with the get method .
 | The rest of the functions outside the class are adapted for the presence of the dummy node
 ? The delete method is modified but has the same final effect
*/

#include <iostream> 
#include <string>

using namespace std;

class Node{ 
    private:
        // attributes
        string element;
    public: 
        // constructor
        Node(string e) : element(e), next(nullptr){ }
        
        // method get
        string get() { return element; }

        // pointer to the next node (class node)
        Node *next;  // ? creates a pointer of type 'class Node'
};

// ? creates a pointer of type class Node, pointer to list, to first node
typedef Node *List;

void insert (List l, string data){
    // element allocation
    Node * new_node= new Node(data);
    
    // attach the new node pointer to the list
    new_node->next = l->next;

    // pointer "to list" = new node
    l->next = new_node;
}

// | delete method, modified but with the same final effect
void delete_first(List l){
    Node * first = l->next; // ? it is a temporary node
    //Node * new_first = first->next; // saves the node following the first
    l->next = first->next; // ? saves the node following the first

    delete first; // ? deallocates the first node of the list
    //l->next = new_first; // set the new first node
}


void show (List the_list){
    // ? starts from the second element of the list
    Node * p = the_list->next;// ? use p, because the first node is the dummy node

    while( p != nullptr){
        // ?  use the "get function" because 'element' is a private attribute of the class
        cout << p->get() << " -> ";

        p = p->next;
    }
}
int main(int argc, char ** argv){
    List mylist = new Node(""); // ? dummy node

    insert(mylist, "Alessandro");
    insert(mylist, "Marco");
    insert(mylist, "Cristian");
    insert(mylist, "Peppe");

    cout << "MyList is : ";
    show(mylist);
    cout << "END" << endl;

    // ? delete the last one not inserted, which is at the top
    delete_first(mylist);
    delete_first(mylist);

    cout << "MyList is : ";
    show(mylist);
    cout << "END" << endl;
    
    // ? delete the last one not inserted, which is at the top
    delete_first(mylist);
    delete_first(mylist);

    cout << "MyList is : ";
    show(mylist);
    cout << "END" << endl;


    // ? test with empty list
    // ? delete the last one not inserted, which is at the top
    delete_first(mylist);
    delete_first(mylist);
    
    cout << "MyList is : ";
    show(mylist);
    cout << "END" << endl;
}