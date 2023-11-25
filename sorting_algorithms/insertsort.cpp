/*
 author: Alessandro Ferrante
 * insertsort.cpp
*/

/*
 | The file introduces the InsertSort sorting algorithm with templates.
 | The algorithm iterates through the array, extending the sorted portion at each step.
 | At each iteration the current element is placed in the sorted portion of the array.
 | The algorithm compares the current item with previous items.
 | If the current element is smaller than the previous element, a swap occurs using the _swap function.

*/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#define N 20

using namespace std;

template <typename T> void _swap(T& a, T&b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void insertsort(T * data, int n) {
    for(int i = 1; i < n; i++){
        for (int j = i; j > 0; j--){
            if(data[j-1] > data[j])
                _swap(data[j-1], data[j]);
        }
    }
}

int main(int argc, char ** argv){
    srand(time(NULL));
    float data[N];
    for( int i = 0; i < N; i++) {
        data[i] = ((float)rand() / RAND_MAX * 50);
    }

    insertsort<float>(data, N);

    for(int i = 0; i < N ; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}