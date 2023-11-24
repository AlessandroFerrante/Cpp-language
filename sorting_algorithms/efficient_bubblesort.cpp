/*
 author: Alessandro Ferrante
 * efficient_bubblesort.cpp
*/

/*
 | The file introduces an efficient Bubble Sort sorting algorithm with templates.
 | The bubble sorting algorithm works by comparing adjacent elements 
 | and swapping them if they are out of order. 
 _ This process is repeated until there are exchanges equal to the length of the array 
 _ The algorithm is optimized by replacing the outermost for loop 
 _ with a while loop and a boolean variable,
 - adding the while loop allows you to stop executing the main loop as soon 
 - as the array is completely sorted, thus reducing the total number of iterations.
 ? Essentially, it can be more efficient in specific cases where the array 
 ? is already sorted or partially sorted, saving unnecessary iterations.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 20

using namespace std;

template <typename T> void _swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> void bubblesort(T * data, int n){
    bool done = false;
    while(!done){
        done = true;
        for(int j = 0; j < n - 1 ; j++){
            if(data[j] > data[j+1]){
                _swap<T>(data[j], data[j+1]);
                done = false;
            }
        }
    }
}

int main(int argc, char ** argv){
    srand(time(NULL));
    float data[N];
    for(int i = 0; i < N; i++){ 
        data[i] = ((float)rand() / RAND_MAX * 50);
    }
    
    bubblesort<float>(data, N);

    for(int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}