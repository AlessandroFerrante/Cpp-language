/**
 * @file exam_test_5.cpp
 * @author Alessandro Ferrante
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class QueueEmptyException{ };

template<typename T> class node{
    private:
        T data;
    public:
        node() : tail(this), next(nullptr){}
        node(T _data) : data(_data), tail(this), next(nullptr) { }
        node<T>* next;
        node<T>* tail;

        void enqueue(T data){
            node<T>* new_node = new node<T>(data);
            tail->next = new_node;
            tail = new_node;
        }

        T denqueue(){
            if(this == tail)
                throw QueueEmptyException();
            node<T>* head = this->next;
            //node<T>* new_head = head->next;
            T temp = head->data;
            if(head->next == nullptr)
                tail = this;
            this->next = head->next;
            delete head;
            return temp;            
        }

        void show(){
            node<T>* s = this->next;
            while(s != nullptr){
                cout << s->data << " -> ";
                s = s->next;
            }
            cout << "END" << endl;
        }

        void showShape(){
            node<T>* s = this->next;
            while(s != nullptr){
                vector<double> dimension;
                s->data->getDimension(dimension);
                cout << "Dimension of " << s->data->getType() << ": " ;
                for(const double & value : dimension){
                    cout << value << " and ";
                }
                double area = s->data->getArea();
                cout << "area: "<< area;
                cout << " -> ";
                s = s->next;
            }
            cout << "END" << endl;
        }
};
class Shape{
   public:
    Shape(){ }
    virtual double getArea() = 0;  
    virtual void getDimension(vector<double> &dimension) = 0;
    virtual string getType() = 0;

};

class Rectangle : public Shape{
    private: 
        double base;
        double height;
    public:
        Rectangle(double _base, double _height) :  base(_base), height(_height){ }
        double getArea() override{
            return base*height;
        };
        void getDimension(vector<double> &dimension) override{
            dimension.clear();
            dimension.push_back(base);
            dimension.push_back(height);
        };
        string getType() override{
            return "Rectangle";
        }
};
class Square : public Rectangle{
    private: 
        double side; // unnecessary if not implement getDimension()
    public:
        Square(double _side) : Rectangle(_side, _side), side(_side){ }
        void getDimension(vector<double> &dimension) override{
            dimension.clear();
            dimension.push_back(side);
        };
     string getType() override{
            return "Square";
        }
};

class Circle : public Shape{
    private:
        double radius;
    public:
        Circle(double _radius) : radius(_radius) { }
        double getArea(){
            return 3.14*radius*radius;
        }
        void getDimension(vector<double> &dimension){
            dimension.clear();
            dimension.push_back(radius);
        }
        string getType() override{
            return "Circle";
        }
};

class Triangle : public Shape{
    private: 
        double base;
        double height;
    public: 
        Triangle(double _base, double _height) : base(_base), height(_height){ }
        double getArea(){
            return (base*height)/2;
        }
        void getDimension(vector<double> &dimension){
            dimension.clear();
            dimension.push_back(base);
            dimension.push_back(height);
        }
        string getType() override{
            return "Triangle";
        }
};

int main(int argc, char ** argv){
    node<string> queue;
    queue.enqueue("a");
    queue.enqueue("b");
    queue.enqueue("c");
    queue.enqueue("d");
    queue.enqueue("e");
    queue.enqueue("f");
    queue.enqueue("g");
    queue.show();
    queue.denqueue();
    queue.denqueue();
    queue.denqueue();
    queue.show();
    node<Shape*> queueS;
    queueS.enqueue(new Rectangle(4, 5));
    queueS.enqueue(new Rectangle(3, 6));
    queueS.enqueue(new Rectangle(12, 3));
    queueS.enqueue(new Square(5));
    queueS.enqueue(new Square(16));
    queueS.enqueue(new Square(9));
    queueS.enqueue(new Circle(7));
    queueS.enqueue(new Circle(3));
    queueS.enqueue(new Circle(2));
    queueS.enqueue(new Triangle(7, 5));
    queueS.enqueue(new Triangle(4, 9));
    queueS.enqueue(new Triangle(2, 13));
    queueS.showShape();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    queueS.denqueue();
    cout << "Denqueue x9..." << endl;
    queueS.showShape();
    return 0;
}
