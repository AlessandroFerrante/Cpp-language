/*
 author: Alessandro Ferrante
 * counter.h
*/

/*
 - This code defines three C++ classes: GenericCounter, OneStepCounter, and NonNegativeCounter, 
 - with the implementations of the methods and of the operators.

 | The code provides a class hierarchy for counters with several restrictions. 
 ? GenericCounter is the parent class, which represents a generic counter
 ? the child class, OneStepCounter only allows increments and decrements of 1 at a time, 
 ? and NonNegativeCounter adds the restriction that the counter cannot go below zero.
 *
*/

#include <iostream>

using namespace std;

// ? parent class, allows the increase in a generic way without restrictions
class GenericCounter {
    private: 
        int value;
    public: 
        // default constructor
        GenericCounter() : value(0) { };

        // methods to increments value
        virtual void up(int delta) { value += delta; };
        virtual void down(int delta) { value -= delta; };
        // method get
        int get_value() { return value; };
        // method set
        void set_value(int value) { this->value = value; };

        // Compound increment operator.
        // Increment the counter value by a specified amount (delta)
        // and returns a reference to itself to support encoding. 
        GenericCounter & operator+=(int delta) {
            up(delta);
            return *this;
        }
        
        // Compound decrement operator.
        // Decreases the counter value by a specified amount (delta)
        // and returns a reference to itself to support encoding.
        GenericCounter & operator-=(int delta) {
            down(delta);
            return *this;
        }

        // Assignment operator.
        // Assign the counter a new specified value (value)
        // and returns a reference to itself to support encoding.
        GenericCounter & operator=(int value) {
            this->value = value; 
            return *this;
        }
};

class CounterException { };

// ? child class, only allows increments and decrements of 1 at a time.
class OneStepCounter : public GenericCounter {
    public:
        void up() { up(1); };
        void down() { down(1); };
        
        void up(int delta) {
            if(delta != 1)
                throw CounterException();
            GenericCounter::up(delta);
        }
        void down(int delta) { 
            if(delta != 1)
                throw CounterException();
            GenericCounter::down(delta);
        }
        
        // ? Increments the counter by 1 and returns a reference to itself, allows expressions like counter++++;        
        GenericCounter & operator++(int) {
            up(1);
            return *this;
        }
        // ? Decrease the counter by 1 and returns a reference to itself, allows expressions like counter----;        
        GenericCounter & operator--(int) {
            down(1);
            return *this;
        }
        
};

// ? child class, adds the restriction that the counter cannot go below zero.
class NonNegativeCounter : public OneStepCounter {
    public: 
        void down(int delta) {
            if(get_value() - delta < 0 )
                throw CounterException();
            OneStepCounter::down(delta);
        }
};

// ? output operator on stream.
// ? prints the value of a GenericCounter object to an output stream.
ostream & operator<<(ostream & output, GenericCounter & c){
    output << c.get_value();
    return output;
}