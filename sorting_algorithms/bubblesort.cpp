/*
 author: Alessandro Ferrante
 * bubblesort.cpp
*/

/*
 | The file introduces the Bubble Sort sorting algorithm with templates
 | The bubble sorting algorithm works by comparing adjacent elements 
 | and swapping them if they are out of order. 
 | This process is repeated until there are exchanges equal to the length of the array 
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

#define N 20

using namespace std;

template <typename T> void _swap(T& a, T& b){
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>  void bubblesort(T * data, int n){
    for (int i = 0;  i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(data[j] > data[j+1])
                // T temp = data[j];
                // data[j] = data[j+1];
                // data[j+1] = temp;
                _swap<T>(data[j], data[j+1]);
        }
    }
}

int main(int argc, char ** argv ){

    float data[N];
    for(int i = 0; i< N; i++){
        data[i] = ((float)rand()/ RAND_MAX * 50);
    }

    bubblesort<float>(data, N);
    for(int i = 0; i < N; i++){
        cout << i << " " << data[i] << endl;
    }
    return 0;
}