/*
 author Alessandro Ferrante
 * inheritance.cpp
*/

/*
 ? The example introduces the concept of inheritance, 
 ? which allows you to create new classes based on existing classes. 
 ? A new Square class is defined which inherits the methods and everything 
 ? that is part of the access modify public from the Rectangle class.

 ? Inheritance is a fundamental concept in object-oriented programming (OOP) 
 ? that allows you to create new classes based on existing classes. 
 ? In OOP, a class can be defined as a template or a "factory" 
 ? for creating objects of a certain type. Inheritance allows you to create 
 ? a new class that inherits all the properties and methods of the base class, 
 ? while adding new properties and methods.
 
 ? The base class is also known as the 'parent class' or 'superclass', 
 ? while the new class created through inheritance is known 
 ? as the 'child class' or subclass. 
 ? The 'child class' inherits all the fields and methods of 
 ? the parent class and can also add new fields and methods or 
 ? override existing methods.

 ? Inheritance is useful because it helps you avoid code duplication 
 ? and create class hierarchies to organize your code in a more logical 
 ? and maintainable way.
*/

#include<iostream>

using namespace std;

// ? parent class or superclass of the square class
class Rectangle {
    private:
        // attributes
        float b, h;
    public: 
        // constructor
        Rectangle(float _b, float _h);
        // destructor
        ~Rectangle();

        // methods
        float compute_area();
        float compute_perimeter();
        
        float get_b() { return b; };
        float get_h() { return h; };
        void get_dimension(float & _b, float & _h){
            _b = b;
            _h = h;
        }

        float set_b(float _b) { b = _b; };
        float set_h(float _h ){ h = _h; };
        void set_dimension(float _b, float _h){
            b = _b;
            h = _h;
        }

        void show();
};

// ? child class that inherits from the rectangle class
class Square : public Rectangle{
    public:
        // ? constructor 
        Square(float side) ; //: Rectangle (side, side);

        // ? method
        void set_side(float side);
};

// ? Square constructor
// ? :Rectangle(side, side) is the invocation of the parent-class constructor
Square::Square(float side) : Rectangle(side, side){
    //...Square-specific (it is not needed in this case) 
}

// ? Square class method
void Square::set_side(float side){
    set_dimension(side, side);// ? use inherited method
}

// Rect constructor 
Rectangle:: Rectangle(float _b, float _h){
    cout << "Rect constructor " << endl;
    this->b = _b;
    this->h = _h;
}

//Rect destructor
Rectangle::~Rectangle(){
    cout << "Rect destructor " << endl;
}

// Rectangle class method
float Rectangle::compute_area(){
    return b * h;
}

// Rectangle class method
float Rectangle::compute_perimeter(){
    return (b + h) * 2;
}

// function to display the size
void show_dimension(Rectangle * r){
    cout << "The size is " << r->get_b() << " x " << r->get_h() << endl;
}

// Rectangle class method
void Rectangle::show(){
    show_dimension(this);
}

int main (int argc,  char ** argv){
    /*
    //* Initialize the attributes
    Rectangle my_rect_1(3, 10);
    Rectangle my_rect_2(20.5, 44);

    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << endl;

    //* Create dynamic object using pointer
    Rectangle * my_rect_3;
    my_rect_3 = new Rectangle(30, 40);

    cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << endl;
    cout << "Area of rect 3 = " << my_rect_3->compute_area() << endl;

    //* metodi diversi di visualizzazione delle dimensioni
    cout << "The size of rect 3 is " << my_rect_3->get_b() << " x " << my_rect_3->get_h() << endl;
    float base, height;
    my_rect_3->get_dimension(base,  height);
    cout << "The size of rect 3 is " << base << " x " << height << endl;

    //* deallocation
    delete my_rect_3;

    my_rect_1.set_dimension(3, 4);
    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    */
    // ? Square
    Square q(30);
    cout << "Area of square is " << q.compute_area() << endl;
    cout << "Perimeter of square is " << q.compute_perimeter() << endl;
}