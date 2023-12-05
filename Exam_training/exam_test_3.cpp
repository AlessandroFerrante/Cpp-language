/*
 author: Alessandro Ferrante
 * exam_test_3.cpp
*/

#include <iostream>

using namespace std;

class Shape {
    public:
        Shape() { }
        virtual double get_area() = 0;

};

class Rectangle : public Shape{
    private: 
        double base;
        double height;
    public:
        Rectangle (double b, double h) : base(b), height(h){ };
        
        double get_area(){
            return base * height;
        }
};

class Circle : public Shape{
    private: 
        double radius;
    public:
        Circle (double r): radius(r) { };
        
        double get_area(){
            return 3.14*radius*radius;
        }
};

class Triangle : public Shape{
    private: 
        double base;
        double height;
    public:
        Triangle (double b, double h) : base(b), height(h) { };
        
        double get_area(){
            return (base * height)/2;
        }
};

template <typename T > class node{
    private :
        T data;
        node<T> * left;
        node<T> * right;

        node<T> * root;

        internal_insert(node<T> *& root, T & data){
            if(root == nullptr)
                root = new node(data);
            else{
                if(root->data->get_area() > data->get_area())
                    internal_insert(root->left, data);
                else
                    internal_insert(root->right, data);
            }
        }

        /*
        friend ostream& operator<<(ostream& out, node<T> *& n){
            out << endl;
            return out;
        }
        */

        void internal_visit_in_order(node<T> * root){
            if(root == nullptr)
                return;
            internal_visit_in_order(root->left);
            cout <<"The area is : " << root->data->get_area() << endl;
            internal_visit_in_order(root->right);
        }
        
    public:
        node() : root(nullptr) { };
        node(T d) : data(d), left(nullptr), right(nullptr) { };
        void insert(T data){
            internal_insert(root, data);
        }

        void visit_in_order(){
            internal_visit_in_order(root);
        }
};

int main(int argc, char ** argv){
    
    node<Rectangle*> rect;
    node<Circle*> circles;
    node<Triangle*> triangles;
    
    int c = 0;
    while(c != 3){
        cout << "Enter \n 0 - to create rectangles \n 1 - to create circles \n 2 - to create triangles \n 3 - to end" << endl;
        cout << " Case : ";
        cin >> c;
        int n;
        switch(c){
            case 0 :
                cout << "Enter the number of rectangles to create : ";
                cin >> n;
                for(int i = 0; i < n; i++){
                    int base, height;
                    cout << "insert base and height separated by space: ";
                    cin >> base >> height;
                    rect.insert(new Rectangle(base, height));
                }
                break;
            case 1 : 
                cout << "Enter the number of circles to create : ";
                cin >> n;
                for(int i = 0; i < n; i++){
                    int radius;
                    cout << "insert radius: ";
                    cin >> radius;
                    circles.insert(new Circle(radius));
                }
                break;
            case 2 :
                cout << "Enter the number of triangle to create : ";
                cin >> n;
                for(int i = 0; i < n; i++){
                    int base, height;
                    cout << "insert base and height separated by space: ";
                    cin >> base >> height;
                    triangles.insert(new Triangle(base, height));
                }
                break;
            case 3:
                cout << "Exiting the program" << endl;
                break;
            default : 
                cout << "Invalid choice" << endl;
        }
    }
    rect.visit_in_order();
    circles.visit_in_order();
    triangles.visit_in_order();
    

    return 0;
}