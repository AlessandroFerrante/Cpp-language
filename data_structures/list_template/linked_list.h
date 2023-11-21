/*
 author: Alessandro Ferrante
 * linked_list.cpp
*/

/*
 | The file introduces the List with the "templates", 
 | in addition, the "OrderedList" child class 
 | allows in-order insertion through the override of the insert method
*/

#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <string>

using namespace std;

template <typename T> class List{
    private:
        T element;
    public: 
        // default constructr
        List() : next(nullptr) { }
        // paramters constructor
        List(T e) : element(e), next(nullptr) { }

        // methods

        T get() { return element;}
        
        // inserts the item into the list, at the top
        virtual void insert(T data){
            List<T> * new_node = new List<T>(data);
            new_node->next = this->next;
            this->next = new_node;
        }

        void delete_first() {
            List<T> * first = this->next;
            List<T> * new_first  = first->next;
            delete first;
            this->next = new_first;
        }

        void delete_element(T data){
            List<T> * current = this->next;
            List<T> * prev  = this;
            while (current != nullptr){
                if (current->get() == data){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = prev->next;
            }
        }

        void show(ostream & output = cout){
            List<T> * p  = this->next;
            cout << "Mylist is: ";
            while (p != nullptr){
                output << p->get() << " -> ";
                p = p->next;
            }
            cout << "END" << endl;
        }

        bool exist(T data) {
            List<T> * e = this->next;
            while (e != nullptr){
                if(e->get() == data)
                    return true;
                e = e->next;
            }
            return false;
        }

        T * find(T data) {
            List<T> * f = this->next;
            while (f != nullptr) {
                if (f->get() == data)
                    return &f->element;
                f = f->next;
            }
            return nullptr;
        }

        List<T> * next; 
};

// child class, to insert in order
template <typename T> class OrderedList : public List<T>{
    public: 
        // override insert methos
        void insert(T data) override{
            List<T> * new_node = new List<T>(data); // Initialize the new node
            // scroll the list to insert the element in order
            List<T> * current = this->next;
            List<T> * prev  = this;
            while (current != nullptr && current->get() < data) {
                current = current->next;
                prev = prev->next;
            }
            // places the item in the correct position
            prev->next = new_node;
            new_node->next = current;        
        }
};

#endif