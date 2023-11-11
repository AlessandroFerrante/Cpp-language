/*
 author ALessandro Ferrante
 * lshift_operator.cpp
*/

/*
 ? To print the data of an object modify cout by passing it 
 ? to a function by reference, also pass the object

 ? Returning to the print with this code we can use the following 
 ? code to pass our object to operator, we pass it by reference so 
 ? as not to create a copy which is in fact useless, subsequently 
 ? the get and set methods will be called which will use
 ? the object reference r to get the parameters referring to that object;

 ? To access the private data of the class you need
 ? to use 'friend' and define it in the function inside the class.
 ? --> friend ostream& operator << (ostream& output_stream, Rectangle &r);
*/
#include <iostream>

using namespace std;

class Rectangle {
    private:
        // attributes
        float b, h;
    public: 
        // constructor
        Rectangle (float _b, float _h){
            b = _b;
            h = _h;
        }
            // copy constructor
            Rectangle (const Rectangle & r) : Rectangle(r.b, r.h){}
            // default constructor
            Rectangle() : Rectangle(0, 0){}
        // destrcutor
        ~Rectangle(){}

        // methods

        float compute_area(){
            return b * h;
        }
        float compute_perimeter(){
            return (b + h)*2;
        }

        float get_b() { return b; };
        float get_h() { return h; };
        void get_dimension(float & _b, float & _h) {
            _b = b;
            _h = h;
        };

        void set_b(float _b) { b = _b; };
        void set_h(float _h) { h = _h; };
        void set_dimension(float _b, float _h) {
            b = _b;
            h = _h;
        };
        // ? operator << (cout, Rectangle r) << endl; -->cout
        // ? Applies to all ostream objects (output stream)
        // ? 'type reference' operator 'symbol' ('parameters passed by reference')
        friend ostream& operator << (ostream& output_stream, Rectangle &r);

};

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

// ? operator << (cout, Rectangle r) ---> cout
ostream& operator << (ostream & output_stream, Rectangle &r){
    output_stream << r.b << " x " << r.h;
    return output_stream;
}

int main(int argc , char **argv){
    // Initialize rect1 and rect2
    Rectangle my_rect_1(3, 10);
	Rectangle my_rect_2(20.5, 44);

    cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
    cout << "Area of rect 1 = " << my_rect_1.compute_area() << endl;
    cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << endl;
    cout << "Area of rect 2 = " << my_rect_2.compute_area() << endl;

    // ? Example using the rereferenced shift operator
    ((cout << "\nPerimeter of rect 1 = ") << my_rect_1.compute_perimeter()) << endl;
	(cout << my_rect_1.compute_perimeter()) << endl;
	cout << endl;
	
	cout << "Perimeter of rect 1 = ";
	cout << my_rect_1.compute_perimeter();
	cout << endl;
	
    // ? Using the rereferenced shift operator with the variables
	int i = 3;
	int a = i << 2 << 3 << 4;
	a = ((i << 2) << 3) << 4;
	int temp = i << 2;
	temp = temp << 3;
	a = temp << 4;
    cout << "Value of a : " << a << endl;

    // ? Using the rereferenced shift operator with an object
    cout << r2 << endl;

    // copy the values ​​to the new object
    Rectangle r2 = my_rect_1;
    cout << "Area of r2 = " << r2.compute_area() << endl;

    // initialize array of objects to default values
    Rectangle * r_array = new Rectangle[3];
    // deallocate array
    delete []r_array;
}