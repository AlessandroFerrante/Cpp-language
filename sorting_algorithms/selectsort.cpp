/*
 author: Alessandro Ferrante
 * selectsort.cpp
*/

/*
 | The file introduces the Select Sort sorting algorithm with templates
 | The algorithm works iteratively by selecting the smallest or largest, 
 | depending on the desired order element from an unsorted portion 
 | of the array and placing it in the sorted part. This process repeats until 
 | the entire array is sorted. In each iteration, the algorithm finds the smallest 
 | element in the unsorted part and exchanges it with the next element in the sorted part.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 20

using namespace std;

template <typename T> void _swap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void selectsort(T * data, int n) {
    for(int i = 0; i < n - 1; i++) {
        int least_index = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[least_index])
                least_index = j;
        }
        _swap<T>(data[i], data[least_index]);
    }
}

int main(int argc, char ** argv){
    srand(time(NULL));
    float data[N];
    for (int i = 0; i < N; i++){
        data[i] = ((float)rand() / RAND_MAX * 50);
    }

    selectsort<float>(data, N);

    for(int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }

    return 0;
}