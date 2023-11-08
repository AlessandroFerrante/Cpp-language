/*
author Alesandro Ferrante 
* dynamic_object_example.cpp
*/

/*
 ? An object is an `instance` of a class. 
 ? A class is a data type that can contain attributes (variables) and methods (functions).
 ? An object is created by the class and has access to its attributes and methods.
 ? The concept of class, allows you to create objects with attributes and methods.

 ? The example shows how to define a class in C++ and create class objects. 
 
 | Dynamic creation of objects.
 | The objects in this example are created dynamically, using the new operator,
 | this returns a pointer to the object;
 
 ? Two objects of the Rectangle class are instantiated 
 ? and their methods are invoked to calculate the perimeter and area.
*/

#include<iostream>

using namespace std;

/*
 ? In C++, there are three access specifiers: 
 ? public - members are accessible from outside the class. 
 ? private - members cannot be accessed (or viewed) from outside the class.
 ? protected - members cannot be accessed from outside the class, 
 ? however, they can be accessed in inherited classes.
*/
// ? Rectangle class with attributes and methods
class Rectangle {
    private: 
        //attributes
        float b, h;
    public: 
        //methods
        void init(float _b, float _h);
        float compute_area();
        float compute_perimeter();
};

//? Initializes the attributes
void Rectangle::init(float _b, float _h){
    b = _b;
    h = _h;
}

//? Compute and return the area of the rectangle
float Rectangle::compute_area(){
    return b * h;
}

//? Compute and return the perimeter of the rectangle
float Rectangle::compute_perimeter(){
    return (b + h)*2;
}

int main(int argc, char ** argv){
    // ? Defines two pointer  variables to store pointers to Rectangle objects
    Rectangle * my_rect_1, * my_rect_2;

    // ? Create new Rectangle objects and assign their addresses to the pointers
    my_rect_1 = new Rectangle;
    my_rect_2 = new Rectangle;

    // Initialize the objects rectangle, 
    // ? use -> to access object allocation

    my_rect_1->init(3, 20);
    my_rect_2->init(20.5, 44);

    cout  << "Area of rect 1 = " << my_rect_1->compute_area() << endl;
    cout << "Perimeter of rect 1 = " << my_rect_1->compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2->compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2->compute_perimeter() << endl;

    // ? Deallocate memory by deleting the dynamically allocated objects
    delete my_rect_1;
    delete my_rect_2;
}