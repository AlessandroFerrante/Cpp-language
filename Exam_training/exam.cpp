/**
 * @file exam.cpp
 * @author Alessandro Ferrante
 * @brief 
 * @version 0.1
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

using namespace std;

class node{
    private:
        //attributes
        int n;
    public:
        node(): next(nullptr) { }
        node(int _n) : n(_n) , next(nullptr) { }

        void insert(int n){
            node* new_node = new node(n);
            if(this->next == nullptr)
                this->next = new_node;
            else{
                node* current = this->next;
                while (current->next != nullptr){
                    current = current->next;
                }
                current->next = new_node;
                
                static int counter;
                counter++;
                if(counter == 4){
                    node* p = this->next;
                    for(int i= 0; i<2; i++){
                        p = p->next;
                    }
                    new_node->next = p;
                }
                
            }
        }

        void show(){
            node* s = this->next;
            while(s != nullptr){
                cout << s->n << "->";
                s = s->next;
            }
            cout << "END";
        }
    bool detectAndRemoveCicle(){
        node* current = this->next;
        for(int i= 0; i<4; i++){
            current = current->next;
        }
        if(current->next != nullptr){
            current->next = nullptr;
            return true;
        }
        return false;
    }

    node* next;
};

int main(int agrc, char ** argv){
    node* mylist = new node();
    mylist->insert(50);
    mylist->insert(20);
    mylist->insert(15);
    mylist->insert(4);
    mylist->insert(10);
    //cout << mylist->detectAndRemoveCicle() << endl;
    //cout << mylist->detectAndRemoveCicle() << endl;
    mylist->show();
    return 0;   
}