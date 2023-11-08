/*
* object_example.cpp
*/

/*
 ? An object is an `instance` of a class. 
 ? A class is a data type that can contain attributes (variables) and methods (functions).
 ? An object is created by the class and has access to its attributes and methods.
 ? The concept of class, allows you to create objects with attributes and methods.


 ? The example shows how to define a class in C++ and create class objects. 
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
        // attibutes
        float b, h;
    public:
        //methods
        void init(float _b, float _h);
        float compute_area();
        float compute_perimeter();
};

/*
 ? (gets/receives and sets) 
 ? Sets and initializes (with the values passed as arguments) 
 ? the attributes of the object of the rectangle class
*/
void Rectangle::init(float _b, float _h){
    b= _b;
    h = _h;
}

//? Compute and return the area of the rectangle
float Rectangle::compute_area(){
    return b * h;
}

//? Compute and return the perimeter of the rectangle
float Rectangle::compute_perimeter(){
    return 2 *(b + h);
}

int main(int argc, char ** argv){
    Rectangle my_rect1, my_rect2;
    // Initialize the attributes of the first rectangle
    my_rect1.init(3, 10);
    // Initialize the attributes of the second rectangle
    my_rect2.init(20.5, 44);
    
    //Calculate and print the perimeter anda area of the first and second rectangle
    cout << "Perimeter of rect 1 = " << my_rect1.compute_perimeter() << endl;
    cout  << "Area of rect 1 = " <<  my_rect1.compute_area() << endl;
    cout << "Permeter of rect 2 = " << my_rect2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect2.compute_area() << endl; 
}