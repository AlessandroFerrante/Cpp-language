/*
 author Alessandro Ferrante
 *  constructor_example.cpp
*/

/*
 ? Introduction of the costructor and the destructor,
 ? The constructor acts when the object is created,
 ? performing specific functions such as attribute initialization;
 ? the destructor acts when the object is deleted,
 ? performing specific functions such as freeing a dynamic allocation.
*/

/*
 ? In this example, costruct and destruct have no concrete use, 
 ? in fact the "init" method is still used for the initialization of attributes
*/
#include<iostream>

using namespace std;

/* 
 ? Rectangle class with attributes and methods, 
 | intruduction of constractor and destructor.
*/
class Rectangle {
    private: 
        // attributes
        float b, h;
    public: 
        // ? constructor
        Rectangle();

        // ? destructor
        ~Rectangle();

        //methods
        void init(float _b, float _h);
        float compute_area();
        float compute_perimeter();
};

/*
 ? default constructor, 
 ? in this case it does not perform particular functions
*/ 
Rectangle::Rectangle(){
    cout << "Rect constructor " << endl;
}

/*
 ? default destructor, 
 ? in this case it does not perform particular functions
*/
Rectangle::~Rectangle(){
    cout << "Rect destructor " << endl;
}

// Initializes the attributes
void Rectangle::init(float _b, float _h){
    b = _b;
    h = _h;
}

// Compute and return the perimeter of the rectangle
float Rectangle::compute_perimeter(){
    return (b + h) * 2;
}

// Compute and return the area of the rectangle
float Rectangle::compute_area(){
    return b * h;
}


int main(int argc, char ** argv){
    Rectangle my_rect_1, my_rect_2;

    // Initilize the attributes
    my_rect_1.init(3, 10);
    my_rect_2.init(20.5, 44);

    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << endl;
} 