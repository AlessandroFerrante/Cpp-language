/*
 author: Alessandro Ferrante
 * queue.h
*/

/*
 | The file introduces the Stack with the "templates", and its methods, put() , get() and show()
*/

#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>

using namespace std;

class QueueEmptyException { };

template <typename T> class Queue{
    private: 
        // attribute
        T element;
    public:
        // defualt constructor
        Queue() : next(nullptr), tail(this) { };
        //costructor parameters 
        Queue(T e) : element(e), next(nullptr), tail(this) { };
        
        //methods

        // put the items in the queue
        void put(T data){
            Queue<T> * new_node = new Queue<T>(data);
            tail->next = new_node; // ? the tail node will point to the new node
            tail = new_node; // ? avanza il puntatore di coda al nuovo nodo
        }

        // remove items from the queue
        T get(){
            // ? if the queue is empty
            if (this == tail)
                throw QueueEmptyException(); 

            Queue<T> * first = this->next; 
            Queue<T> * new_first = first->next; // ? next node after the first
            T e = first->element;
            
            // ? If the first node is also the last node, update 'tail'
            if (first->next == nullptr)
                tail = this;
            
            // delete the first node
            delete first;
            // ? Updates the pointer to the next item in the queue
            this->next = new_first;

            // return element
            return e;
        }
        // view queue
        void show(){
            Queue<T> * c = this->next;
            while(c != nullptr){
                cout << c->element << endl; // ! use c->element, c->get() removes items from the queue
                c = c->next;
            }
        }

        // ? pointer to the 'next node,' and the 'tail' of the queue
        Queue<T> * next, * tail;
};

#endif