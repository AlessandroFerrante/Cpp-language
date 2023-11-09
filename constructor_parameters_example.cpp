/*
 author Alessandro Ferrante
 * constructor_parameters_example.cpp
*/

/*
 ? The constructor acts when the object is created,
 ? performing specific functions such as attribute initialization;
 ? the destructor acts when the object is deleted,
 ? performing specific functions such as freeing a dynamic allocation.
*/

#include <iostream>

using namespace std;
/*
 ? Rectangle class with attributes and methods, 
*/
class Rectangle {
    private:
        // attributes
        float b, h;
    public: 
        // ? constructor
        Rectangle(float _b, float _h);

        // ? destructor
        ~Rectangle();

        // methods
        float compute_area();
        float compute_perimeter();
};

/*
 ? default constructor with paramaters, 
 ? initializes the attributes
 */
Rectangle::Rectangle(float _b, float _h){
    cout << "Rect costructor " << endl;
    b = _b;
    h = _h;
}

/*
 ? default destructor, 
 ? in this case it does not perform particular functions
*/
Rectangle::~Rectangle(){
    cout << "Rect destructor " << endl;
}

// Compute and return the area of the rectangle
float Rectangle::compute_area(){
    return b * h;
}

// Compute and return the perimeter of the rectangle
float Rectangle::compute_perimeter(){
    return (b + h) * 2;
}

int main(int argc, char ** argv){
    // Initialize the attributes
    Rectangle my_rect_1(3, 10);
	Rectangle my_rect_2(20.5, 44);

	std::cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << std::endl;
	std::cout << "Area of rect 1 = " << my_rect_1.compute_area() << std::endl;
	std::cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << std::endl;
	std::cout << "Area of rect 2 = " << my_rect_2.compute_area() << std::endl;

	Rectangle * my_rect_3;
	my_rect_3 = new Rectangle(30,40); //dynamic allocation
    
	std::cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << std::endl;
	std::cout << "Area of rect 3 = " << my_rect_3->compute_area() << std::endl;
	delete my_rect_3; //Deallocate or free memory ,dynamically allocated
}