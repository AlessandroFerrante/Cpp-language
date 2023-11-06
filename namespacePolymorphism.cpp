/*
 * namespacePolymorphism.cpp
 */


 #include <iostream>
 
 using namespace std;
 
/*
 ? Namespace polymorphism means that,
 ? In namespaces with different type variables (int and float) 
 ? it is possible to use the same function name;
 ! This is more commonly called "ad hoc polymorphism" or "inclusion polymorphism", 
 ! because it is nothing more than an "overloading" of functions with namespace.
*/

/*
 ? in this example the two max functions use different types of variables,
 ? the call to the functions is "managed" automatically
*/
namespace calc {
 	void Max(int * a, int n, int & _max);
 	void Max(float * a, int n, float & _max);
 };
 
// ?  Max with integers
void calc::Max(int * a, int n, int & _max)
{
	cout << "Computing Max of ints" << endl;
 	_max = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 	}
}
 
// ?  Max with floating point numbers
void calc::Max(float * a, int n, float & _max)
{
	cout << "Computing Max of floats" << endl;
 	_max = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 	}
}
 
int main(int argc, char * argv[])
{
	cout << "Insert array size:";
	int n;
	cin >> n;
	float * array = new float[n];
	for (int i = 0; i < n;i++) {
		cout << "Insert element "<< i << ":";
		cin >> array[i];
	}
	float MAX;
	calc::Max(array, n, MAX); // ? the call to the functions is "managed" automatically, int or float
	cout << "Max is " << MAX << endl;
	delete [] array;
	return 0;
}
