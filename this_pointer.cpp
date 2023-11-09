/*
 author Alessandro Ferrante
 * this_pointer.cpp
*/

/*
 ? The example illustrates the use of the `this` pointer, 
 ? which allows you to access the current object's attributes 
 ? and methods within the class's methods.

 ? The `this` pointer is a special pointer that is used 
 ? within the methods of a class to access the attributes 
 ? and methods of the current object. In other words, 
 ? the `this` pointer *points to the object for which 
 ? the method was called. 
 ? The `this` pointer is used when you want to access 
 ? the attributes of an object within a method of the class, 
 ? but not you know the name of the current object. 
 ? In this mode, you can refer to the current object without
 ? having to explicitly name it.
*/

#include <iostream>

using namespace std;

class Rectangle{
    private: 
        // attributes
        float b, h;
        int id;
    public: 
        // constructor
        Rectangle(float _b, float _h);
        // destructor
        ~Rectangle();
        
        //methods
        float compute_area();
        float compute_perimeter();

        // ? Getter methods to access private attributes
        float get_b() { return b; };
        float get_h() { return h; };
        // ? Method to get dimensions with reference parameters
        void get_dimension(float & _b, float & _h){
            _b = b;
            _h = h;
        };

        // ? Setter methods for modifying private attributes
        void set_b(float _b) { b = _b; };
        void set_h(float _h) { h = _h; };
        // ? Method to set the size using individual parameters
        void set_dimension(float _b, float _h){
            b = _b;
            h = _h;
        };
        
        // ? Method for displaying dimensions
        void show();
};

// ? Function to display dimensions
void show_dimension(Rectangle * r){
    cout << "This size is " << r->get_b() << " x " << r->get_h() << endl;
}

void Rectangle::show(){  
    show_dimension(this); // ? `this` is a POINTER of type Rectangle,
    // ?                  // ? which points to the current object.
}

// constructor
Rectangle::Rectangle(float _b, float _h){
    cout << "Rect costructor " << endl;
    this->b = _b;
    this->h = _h;
}

// default destructor
Rectangle::~Rectangle(){
    cout << "Rect destructor " << endl;
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
    // Initialize the attributes
    Rectangle my_rect_1(3, 10);
    Rectangle my_rect_2(20.5, 44);

    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << endl;
    // ? Displaying the dimensions of the rectangle 1
    show_dimension(&my_rect_1);

    // ? Create dynamic object using pointer
    Rectangle * my_rect_3;
    my_rect_3 = new Rectangle(30, 40);

    cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << endl;
    cout << "Area of rect 3 = " << my_rect_3->compute_area() << endl;

    // ? View the size of my_rect_3 in three different ways
    // ? First way
    cout << "? View the size of my_rect_3 in three different way \n? First way with methods get_b() and get_h()  " << endl;
    cout << "The size of rect 3 is " << my_rect_3->get_b() << " x " << my_rect_3->get_h() << endl;
    // ? Second way with function get_dimention()
    cout << "? Second way with function get_dimension()" << endl;
    float base, height;
    my_rect_3->get_dimension(base,  height);
    cout << "The size of rect 3 is " << base << " x " << height << endl;
    // ? Third way method show()
    cout << "? Third way with method show()" << endl;
    my_rect_3->show();// ? Call the rectangle method 3, that use function get_dimension()

    // deallocation
    delete my_rect_3;

    // ? Set the new dimensions of the rectangle 1
    my_rect_1.set_dimension(3, 4);
    cout << "Nuove dimensioni impostate per il rect 1 (" << my_rect_1.get_b() << " x " << my_rect_1.get_h() <<")" << endl;
    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
}