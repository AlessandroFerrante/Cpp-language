/*
 author: Alessandro Ferrante
 * stack.cpp
*/

/*
 | The file introduces the Stack with the "templates", and its methods
*/

#ifndef __STACK_H
#define __STACK_H

#include <iostream>

using namespace std;

// ? for empty stack exception
class StackEmptyException { };

template <typename T> class Stack{
    private: 
        // attribute
        T element;
    public:
        // default constructor
        Stack() : next(nullptr) { }
        // parameters constructor
        Stack(T e) : element(e), next(nullptr) { }

        // methods
        T get() { return element; }
        
        // puts items on the stack
        virtual void push(T data){
            Stack<T> * new_node = new Stack<T>(data);
            new_node->next = this->next;
            this->next = new_node;
        }

        // pops items from the stack
        T pop() {
            Stack<T> * first = this->next;

            if (first == nullptr)
                throw StackEmptyException(); // ? for empty stack exception
            
            Stack<T> * new_first = first->next;
            T temp = first->element;
            delete first;
            this->next = new_first;
            return temp;
        }

        // view stack
        void show() {
            cout << "My stack is : ";
            Stack<T> * p = this->next;
            while(p != nullptr) {
                cout << p->get() << endl;
                p = p->next;
            }
            cout << "END" << endl;
        }
       // pointer to the next node
        Stack<T> * next;
};

#endif