/*
 author : Alessandro Ferrante
 * exam_test_1.cpp
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{
    private:
        // attributes 
       string name;
       string race;
       int age;
    public:
        // parameters constructor
        Animal(string n, string r, int a) : name(n), race(r), age(a) { }
        
        string get_name(){return name; }
        string get_race(){return race; }
        int get_age(){return age; }

        friend ostream& operator<<(ostream& out, const Animal * a){
            out << "Name :" << a->name << endl;
            out << "Race :" << a->race << endl;
            out << "Age :" << a->age << endl;
            return out;
        }

        virtual string animal_call() = 0;
        
};

class Cat : public Animal {
    public:
        Cat(string name, string race, int age) : Animal(name, race, age) { }
        
        string animal_call(){
            return "Miao!" ;
        }
};

class Dog : public Animal {
    public:
     Dog(string name, string race, int age) : Animal(name, race, age) { }

     string animal_call(){
        return "Bau bau!";
     }
};

template <typename T> class node{
    private:
        T animal;
        int size;
        node* left = nullptr;
        node* right = nullptr;


        node* root;

        void internal_insert(node<T> *& root, const T a) {
            if(root == nullptr){
                root = new node(a);
                return;
            }
            if(root->animal->get_name() < a->get_name())
                internal_insert(root->right, a);
            else
                internal_insert(root->left, a);
        }   

        Animal* internal_find(node<T> *& root, string name){
            if(root == nullptr)
                return nullptr;
            if(name == root->animal->get_name())
                return root->animal;
            if(name > root->animal->get_name())
                return internal_find(root->right, name);
            else
                return internal_find(root->left, name);
        }

        void internal_visit_in_order(node<T> *& root){
            if(root == nullptr)
                return;
            internal_visit_in_order(root->left);
            Animal * a = root->animal;
            cout << a << endl;
            internal_visit_in_order(root->right);
        }

    public:
        node(int n) : root(nullptr), size(n) { }
        node(const T& a) : animal(a), left(nullptr), right(nullptr) { }
        ~node() { }

        void insert(T a) {
            internal_insert(root, a);
        }

        Animal* find(string name) {
            return internal_find(root, name);
        }

        void visit_in_order(){
            internal_visit_in_order(root);
        }

};



int main (int argc, char ** argv){
    node<Animal*> mybst(10);

    Animal * a = new Dog("Fido", "Labrador", 3);
    mybst.insert(a);
    mybst.insert(new Cat("Luna", "Siamese", 2));
    mybst.insert(new Dog("Rex", "Pastore Tedesco", 5));
    mybst.insert(new Cat("Leo", "Persiano", 4));
    mybst.insert(new Dog("Milo", "Beagle", 1));
    mybst.insert(new Cat("Nala", "Maine Coon", 3));
    cout << "Enter the name of an animal : "; 
    string name;
    cin >> name;
    a = mybst.find(name);
    if(a != nullptr){
        cout << a;
        cout << "The verse of " << a->get_name() << " is : " << a->animal_call() << endl;
    }
    else 
        cout << "No animals with this name found in the tree." << endl;

    mybst.visit_in_order();
    
    return 0;
}