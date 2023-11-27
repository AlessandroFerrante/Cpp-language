/*
 author: Alessandro Ferrante
 * quicksort.cpp
*/

/*
 | The sorting algorithm employs a partition function to split 
 | and partially sort two subarrays: one on the left and one on the right.
 | Next, these subarrays are sorted using recursive calls to the quicksort function. 
 | In other words, the initial array is divided into smaller portions via partition, 
 | and each of these portions is then sorted separately by recursively applying the quicksort algorithm. 
 | This process continues until all portions are sorted, and the entire array is sorted.
 _ The division of the array is virtual as is the combination of the individual 'subarrays', 
 _ in fact the division and exchange operations take place on the array itself
 *
 | Partition function for the quicksort algorithm
 ? Parameters:
 - data: array of elements to sort
 - start: starting index of the portion of the array to be considered
 - end: final index of the portion of the array to be considered
 ? Returns:
 - Index of the pivot after the partition
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

template <typename T>  void _swap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b; 
    b = tmp;
}

template <typename T> int partition(T * data, int start, int end) {
    int pivot_index;

    // ? if the portion of the array has size 1, return the index
    if (start == end)
        return start;
    
    // ? determines pivot index
    if (data[start] > data[start + 1])
        pivot_index = start;
    else 
        pivot_index = start + 1; 
    
    // ? store pivot value
    T pivot = data[pivot_index];

    // ? index initialization for iterations
    int left = start;
    int right = end;

    // | main loop to partition
    while (left <= right) {
        // ? search for element on the left greater than the pivot, data[left] > pivot
        // ? if it is less than the pivot, move the index by increasing it
        while ((data[left] <= pivot) && (left <= right))
            left++;
        
        // ? search for element on the right smaller than the pivot, data[right] < pivot;
        // ? if it is greater than the pivot it moves the index by decreasing it
        while ((data[right] > pivot) && (left <= right))
            right--;

        // ? swap the elements in the left and right positions, if the indices have not reversed places
        if (left < right)
            _swap<T>(data[left], data[right]);            
    }
    // ? swap the pivot placing it in its correct position, to the right of the array (left-1).
    _swap<T>(data[pivot_index], data[left - 1]); 
    // ? return the pivot index after the partition
    return left - 1;
}

template <typename T> void quicksort(T * data, int start, int end) {
    if(start < end) {
        // ? to subdivide and 'sort' the array
        int split = partition<T>(data, start, end);
        for (int i = 0;  i < N; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        // ? recursive calls to sort the left and right subarrays
        quicksort<T>(data, start, split - 1);
        quicksort<T>(data, split + 1, end);
    } 
}

int main(int argc, char ** argv){
    srand(time(NULL));
    float data[] = {10, 8, 3, 15, 7, 9, 13, 4, 11, 6};
    for (int i = 0;  i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    /*
    for (int i = 0; i < N; i++) {
        data[i] = ((float)rand() / RAND_MAX * 50);
            cout << i << " " << data[i] <<endl;
    }
    */
    cout << "partitions" << endl;   
    quicksort<float>(data, 0, N -1);
    cout << endl;
    for (int i = 0;  i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
