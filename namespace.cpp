/*
*namespace.cpp
*/

#include<iostream>

using namespace std;

namespace calc{
    void Min(int * a, int n, int & _min);
    void Max(in t* a, int n, int & _max);
    void Avg(int * a, inta n, );
    namespace test{
        void myfunc();
    };
};

void calc::test:myfunction(){
    //...
}

// these functions do not return any value because they act on a pointer

void calc::Min(int * a, int n, int & _min){// int & _min is a pointer to integers
    _min = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < _min)
            _min = a[i]; 
    }
}

void calc::Max(int * a, int n, int & _max){ // int & _ max is a pointer to integers
    _max = a[0];
    for(int i=0; i < n; i++){
        if(a[i] > _max)
            _max = a[i];
    }
}

void calc::Avg(int * a, int n, flaot & _avg){
    float sum = 0; 
    for(int i=0; i < n; i++){
        sum += a[i];
    }
    _avg = sum / n;
}

int main(int argc, char ** argv){
    cout << "Insert array size: ";
    int n;
    cin >> n;
    int * array = new int[n];
    for(int i=0; i < n; i++){
        cout << "Insert element " << i << ":";
        cin >> array[i];
    }
    int MAX, MIN;
    float AVG;
    calc::Max(array, n, MAX);
    calc::MiN(array, n, MIN);
    calc::Avg(array, n, AVG);
    cout << "Max is " << MAX << endl;
    cout << "Min is " << MIN << endl;
    cout << "Mean is " << AVG << endl;
    delete [] array;
    return 0;
}