/*
 author: Alessandro Ferrante
 file: exam_test_4.cpp
*/

#include<iostream>
#include<string>

using namespace std;

class Rectangle{
    private: 
        float b;
        float h;
    public: 
        Rectangle(){}
        // constructor
        Rectangle(float _b, float _h) : b(_b), h(_h){ }
        Rectangle(const Rectangle & r): Rectangle(r.b, r.h) { } 

        float getArea(){
            return b * h;
        }
        float getBase(){
            return b;
        }
        float getHeight(){
            return b;
        }
        void setRect(float _b, float _h){
            b = _b;
            h = _h;
        }
};

template <typename T> class Node{
    private:
        // attribute
        T data;
    public: 
        // default constructor
        Node() : next(nullptr){ }
        // parameters constructo
        Node(T _data) : data(_data), next(nullptr) { }

        T get() { return data; }
        T& getR() { return data; }
        
        void insert(const T data){ 
            Node<T>* new_node = new Node<T>(data);
            new_node->next = this->next;
            this->next = new_node;
        }
        void delete_first(){
            Node<T> * first = this->next;
            this->next = first->next;
            delete first;

        }
        void delete_element(T data){
            Node<T>* current = this->next;
            Node<T>* prev = this;
            while(current != nullptr){
                if(current->get() == data){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = prev->next;
            }
        }
        bool exist(T data){
            Node<T>* p = this->next;
            while(p != nullptr){
                if(p->get() == data)
                    return true;
                p = p->next;
            }
            return false;
        }
        T find(T data){
            Node<T>* f = this->next;
            while(f != nullptr){
                if(f->get() == data){
                    //cout << f->get() << endl;
                    return f->get();
                }
                f = f->next;
            }
            cout << "Not found" << endl;
            T s;
            return s;
        }

        Rectangle* findR( float s) {
            Node<T>* f = this->next;
            while(f != nullptr){
                float area = f->data->getArea();
                if( area == s){
                    return f->data;
                }
                f = f->next;
            }
            cout << "Not found2" << endl;
            return nullptr;
        }

        void show(){
            Node<T>* p = this->next;
            while(p != nullptr){
                cout << "data :" << p->get() << endl;
                p = p->next;
            }
        }

        Node<T>* next;
}; 



int main(int argc, char ** argv){
    Node<string> mylist;
    mylist.insert("dd");
    bool e = mylist.exist("dd");
    cout << "e: " << e << endl;
    string m = mylist.find("mm");
    cout << m << endl;
    mylist.delete_element("dd");
    //Rectangle* rect2 = new Rectangle(3, 5);
    Node<Rectangle*> listRect;
    listRect.insert(new Rectangle(1.4, 5));
    listRect.insert(new Rectangle(3, 5));
    
    Rectangle* rect2 = listRect.findR(77);
    cout << rect2->getArea();
    //bool n = listRect.exist();
    //cout << rect.getArea();
    return 0;
}