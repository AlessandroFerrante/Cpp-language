/*
 author Alessandro Ferrante
 * constructor_copy.cpp
*/

/*
 ? The example illustrates using the copy constructor when you want to create
 ? a copy of one object in another and the default constructor when creating objects 
 ?without specifying initial values. 

 ? The default constructor is a parameterless constructor useful 
 ? when passing no parameters, uses the constructor with values ​​(0, 0)
 
 ? The copy constructor creates a new object by copying the attributes 
 ? of an existing object (r in this case).
*/
#include <iostream>

using namespace std;

class Rectangle{
    private: 
        // attributes
        float b, h;
    public: 
        // constructor
        Rectangle(float _b, float _h);
            // copy constructor
            Rectangle(const Rectangle & r);
            // default constructor
            Rectangle();
        // destructor
        ~Rectangle(){
            cout << "Rect destructor" << endl;
        }

        //methods

        float get_b(){ return b; };
        float get_h(){ return h; };
        void get_dimension(float & _b, float & _h){
            _b = b;
            _h = h;
        };

        float set_b(float _b){ b = _b; };
        float set_h(float _h){ h = _h; };
        void set_dimension(float _b, float _h){
            b = _b;
            h = _h;
        };

        float compute_area(){
            return b * h;
        };
        
        float compute_perimeter(){
            return (b + h) * 2;
        };
};

// | Rectangle constructor
// ? Initialize member variables b and h with the provided values
Rectangle::Rectangle(float _b, float _h) : b(_b), h(_h){
    cout << "Rect constructor" << endl;
}

// | Rectangle copy constructor            
// ? : Rectangle(r.b, r.h) -> Invoke the main constructor to copy
Rectangle::Rectangle(const Rectangle & r) : Rectangle(r.b, r.h){  
        cout << "Copy constructor " << endl;
}

// | Rectangle default constuctor
// ? : Rectangle(0, 0) -> Invoke the main constructor with default values
Rectangle::Rectangle() : Rectangle(0, 0){
    cout << "Default constructor " << endl;
}

// child class, inherits from the rectangle class
class Square : public Rectangle{
    public: 
        Square(float side) : Rectangle(side, side){
            //...Square specific
        }

        void set_side(float side){
            set_dimension(side, side);
        }
};

int main(int argc, char ** argv){

    // Initialize the attributes of rect1 and rect2
    Rectangle my_rect_1(3, 10);
    Rectangle my_rect_2(22.5, 44);

    cout << "\nPerimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << "\n" << endl;

    // ? invokes the copy constructor, to copy the values ​​to the new object
    Rectangle r2 = my_rect_1;
    cout << "Area of r2 = " << r2.compute_area() << endl;

    // ? invokes the default constructor, to initiliaze the objects
    cout << "\nArray of 3 Rectangle objects" << endl;
    Rectangle * r_array = new Rectangle[3];
    delete []r_array;
    cout << " " << endl;
}

