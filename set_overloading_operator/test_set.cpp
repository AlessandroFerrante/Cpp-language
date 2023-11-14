/*
 author Alessandro Ferrante
 * test_set.cpp
*/
/* 
 | The file contains only the instantiation of the SetDuplicates and Set objects.
 *
 ? The example implements the redemption of the set, union and difference operators,
 ? the addition and subtraction operators and the element access operator via index.
 * 
*/

#include "set.h"
#include "set.cpp"

using namespace std;

int main(int argc, char ** argv){
    // Initialization with default constructor
    SetDuplicates s1;

    // ? add elements to the set, with redefined operators (overloading).

    s1 += 10;
    s1 += 20;
    s1 -= 10;
    cout << "S1: " << s1 << endl;

    Set s;

	s += 11;
    s.add(20);
    s.add(2);
    s.add(50);
    s.add(30);
    s.add(50);
	

    cout << "S : " << s << endl;

    Set s2;
	s2.add(10);
    s2.add(15);
    s2.add(30);
	cout << "S2: " << s2 << endl;
	
    // ? Using the UNION operator
	//Set s3(s);
	//s3 + s2;
	// ! instantiate the object without any assignment, because a constructor has not been defined for this purpose.
	Set s3; 
	s3 = s + s2;// ? the '=' operator, by default, allows the assignment/copy of another object.
	cout << "S3: " << s3 << endl;

    /* use of the various redefined operators
    s -= 50;
	s -= 1;
	
	cout << "S: " << s << endl;

	Set s1 = s;
	
	cout << "S1: " << s1 << endl;
	
	s1 -= 20;
	cout << "S: " << s << endl;
	cout << "S1: " << s1 << endl;
	
	Set s2;
	s2 += 10;
	s2 += 15;
	s2 += 30;
	cout << "S2: " << s2 << endl;
	
	SetDuplicates s3 = s1 + s2;
	cout << "S3: " << s3 << endl;
	
	SetDuplicates s4 = s1 - s2;
	cout << "S4: " << s4 << endl;
	
	for (int i = 0; i < s.length();i++) {
		cout << s[i] << endl;
	}
	*/	
	return 0;
}