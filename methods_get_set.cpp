/*
author Alessandro Ferrante
* methods_get_set.cpp
*/

/*
 ? The example demonstrates the use of the get and
 ? set methods to access and modify the attributes of an object.

 ? The set and get methods are commonly used to access 
 ? and change the values ​​of variables or properties of an object.

 ? They can be used together to create a property of an object 
 ? that can be read and written. For example, you can create 
 ? a property called dimension for a Rectangle object that 
 ? allows you to set and retrieve the size of the rectangle.
*/

#include <iostream>

using namespace std;

// class Rectangle
class Rectangle{
    private:
        // attributes 
        float b, h;
    public:
        // constructor
        Rectangle(float _b, float _h);
        // destructor
        ~Rectangle();

        //methods
        float compute_perimeter();
        float compute_area();

        // ? The "get" method is used to get or retrieve the value of a variable
        float get_b() { return b; };
        float get_h() { return h; };
        // ? The get_dimension method is used to retrieve the size of the rectangle.      
        // ? reference operators are used to copy values ​​directly into passed variables (by reference)        
        void get_dimension(float & _b, float & _h){ 
            _b = b;
            _h = h;
        };

        // ? The `set` method is used to set or assign a value to a variable       
        void set_b(float _b){ b = _b; };
        void set_h(float _h){ h = _h; };
        // ?  the set_dimension method is used to set the size of the rectangle
        void set_dimension(float _b, float  _h){
            b = _b;
            h = _h;
        };
};

// costructor
Rectangle::Rectangle(float _b, float _h){
    cout << "Rect constructor " << endl;
    b = _b;
    h = _h;
}

// destructor
Rectangle::~Rectangle(){
    cout << "Rect destructor " << endl;
}

// Compute and return the perimeter of the rectangle
float Rectangle::compute_perimeter(){
    return 2 * (b + h);
}

// Compute and return the area of the rectangle
float Rectangle::compute_area(){
    return b * h;
}

int main(int argc, char ** argv){
    // Initialize the attributes
    Rectangle my_rect_1(3, 10);
    Rectangle my_rect_2(22.5, 44);

    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << endl;

    //  Create dynamic object using pointer, and initialize with constructor
    Rectangle * my_rect_3;
    my_rect_3 = new Rectangle(30, 40);

    cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << endl;
    cout << "Area of reect 3 = " << my_rect_3->compute_area() << endl;

    // ? View the size of my_rect_3 in two different ways
    // ? First way
    cout << "? View the size of my_rect_3 in three different way \n? First way with methods get_b() and get_h()  " << endl;
    cout << "The size of rect 3 is " << my_rect_3->get_b() << " x " << my_rect_3->get_h() << endl;
    
    // ? Second way with function get_dimention()
    cout << "? Second way with function get_dimension()" << endl;
    float base, height;
    // ? pass the variables that are taken from the prototype with the & operator,
    // ? thus the values ​​inside them are modified directly
    my_rect_3->get_dimension(base, height);
    cout << "The size of rect 3 is " << base << " x " << height << endl;

    // deallocate rect3
    delete my_rect_3;
    
    // ?  Set the new dimension of the rectangle
    my_rect_1.set_dimension(4, 3);
    cout << "? New size set for rect 1" << my_rect_1.get_b() << " x " << my_rect_1.get_h() << endl;
    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
}