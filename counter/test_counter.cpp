/*
 author: Alessandro Ferrante
 * counter_example.cpp
*/

/*
 - This file import "counter.h" file and use the: GenericCounter, OneStepCounter, and NonNegativeCounter classes, for testing

 | The code provides a class hierarchy for counters with several restrictions. 
 ? GenericCounter is the parent class, which represents a generic counter
 ? the child class, OneStepCounter only allows increments and decrements of 1 at a time, 
 ? and NonNegativeCounter adds the restriction that the counter cannot go below zero.
 *
*/

#include <iostream>
#include "counter.h"

using namespace std;

int main(int argc, char ** argv){
    GenericCounter c;

    c.up(2);
    c +=3;
    cout << c << endl; // c = 5

    c.down(1);
    c -= 2;
    cout << c << endl; // c = 3

    c = 3;
    cout << c << endl;

    OneStepCounter c1;

    c1 += 1;
    cout << c1 << "->";
    c1 ++;
    cout << c1 << "->";

    c1 -= 1;
    cout << c1 << endl;

    NonNegativeCounter c2;

    c2 += 1;
    c2 += 1;
    cout << c2 << endl;

    c2 -= 1;
    cout << c2 << endl;
    c2 -= 1;
    cout << c2 << endl;
    c2 -= 1;
    cout << c2 << endl;

    return 0;
}