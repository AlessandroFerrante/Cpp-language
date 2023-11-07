/*
* object_example.cpp
*/

/*
 -> Rectangle basic with the struct
 ? The example presents an "object" in C++, 
 ? which is an instance of a user-defined  -*//* -> struct.
*/-*/
#include<iostream>

using namespace std;

//-> Rectangle basic
typedef struct{
    float b, h; // ? instances of the struct
} Rectangle;

void init_rectangle(Rectangle * rect, float _b, float _h){
    rect->b = _b;
    rect->h = _h; 
}

float compute_area(Rectangle * rect){
    return rect->b * rect->h;
}

float compute perimeter(Rectangle * rect){
    return (rect->b + rect->h) * 2;
}

int main(int argc, char ** argv){
    Rectangle my_rect;
    init_rectangle(&my_rect, 10.5, 22.5);
    cout << "Permeter = " << compute_perimeter(&my_rect) << endl;
    cout << "Area = " << compute_area(&my_rect) << endl;
}