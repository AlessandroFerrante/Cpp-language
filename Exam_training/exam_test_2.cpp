/*
 author: Alessandro Ferrante
 * exam_test_2.cpp
*/

#include<iostream>
#include<string>

using namespace std;

class Fruit{
    private: 
        // attributes
        string name;
        string color;
        string season;
        string taste;
    public:
        // parameters constructor
        Fruit(string n, string c, string s) : name(n), color(c), season(s) { };
        // copy constructor
        //Fruit(const Fruit & f): Fruit(f.name, f.color, f.season) { };

        string get_name() { return name; }
        string get_color() { return color; }
        string get_season() { return season; }

        friend ostream& operator<<(ostream& out,  Fruit * f){
            out << "Name : " << f->get_name() << endl;
            out << "Color : " << f->get_color() << endl;
            out << "Season: " << f->get_season() << endl;
            return out;
        }

        virtual string get_taste() = 0;
        virtual string get_type() = 0;
};

class Apple : public Fruit {
    public: 
        string taste;   
        Apple(string name, string color, string season, string taste) : Fruit (name, color, season), taste(taste) { }

        string get_type(){
            return "Apple";
        }

        string get_taste(){
            return taste;
        }
};

class Orange : public Fruit {
    public:  
        string taste;
        Orange(string name, string color, string season, string taste) : Fruit (name, color, season), taste(taste){ };
    string get_type(){
        return "Orange";
    }

    string get_taste(){
        return taste;
    }
};

class QueueEmptyException { };

template <typename T>
class Queue {
    private: 
        // attributes
        T element;
        int size = 0;
        Queue<T> * head, * tail;
    public:
        // default constructor
        Queue() : head(nullptr), tail(this) { }
        // paramters constructor
        Queue(const T & e) : element(e), head(nullptr), tail(this) { }

        void enqueue(T element){
            Queue<T>* new_node = new Queue(element);
            tail->head = new_node;
            tail = new_node;
        }

        T denqueue(){
            if(this == tail)
                throw QueueEmptyException { };
            Queue<T>* first = this->head;
            Queue<T>* new_first = first->head;
            T e = first->element;

            if(first->head == nullptr)
                tail = this;
            cout << "delete" << endl;
            delete first;
            this->head = new_first;

            return e;
        }

        void show(){
            Queue<T>* q = this->head;
            while(q != nullptr){
                cout << q->element << endl;
                q = q->head;
            }           
        }

        void front(){
            Queue<T>* q = this->head;
            if(q != nullptr)
                cout << "Element in front: "<< endl; 
                cout << q->element << endl;
        }
        
        
};  


int main(int argc, char ** argv) {
    Queue<Fruit*> myqueue;
    
    myqueue.enqueue(new Apple("Granny Smith", "Verde", "Autunno", "Aspro"));
    myqueue.enqueue(new Orange("Tarocco", "Arancione", "Inverno", "Dolce"));
    myqueue.enqueue(new Apple("Golden Delicious", "Giallo", "Autunno", "Dolce" ));
    myqueue.enqueue(new Orange("Navel", "Arancione", "Inverno", "Dolce-Acido" ));
    myqueue.enqueue(new Apple("Fuji", "Rosso", "Autunno", "Dolce"));
    myqueue.enqueue(new Orange("Valencia", "Arancione", "Estate", "Acido"));
    
    myqueue.show();
    
    myqueue.denqueue();
    myqueue.denqueue();
    myqueue.show();
    
    myqueue.front();

    return 0;
}