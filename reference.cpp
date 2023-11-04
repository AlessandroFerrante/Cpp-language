/*
 *reference.cpp
*/
#include <iostream>

/*
 ? The using directive allows us to access all members of the namespace.
 ? Used to write using std namespace, to give access to functions like cin, cout, etc.
*/
using namespace std;

void calc_max_min(int *a, int n, int *max, int *min){
    *max= a[0];
    *min= a[0];
    for(int i=1; i<n; i++){
        if(a[i] > *max)
            *max= a[i];
        if(a[i] < *min)
            *min= a[i];
    }   
}

int main(int argc, char **argv){
    cout << "Insert array size: ";
    int n;
    int * array = new int[n];
    for (int i=0; i<n; i++){
        cout << "Insert  element " << i <<": ";
        cin>> array[i];
    }

    int MAX, MIN;
    calc_max_min(array, n, MAX, MIN);
    cout << "Max is " << MAX << endl;
    cout << "Min is " << MIN << endl;
    delete [] array;
    return 0;
}